#include "SegmentationDebug.h"

SegmentationDebug::SegmentationDebug(int const imageWidth, int const imageHeight)
	:mWidthImage{ imageWidth },
	mHeightImage{ imageHeight }
{
	memset(mRgb2Hsv.data(), 0, sizeof uint32_t * mRgb2Hsv.size());

	for (int r{}; r < 256; ++r) {
		for (int g{}; g < 256; ++g) {
			for (int b{}; b < 256; ++b) {
				QColor c(r, g, b);
				mRgb2Hsv[r << 16 | g << 8 | b] = black |
					static_cast<uint8_t>(c.hsvHueF() * 255) << 16 |
					static_cast<uint8_t>(c.hsvSaturationF() * 255) << 8 |
					static_cast<uint8_t>(c.valueF() * 255) << 0;

				QColor d(QColor::fromHsvF(r / 255.0, g / 255.0, b / 255.0));
				mHsv2Rgb[r << 16 | g << 8 | b] = black |
					static_cast<uint8_t>(d.redF() * 255) << 16 |
					static_cast<uint8_t>(d.greenF() * 255) << 8 |
					static_cast<uint8_t>(d.blueF() * 255) << 0;
			}
		}
	}

}

SegmentationDebug::~SegmentationDebug()
{
	for (auto & curImage : mVectImage) {
		delete curImage;
	}

	mVectImage.clear();
}

std::vector<img_t *> SegmentationDebug::perform(std::vector <img_t*> const & vectImage) {
	
	image = img_t(*vectImage[0]);

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

		int crMin{ (*mVectColor)[mCurColor].minChanel0() };
		int cgMin{ (*mVectColor)[mCurColor].minChanel1() };
		int cbMin{ (*mVectColor)[mCurColor].minChanel2() };

		int crMax{ (*mVectColor)[mCurColor].maxChanel0() };
		int cgMix{ (*mVectColor)[mCurColor].maxChanel1() };
		int cbMax{ (*mVectColor)[mCurColor].maxChanel2() };

		while (curPix < endPix) {

			uint32_t value{ *modifPix };
			uint8_t r{ (*curPix >> 16) & 0xFF };
			uint8_t g{ (*curPix >> 8) & 0xFF };
			uint8_t b{ (*curPix >> 0) & 0xFF };

			*modifPix = (r >= crMin && r <= crMax && g >= cgMin && g <= cgMix && b >= cbMin && b <= cbMax) ? value : black;

			++modifPix;
			++curPix;
		}

	}

	return mVectImage;
}

void SegmentationDebug::setVectColor(std::vector<Color> * vectColor)
{
	for (auto & curImage : mVectImage) {
		delete curImage;
	}

	mVectColor = vectColor;
	mVectImage.resize(1);

	for (auto & curImage : mVectImage) {
		curImage = new img_t(mWidthImage, mHeightImage, img_t::Format_ARGB32);
	}
}

void SegmentationDebug::setColor(int index, Color color)
{
	(*mVectColor)[index] = color;
}

void SegmentationDebug::setCurColorToEval(const int &index)
{
	mCurColor = index;
}

void SegmentationDebug::rgbhsv(img_t &manipImage)
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

void SegmentationDebug::hsvrgb(img_t &manipImage)
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


