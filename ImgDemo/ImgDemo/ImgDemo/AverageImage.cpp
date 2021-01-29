#include "AverageImage.h"

AverageImage::AverageImage(int const imageWidth, int const imageHeight)
	:mWidthImage{ imageWidth },
	mHeightImage{ imageHeight }
{
	image = img_t(mWidthImage, mHeightImage, img_t::Format_ARGB32);
}

AverageImage::~AverageImage()
{
	for (auto & image : mVectResult) {
		delete image;
	}
	mVectResult.clear();
}

std::vector<img_t*> AverageImage::perform(std::vector<img_t*> const & vectImage)
{
	if (vectImage.empty()) {
		throw std::out_of_range("Le vecteur d'image recu est vide...");
	}

	int * curPix{ reinterpret_cast<int*>(image.bits()) };
	int * endPix{ curPix + image.width() * image.height() };
	int manipImg{};
	int sizeVect = vectImage.size();

	while (curPix < endPix) {

		long long r{};
		long long g{};
		long long b{};

		for (auto & bckImg : vectImage) {
			int * manipPix{ reinterpret_cast<int*>(bckImg->bits()) };
			manipPix += manipImg;
			r += static_cast<unsigned char>((*manipPix & 0x00'FF'00'00) >> 16);
			g += static_cast<unsigned char>((*manipPix & 0x00'00'FF'00) >> 8);
			b += static_cast<unsigned char>((*manipPix & 0x00'00'00'FF) >> 0);
		}

		//Moyenne des RBG des images
		*curPix = ((r / sizeVect) << 16) |
			((g / sizeVect) << 8) |
			((b / sizeVect) << 0) |
			0xFF'00'00'00;

		++manipImg;
		++curPix;
	}
	mVectResult.resize(1);
	mVectResult[0] = &image;
	return mVectResult;
}
