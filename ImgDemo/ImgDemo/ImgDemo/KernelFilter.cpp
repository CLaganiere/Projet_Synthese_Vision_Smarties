#include "KernelFilter.h"


KernelFilter::KernelFilter()
	:mWidthKernel{ 3 }
{
	mWeightMatrix.resize(mWidthKernel*mWidthKernel);

	mWeightMatrix[0] = 1;
	mWeightMatrix[1] = 1;
	mWeightMatrix[2] = 1;
	mWeightMatrix[3] = 1;
	mWeightMatrix[4] = 1;
	mWeightMatrix[5] = 1;
	mWeightMatrix[6] = 1;
	mWeightMatrix[7] = 1;
	mWeightMatrix[8] = 1;
}

KernelFilter::KernelFilter(std::vector<float> const & weightMatrix, int posEvalX, int posEvalY)
	:mWeightMatrix{ weightMatrix.begin(), weightMatrix.end() },
	mPosToEvalX{ posEvalX },
	mPosToEvalY{ posEvalY }
{
	mWidthKernel = weightMatrix.size();
}

int KernelFilter::sizeMatrix() const
{
	return mWeightMatrix.size();
}

int KernelFilter::widthKernel() const
{
	return mWidthKernel;
}

int KernelFilter::posToEval() const
{
	return mPosToEvalX* mPosToEvalY;
}

int KernelFilter::posToEvalX() const
{
	return mPosToEvalX;
}

int KernelFilter::posToEvalY() const
{
	return mPosToEvalY;
}

int KernelFilter::notEvalBorder() const
{
	int border = mWidthKernel;

	if (border & ~1 != 0) {
		border += 1;
	}

	return border/2;

}

float KernelFilter::weightMatrix(int posX, int posY) const
{
	return mWeightMatrix[posX + (mWidthKernel*posY)];
}

void KernelFilter::setEachPositionValue(int const imageWidth)
{
	mValPosition.resize(mWeightMatrix.size());

	for (int y = 0; y < mWidthKernel; ++y){
		for (int x = 0; x < mWidthKernel; ++x) {

			if (y < mPosToEvalY) {
				
				if (x < mPosToEvalX) {
					mValPosition[x + (y*mWidthKernel)] = std::pair<int, double>((-(imageWidth*(mPosToEvalY - y)) - (1* (x - mPosToEvalX))), mWeightMatrix[x + (y*mWidthKernel)]);
				}
				else if (x == mPosToEvalX) {
					mValPosition[x + (y*mWidthKernel)] = std::pair<int, double>(-(imageWidth*(mPosToEvalY - y)), mWeightMatrix[x + (y*mWidthKernel)]);
				}
				else if (x > mPosToEvalX){
					mValPosition[x + (y*mWidthKernel)] = std::pair<int, double>((-(imageWidth*(mPosToEvalY - y)) + (1 * (mPosToEvalX - x))), mWeightMatrix[x + (y*mWidthKernel)]);
				}
			}
			else if (y == mPosToEvalY) {
				if (x < mPosToEvalX) {
					mValPosition[x + (y*mWidthKernel)] = std::pair<int, double>((mPosToEvalY - y) - (1 * (x - mPosToEvalX)), mWeightMatrix[x + (y*mWidthKernel)]);
				}
				else if (x == mPosToEvalX) {
					mValPosition[x + (y*mWidthKernel)] = std::pair<int, double>(0, mWeightMatrix[x + (y*mWidthKernel)]);
				}
				else if (x > mPosToEvalX) {
					mValPosition[x + (y*mWidthKernel)] = std::pair<int, double>((mPosToEvalY - y) + (1 * (x - mPosToEvalX)), mWeightMatrix[x + (y*mWidthKernel)]);
				}
			}
			else if (y > mPosToEvalY) {
				if (x < mPosToEvalX) {
					mValPosition[x + (y*mWidthKernel)] = std::pair<int, double>(((imageWidth*(y - mPosToEvalY)) - (1 * (mPosToEvalX - x))), mWeightMatrix[x + (y*mWidthKernel)]);
				}
				else if (x == mPosToEvalX) {
					mValPosition[x + (y*mWidthKernel)] = std::pair<int, double>((imageWidth*(y - mPosToEvalY)), mWeightMatrix[x + (y*mWidthKernel)]);
				}
				else if (x > mPosToEvalX) {
					mValPosition[x + (y*mWidthKernel)] = std::pair<int, double>(((imageWidth*(y - mPosToEvalY)) + (1 * (x - mPosToEvalX))), mWeightMatrix[x + (y*mWidthKernel)]);
				}
			}
		}
	}
}

void KernelFilter::setKernelValue(int sizeKernel, int conv)
{
	mWidthKernel= sizeKernel;

	if (mWidthKernel & ~1 != 0) {
		mPosToEvalX = mWidthKernel/2;
		mPosToEvalY = mPosToEvalX;
	}
	else{
		mPosToEvalX = 1;
		mPosToEvalY = 1;
	}
	
	mSizeKernel = mWidthKernel * mWidthKernel;
	mWeightMatrix.resize(mWidthKernel*mWidthKernel);
	int curKernel{}, endKernel{ mWidthKernel };

	if (conv == 0) {	//	Filtre Maximum ou Median
		while (curKernel < mSizeKernel) {
			mWeightMatrix[curKernel] = 1;
			++curKernel;
		}
	}
	else if (conv == 1) {	//	Convolution Uniforme
		float weight{ 1.0f / mSizeKernel };
		while (curKernel < mSizeKernel) {
			mWeightMatrix[curKernel] = weight;
			++curKernel;
		}
	}
	else if (conv == 2) {	//	Convolution Gaussien
		double moyenne{ 1 + ((double)mWidthKernel - 1) / 2 };
		double ecart = {((double)mWidthKernel - 1) / 5};
		int curXPixel{};
		int curYPixel{};
		const int square{ 2 };
		const double PI{ 3.1415926535897932384626433832795 };
		
		double total{};
		while (curXPixel < mWidthKernel) {
			while (curYPixel < mWidthKernel) {
				mWeightMatrix[curKernel] = (1 / (pow((2 * PI), 0.5)*ecart*ecart))* std::exp(-(pow(((curXPixel + 1) - moyenne), square) / (2 * ecart) + (pow(((curYPixel + 1) - moyenne), square)) / (2 * ecart)));
				total += mWeightMatrix[curKernel];
				++curYPixel;
				++curKernel;
			}
			curYPixel = 0;
			++curXPixel;
		}

		curKernel = 0;
		while (curKernel < mSizeKernel) {
			mWeightMatrix[curKernel] = mWeightMatrix[curKernel] / total;
			++curKernel;
		}
	}
}

std::pair<int, float> const & KernelFilter::operator[](int index) const
{
	return mValPosition[index];
}
