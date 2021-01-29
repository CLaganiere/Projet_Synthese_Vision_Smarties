#include "Uniformisation.h"

Uniformisation::Uniformisation(int const imageWidth, int const imageHeight)
	:mWidthImage{ imageWidth },
	mHeightImage{ imageHeight }
{
	image = img_t(mWidthImage, mHeightImage, img_t::Format_ARGB32);
}

std::vector<img_t*> Uniformisation::perform(std::vector<img_t*> const & vectImage)
{
	if (vectImage.empty()) {
		throw std::out_of_range("Vecteur d'image recu vide...");
	}

	for(auto & vImage : vectImage){

		int * curPix{ reinterpret_cast<int*>(vImage->bits()) };
		int * endPix{ curPix + image.width() * image.height() };
		int * lightPix{ reinterpret_cast<int*>(mLightCard->bits()) };
		int * modifPix{ reinterpret_cast<int*>(image.bits()) };
		int sizeVect = vectImage.size();

		while (curPix < endPix) {

			int r{ (static_cast<unsigned char>((*lightPix & 0x00'FF'00'00) >> 16) +
					static_cast<unsigned char>((*curPix & 0x00'FF'00'00) >> 16)) / 2 };

			int g{ (static_cast<unsigned char>((*lightPix & 0x00'00'FF'00) >> 8) + 
					static_cast<unsigned char>((*curPix & 0x00'00'FF'00) >> 8)) / 2 };

			int b{ (static_cast<unsigned char>((*lightPix & 0x00'00'00'FF) >> 0) + 
					static_cast<unsigned char>((*curPix & 0x00'00'00'FF) >> 0)) / 2 };

			*modifPix = (r << 16) |
				(g << 8) |
				(b << 0) |
				0xFF'00'00'00;

			++modifPix;
			++lightPix;
			++curPix;
		}

		*vImage = image;
	}

	return vectImage;
}


std::vector<img_t*> Uniformisation::performOneOfMany(std::vector<img_t*> const & vectImage)
{
	if (vectImage.empty()) {
		throw std::out_of_range("Vecteur d'image recu vide...");
	}


	int * curPix{ reinterpret_cast<int*>(vectImage[0]->bits()) };
	int * endPix{ curPix + image.width() * image.height() };
	int * modifPix{ reinterpret_cast<int*>(image.bits()) };
	int manipImg{};
	int sizeVect = vectImage.size();

	while (curPix < endPix) {

		long long r{};
		long long g{};
		long long b{};

		for (int i{ 1 }; i < sizeVect; ++i) {
			int * manipPix{ reinterpret_cast<int*>(vectImage[i]->bits()) };
			manipPix += manipImg;
			r += static_cast<unsigned char>((*manipPix & 0x00'FF'00'00) >> 16);
			g += static_cast<unsigned char>((*manipPix & 0x00'00'FF'00) >> 8);
			b += static_cast<unsigned char>((*manipPix & 0x00'00'00'FF) >> 0);
		}

		// Valeurs Pixels des Cartes d'éclairages
		r /= sizeVect;
		g /= sizeVect;
		b /= sizeVect;

		r = (r + static_cast<unsigned char>((*curPix & 0x00'FF'00'00) >> 16)) / 2;
		g = (g + static_cast<unsigned char>((*curPix & 0x00'00'FF'00) >> 8)) / 2;
		b = (b + static_cast<unsigned char>((*curPix & 0x00'00'00'FF) >> 0)) / 2;

		*modifPix = ( r << 16) |
					( g << 8 ) |
					( b << 0 ) |
					0xFF'00'00'00;

		++modifPix;
		++manipImg;
		++curPix;
	}

	*vectImage[0] = image;
	return vectImage;
}

void Uniformisation::setLightCard(img_t * lightcard)
{
	mLightCard = lightcard;
}
