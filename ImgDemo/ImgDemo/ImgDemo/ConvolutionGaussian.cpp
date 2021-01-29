#include "ConvolutionGaussian.h"

ConvolutionGaussian::ConvolutionGaussian(KernelFilter kernel, int const imageWidth, int const imageHeight)
	:mWidthImage{ imageWidth },
	mHeightImage{ imageHeight },
	sizeMatFilter{ kernel.sizeMatrix() },
	border{ kernel.notEvalBorder() }
{
	mKernelFilter = kernel;

	image = img_t(mWidthImage, mHeightImage, img_t::Format_ARGB32);
}

std::vector<img_t*> ConvolutionGaussian::perform(std::vector<img_t*> const & vectImage)
{
	for(auto & vImage : vectImage){

		int * curPix{ (int*)(vImage->bits()) };
		int * endPix{ (int*)(vImage->bits()) + (mWidthImage * (mHeightImage - border)) };
		int * modifPix{ reinterpret_cast<int*>(image.bits()) };
		int * manipPix{};
		int curKernel, endKernel{ sizeMatFilter };
		int axeY{ border };

		curPix += (mWidthImage* border) + border;
		modifPix += (mWidthImage* border) + border;
		while (curPix < endPix) {
			valueRd = 0, valueGd = 0, valueBd = 0, curKernel = 0;
			manipPix = curPix;
			while (curKernel < endKernel) {
				double weight = mKernelFilter[curKernel].second;

				curPix += mKernelFilter[curKernel].first;
				valueRd += static_cast<unsigned char>((*curPix & 0x00'FF'00'00) >> 16) * weight;
				valueGd += static_cast<unsigned char>((*curPix & 0x00'00'FF'00) >> 8)  * weight;
				valueBd += static_cast<unsigned char>((*curPix & 0x00'00'00'FF) >> 0)  * weight;

				curPix = manipPix;
				++curKernel;
			}

			valueR = static_cast<int>(valueRd);
			valueG = static_cast<int>(valueGd);
			valueB = static_cast<int>(valueBd);

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
		
		*vImage = image;
	}

	return vectImage;
}