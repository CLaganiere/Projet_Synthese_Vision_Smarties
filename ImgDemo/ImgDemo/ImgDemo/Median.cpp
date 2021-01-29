#include "Median.h"

Median::Median(KernelFilter kernel, int const imageWidth, int const imageHeight)
	:mWidthImage{ imageWidth },
	mHeightImage{ imageHeight },
	sizeFilter{ kernel.widthKernel() },
	border{ kernel.notEvalBorder() },
	sizeMatFilter{ kernel.sizeMatrix() }
{
	mKernelFilter = kernel;
	posMidPix = sizeMatFilter / 2;

	valueR.resize(sizeMatFilter);
	valueG.resize(sizeMatFilter);
	valueB.resize(sizeMatFilter);

	image = img_t(mWidthImage, mHeightImage, img_t::Format_ARGB32);
}

std::vector<img_t *> Median::perform(std::vector<img_t *> const & vectImage)
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
		curKernel = 0;

		manipPix = curPix;
		while (curKernel < endKernel) {
			curPix += mKernelFilter[curKernel].first;
			valueR[curKernel] = static_cast<unsigned char>((*curPix & masque0) >> 16);
			valueG[curKernel] = static_cast<unsigned char>((*curPix & masque1) >> 8);
			valueB[curKernel] = static_cast<unsigned char>((*curPix & masque2) >> 0);

			curPix = manipPix;
			++curKernel;
		}

		std::sort(valueR.begin(), valueR.end());
		std::sort(valueG.begin(), valueG.end());
		std::sort(valueB.begin(), valueB.end());

		if (sizeFilter &(0x01)) {
			*modifPix = (((valueR[posMidPix] + valueR[posMidPix + 1]) / 2) << 16) |
				(((valueG[posMidPix] + valueG[posMidPix + 1]) / 2) << 8) |
				(((valueB[posMidPix] + valueB[posMidPix + 1]) / 2) << 0) |
				masque3;
		}
		else {
			*modifPix = (valueR[posMidPix] << 16) |
				(valueG[posMidPix] << 8) |
				(valueB[posMidPix] << 0) |
				masque3;
		}

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
	return vectImage;
}
