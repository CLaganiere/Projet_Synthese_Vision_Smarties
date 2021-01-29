#include "OpeBackImgProc.h"

OpeBackImgProc::OpeBackImgProc(int const imageWidth, int const imageHeight)
{
	mVectProcess.resize(7);
	mKernel = new KernelFilter();
	
	mKernel->setKernelValue(9, 2);
	mKernel->setEachPositionValue(imageWidth);
	mVectProcess[0] = new ConvolutionGaussian(*mKernel, imageWidth, imageHeight);
	
	mVectProcess[1] = new AverageImage(imageWidth, imageHeight);

	mKernel->setKernelValue(9, 0);
	mKernel->setEachPositionValue(imageWidth);
	mVectProcess[2] = new Maximum(*mKernel, imageWidth, imageHeight);

	mKernel->setKernelValue(9, 2);
	mKernel->setEachPositionValue(imageWidth);
	mVectProcess[3] = new ConvolutionGaussian(*mKernel, imageWidth, imageHeight);

	mKernel->setKernelValue(9, 0);
	mKernel->setEachPositionValue(imageWidth);
	mVectProcess[4] = new Maximum(*mKernel, imageWidth, imageHeight);

	mKernel->setKernelValue(9, 2);
	mKernel->setEachPositionValue(imageWidth);
	mVectProcess[5] = new ConvolutionGaussian(*mKernel, imageWidth, imageHeight);

	mVectProcess[6] = new MonoChrome();
}

OpeBackImgProc::~OpeBackImgProc()
{
	for (auto & curProc : mVectProcess) {
		delete curProc;
	}

	mVectProcess.clear();
}

std::vector<EmbeddedProc*>& OpeBackImgProc::vectProcess()
{
	return mVectProcess;
}

size_t OpeBackImgProc::sizeVetProcess()
{
	return mVectProcess.size();
}
