#include "Normalisation.h"

std::vector<img_t *>  Normalisation::perform(std::vector <img_t*> const & vectImage)
{
	image = *vectImage[0];
	int length{ image.width() * image.height() };

	int * curPix{ reinterpret_cast<int*>(image.bits()) };
	int * endPix{ curPix + length };
	int curPos{};

	while (curPix < endPix) {

		unsigned char ch0{ static_cast<unsigned char>((*curPix & 0x00'FF'00'00) >> 16) };
		unsigned char ch1{ static_cast<unsigned char>((*curPix & 0x00'00'FF'00) >> 8) };
		unsigned char ch2{ static_cast<unsigned char>((*curPix & 0x00'00'00'FF) >> 0) };

		if (ch0 < mMinValC0) {
			mMinValC0 = ch0;
		}
		else if (ch0 > mMaxValC0) {
			mMaxValC0 = ch0;
		}

		if (ch1 < mMinValC1) {
			mMinValC1 = ch1;
		}
		else if (ch1 > mMaxValC1) {
			mMaxValC1 = ch1;
		}

		if (ch2 < mMinValC2) {
			mMinValC2 = ch2;
		}
		else if (ch2 > mMaxValC2) {
			mMaxValC2 = ch2;
		}
		
		++curPix;
	}

	curPix = reinterpret_cast<int*>(image.bits());
	while (curPix < endPix) {

		*curPix = (static_cast<unsigned char>((static_cast<unsigned char>((*curPix & 0x00'FF'00'00) >> 16) - mMinValC0) / (mMaxValC0 - mMinValC0) * 255) << 16) |
					(static_cast<unsigned char>((static_cast<unsigned char>((*curPix & 0x00'00'FF'00) >> 8) - mMinValC1) / (mMaxValC1 - mMinValC1) * 255) << 8) |
					(static_cast<unsigned char>((static_cast<unsigned char>((*curPix & 0x00'00'00'FF) >> 0) - mMinValC2) / (mMaxValC2 - mMinValC2) * 255) << 0) |
					0xFF'00'00'00;

		++curPix;
	}

	return vectImage;
}
