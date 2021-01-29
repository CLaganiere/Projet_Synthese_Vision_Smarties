#include "Classification.h"

#pragma inline_recursion( on )
#pragma inline_depth( 255 )

Classification::Classification(int width, int height)
	:mWidthImage{width},
	mHeightImage{height}
{
	mVectImage.resize(1);
	mVectImage[0] = &image;
}

std::vector<img_t *>  Classification::perform(std::vector <img_t*> const & vectImage)
{
	image = *mPtrImageBegin;

	int index{};
	for (auto & curImage : vectImage) {

		uint32_t const * curPix{ reinterpret_cast<uint32_t *>(curImage->bits()) };
		uint32_t const * startPix{ curPix };
		uint32_t const * endPix{ curPix + (image.width()* image.height()) };
		uint32_t * modifPix{ reinterpret_cast<uint32_t *>(image.bits()) };

		int ch0{ ((*vectColorPtr)[index].maxChanel0() + (*vectColorPtr)[index].minChanel0()) / 2 };
		int ch1{ ((*vectColorPtr)[index].maxChanel1() + (*vectColorPtr)[index].minChanel1()) / 2 };
		int ch2{ ((*vectColorPtr)[index].maxChanel2() + (*vectColorPtr)[index].minChanel2()) / 2 };

		uint32_t curColor{ (ch0 << 16) |
							(ch1 << 8) |
							(ch2 << 0) |
							0xFF'00'00'00 };

		while (curPix < endPix) {

			if (*curPix != black) {
				*modifPix = *curPix == colorRed ? colorRed : curColor;
			}

			++modifPix;
			++curPix;
		}
		
		++index;
	}

	return mVectImage;
}

void Classification::setBeginnigImagePtr(img_t * firstImage)
{
	mPtrImageBegin = firstImage;
}

void Classification::setVectColorPtr(std::vector<Color>* vectColor)
{
	vectColorPtr = vectColor;
}