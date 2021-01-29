#include "ConvolutionUniform.h"

ConvolutionUniform::ConvolutionUniform(KernelFilter kernel, int const imageWidth, int const imageHeight)
	:mWidthImage{ imageWidth },
	mHeightImage{ imageHeight },
	sizeMatFilter{ kernel.sizeMatrix() },
	border{ kernel.notEvalBorder() }
{
	mKernelFilter = kernel;

	image = img_t(mWidthImage, mHeightImage, img_t::Format_ARGB32);
}

std::vector<img_t*> ConvolutionUniform::perform( std::vector<img_t*> const & vectImage)
{
	int * curPix{ reinterpret_cast<int*>(vectImage[0]->bits()) };
	int * endPix{ reinterpret_cast<int*>(vectImage[0]->bits()) + (mWidthImage * (mHeightImage - border)) };
	int * modifPix{ reinterpret_cast<int*>(image.bits()) };
	int * manipPix{};
	int curKernel, endKernel{ sizeMatFilter };
	int axeY{ border };

	curPix += (mWidthImage* border) + border;
	modifPix += (mWidthImage* border) + border;
	while (curPix < endPix) {
		valueRf = 0, valueGf = 0, valueBf = 0, curKernel = 0;
		manipPix = curPix;
		while (curKernel < endKernel) {
			double weight = mKernelFilter[curKernel].second;
			curPix += mKernelFilter[curKernel].first;
			valueRf += static_cast<unsigned char>((*curPix & 0x00'FF'00'00) >> 16) * weight;
			valueGf += static_cast<unsigned char>((*curPix & 0x00'00'FF'00) >> 8)  * weight;
			valueBf += static_cast<unsigned char>((*curPix & 0x00'00'00'FF) >> 0)  * weight;

			curPix = manipPix;
			++curKernel;
		}

		valueR = static_cast<int>(valueRf);
		valueG = static_cast<int>(valueGf);
		valueB = static_cast<int>(valueBf);

		*modifPix = (valueR << 16) |
			(valueG << 8) |
			(valueB << 0) |
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
	*vectImage[0] = *&image;
	return vectImage;
}