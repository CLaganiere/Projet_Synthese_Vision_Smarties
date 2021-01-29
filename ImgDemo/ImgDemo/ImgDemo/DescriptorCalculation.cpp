#include "DescriptorCalculation.h"

DescriptorCalculation::DescriptorCalculation()
{
}

std::vector<img_t *> DescriptorCalculation::perform(std::vector <img_t*> const & vectImage)
{
	int index{};
	for (auto & curImage : vectImage) {

		image = *curImage;
		int widthImage{ image.width() };
		int heightImage{image.height()};

		int * startPix{ reinterpret_cast<int*>(image.bits()) };
		int * curPix{ startPix };
		int * endPix{ startPix + widthImage * heightImage };
		for (auto & blob : (*vectBlobsPtr)[index]) {
			drawCross(curPix, endPix, blob.x, blob.y, widthImage, heightImage);
			curPix = startPix;
		}
		*curImage = image;
		++index;
	}

	return vectImage;
}

void DescriptorCalculation::setBlobsPtr(std::vector<Blobs> *blobs)
{
	vectBlobsPtr = blobs;
}

std::vector<int> const DescriptorCalculation::resultReply()
{
	mVectTotalSmarthies.clear();
	if (vectBlobsPtr->size() != mVectTotalSmarthies.size()) {
		mVectTotalSmarthies.resize((*vectBlobsPtr).size());
	}

	int index{};
	for (auto & blob : *vectBlobsPtr) {
		mVectTotalSmarthies[index] = blob.size();
		++index;
	}

	return mVectTotalSmarthies;
}

void DescriptorCalculation::drawCross(int * startPix, int const * endPix, int const x, int const y, int const width, int const height)
{
	int * maniPix{ startPix + x + (width * y) };

	//TOP line
	int index{};
	while (index < sizeCross && y-index >=0) {
		*maniPix = colorRed;
		maniPix -= width;
		++index;
	}

	//Left line
	index = 0;
	maniPix = startPix + x + (width * y);
	while(index < sizeCross && x-index >=0){
		*maniPix = colorRed;
		--maniPix;
		++index;
	}
	
	//Right line
	index = 0;
	maniPix = startPix + x + (width * y);
	while (index < sizeCross && x+index <=width) {
		*maniPix = colorRed;
		++maniPix;
		++index;
	}

	//Bottom line
	index = 0;
	maniPix = startPix + x + (width * y) ;
	while (index < sizeCross && y+index < height) {
		*maniPix = colorRed;
		maniPix += width;
		++index;
	}
	
}
