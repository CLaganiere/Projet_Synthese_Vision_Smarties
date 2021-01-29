#include "SegmentationNormal.h"

SegmentationNormal::SegmentationNormal(int const imageWidth, int const imageHeight)
	:mWidthImage{ imageWidth },
	mHeightImage{ imageHeight }
{

}

SegmentationNormal::~SegmentationNormal()
{
	for (auto & curImage : mVectImage) {
		delete curImage;
	}

	mVectImage.clear();
}

std::vector<img_t *> SegmentationNormal::perform(std::vector <img_t*> const & vectImage) {
	
	image = img_t(*vectImage[0]);

	int curColor{};
	for (auto & curImage : mVectImage) {

		if (image.size() != curImage->size() || image.format() != curImage->format() || image.format() != QImage::Format_ARGB32) {
			throw std::invalid_argument("Image passer en parametre ne comporte pas le même format ");
		}
	
		*curImage = image.copy();
		rgbhsv(*curImage);

		//SEGMENTATION 
		uint32_t const * curPix{ reinterpret_cast<uint32_t *>(image.bits()) };
		uint32_t const * endPix{ curPix + (image.width()* image.height()) };
		uint32_t * modifPix{ reinterpret_cast<uint32_t *>(curImage->bits()) };

		int crMin{ (*mVectColor)[curColor].minChanel0() };
		int cgMin{ (*mVectColor)[curColor].minChanel1() };
		int cbMin{ (*mVectColor)[curColor].minChanel2() };

		int crMax{ (*mVectColor)[curColor].maxChanel0() };
		int cgMix{ (*mVectColor)[curColor].maxChanel1() };
		int cbMax{ (*mVectColor)[curColor].maxChanel2() };

		while (curPix < endPix) {

			uint32_t value{ *modifPix };
			uint8_t r{ (*curPix >> 16) & 0xFF };
			uint8_t g{ (*curPix >> 8) & 0xFF };
			uint8_t b{ (*curPix >> 0) & 0xFF };

			*modifPix = (r >= crMin && r <= crMax && g >= cgMin && g <= cgMix && b >= cbMin && b <= cbMax) ? white : black;

			++modifPix;
			++curPix;
		}

		++curColor;
	}

	return mVectImage;
}

void SegmentationNormal::setVectColor(std::vector<Color> * vectColor)
{
	for (auto & curImage : mVectImage) {
		delete curImage;
	}

	mVectColor = vectColor;
	mVectImage.resize((*mVectColor).size());

	for (auto & curImage : mVectImage) {
		curImage = new img_t(mWidthImage, mHeightImage, img_t::Format_ARGB32);
	}
}

void SegmentationNormal::setColor(int index, Color color)
{
	(*mVectColor)[index] = color;
}

void SegmentationNormal::setPercentageVar(float percentage)
{
	if (percentage > 0 && percentage < 1.00) {
		this->mPercentageVar = percentage;
	}
}

void SegmentationNormal::rgbhsv(img_t &manipImage)
{
	//RGB TO HSV
	uint32_t const * pixelFrom{ reinterpret_cast<uint32_t const *>(image.constBits()) };
	uint32_t const * pixelFromEnd{ pixelFrom + mWidthImage * mHeightImage };
	uint32_t * pixelTo{ reinterpret_cast<uint32_t *>(manipImage.bits()) };

	while (pixelFrom < pixelFromEnd) {
		*pixelTo = mRgb2Hsv[*pixelFrom & 0x00'FF'FF'FF];
		++pixelFrom;
		++pixelTo;
	}
}

void SegmentationNormal::hsvrgb(img_t &manipImage)
{
	//HSV TO RBG
	uint32_t const * pixelFrom{ reinterpret_cast<uint32_t const *>(image.constBits()) };
	uint32_t const * pixelFromEnd{ pixelFrom + mWidthImage * mHeightImage };
	uint32_t * pixelTo{ reinterpret_cast<uint32_t *>(manipImage.bits()) };

	while (pixelFrom < pixelFromEnd) {
		*pixelTo = mHsv2Rgb[*pixelFrom & 0x00'FF'FF'FF];
		++pixelFrom;
		++pixelTo;
	}
}


