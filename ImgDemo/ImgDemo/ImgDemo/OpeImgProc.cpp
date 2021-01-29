#include "OpeImgProc.h"

OpeImgProc::~OpeImgProc()
{
	for (auto & curProc : mVectProcess) {
		delete curProc;
	}

	mVectProcess.clear();
}

OpeImgProc::OpeImgProc(int const imageWidth, int const imageHeight)
{
	mKernel = new KernelFilter();
	mVectProcess.resize(9);

	mKernel->setKernelValue(3, 0);
	mKernel->setEachPositionValue(imageWidth);
	mVectProcess[0] = new Median(*mKernel, imageWidth, imageHeight);

	mKernel->setKernelValue(3, 2);
	mKernel->setEachPositionValue(imageWidth);
	mVectProcess[1] = new ConvolutionGaussian(*mKernel, imageWidth, imageHeight);

	mVectProcess[2] = new Uniformisation(imageWidth, imageHeight);
	mVectProcess[3] = new Normalisation();
	mVectProcess[4] = new SegmentationNormal(imageWidth, imageHeight);
	mVectProcess[5] = new FillingArea(imageWidth, imageHeight);
	mVectProcess[6] = new Labelling(imageWidth, imageHeight);
	mVectProcess[7] = new DescriptorCalculation();
	mVectProcess[8] = new Classification(imageWidth, imageHeight);
}

std::vector<EmbeddedProc*>& OpeImgProc::vectProcess()
{
	return mVectProcess;
}

size_t OpeImgProc::sizeVetProcess()
{
	return mVectProcess.size();
}
