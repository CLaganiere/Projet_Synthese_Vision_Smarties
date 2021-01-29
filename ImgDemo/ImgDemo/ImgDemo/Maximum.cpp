#include "Maximum.h"

Maximum::Maximum(KernelFilter kernel, int const imageWidth, int const imageHeight)
	:mWidthImage	{ imageWidth },
	mHeightImage	{ imageHeight },
	sizeFilter		{ kernel.widthKernel() },
	border			{ kernel.notEvalBorder()},
	sizeMatFilter	{ kernel.sizeMatrix()}
{
	mKernelFilter = kernel;
	image = img_t(mWidthImage, mHeightImage, img_t::Format_ARGB32);
}

std::vector<img_t *> Maximum::perform(std::vector<img_t *> const & vectImage)
{

	int * curPix{ reinterpret_cast<int*>(vectImage[0]->bits()) };
	int * endPix{ curPix + (mWidthImage * (mHeightImage - border)) };
	int * modifPix{ reinterpret_cast<int*>(image.bits()) };
	int * manipPix{};
	int curKernel, endKernel{ sizeMatFilter };
	int axeY{ border };

	curPix += (mWidthImage* border) + border;
	modifPix += (mWidthImage* border) + border;
	while (curPix < endPix) {
		unsigned char maxPixR{};
		unsigned char maxPixG{};
		unsigned char maxPixB{};

		curKernel = 0;
		manipPix = curPix;
		while (curKernel < endKernel) {
			curPix += mKernelFilter[curKernel].first;
			unsigned char r{ static_cast<unsigned char>((*curPix & 0x00'FF'00'00) >> 16) };
			unsigned char g{ static_cast<unsigned char>((*curPix & 0x00'00'FF'00) >> 8) };
			unsigned char b{ static_cast<unsigned char>((*curPix & 0x00'00'00'FF) >> 0) };

			if (r > maxPixR) {
				maxPixR = r;
			}
			if (g > maxPixG) {
				maxPixG = g;
			}
			if (b > maxPixB) {
				maxPixB = b;
			}
			curPix = manipPix;
			++curKernel;
		}

		*modifPix = (maxPixR << 16) |
			(maxPixG << 8) |
			(maxPixB << 0) |
			0xFF'00'00'00;

		if (*curPix == (mWidthImage*axeY) - border) {
			++axeY;
			modifPix += border * 2;
			curPix += border * 2;
		}
		else {
			++modifPix;
			++curPix;
		}
	}

	*vectImage[0] = image;
	return  vectImage;
}