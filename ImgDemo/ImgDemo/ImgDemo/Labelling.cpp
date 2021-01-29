#include "Labelling.h"

#include "Smarthies.h"
#pragma inline_recursion( on )
#pragma inline_depth( 255 )

Labelling::Labelling(int imageWidth, int imageHeight)
	:mWidthImage{ imageWidth },
	mHeightImage{ imageHeight }
{
}

std::vector<img_t*> Labelling::perform(std::vector<img_t*> const & vectImage)
{
	if (vectImage.size() != mVectImageLabel.size()) {
		mVectImageLabel.resize(vectImage.size());
		vectBlobsPtr->resize(vectImage.size());
		for (auto & blob : *vectBlobsPtr) {
			blob = Blobs();
		}
	}

	int index{};
	for (auto & curImage : mVectImageLabel) {

		mCurrentLabel = 0xFF'00'00'01;

		curImage = img_t(*vectImage[index]);

		borderReset(curImage, black);

		uint32_t * curPix{ reinterpret_cast<uint32_t *>(curImage.bits()) };
		uint32_t * startImage{ curPix };
		uint32_t const * endPix{ curPix + (mWidthImage* mHeightImage) };

		int minAireSmarthies{ Smarthies::getMinAire() };
		int maxAireSmarthies{ Smarthies::getMaxAire() };

		while(curPix < endPix) {
		
			if (*curPix == white) {
				uint32_t area{ stamping(curPix) };

				if (area >= minAireSmarthies && area <= maxAireSmarthies) {
					(*vectBlobsPtr)[index].push_back({(curPix - startImage) % mWidthImage,
											static_cast<int>((curPix - startImage) / mWidthImage),
											static_cast<int>(area) });
				}
				++mCurrentLabel;
			}
			++curPix;
		}
		++index;
	}

	return vectImage;
}

void Labelling::setBlobsPtr(std::vector<Blobs> * blobs)
{
	vectBlobsPtr = blobs;
}

void Labelling::borderReset(img_t &curImage, uint32_t value)
{
	int * curPix{ reinterpret_cast<int*>(curImage.bits()) };
	int * endPix{ curPix + (mWidthImage * mHeightImage) };
	int * manipPix{};
	int * topBorder{ curPix + mWidthImage };
	int * sideBorder{ curPix + (mWidthImage * (mHeightImage - 1)) };
	int larger{ mWidthImage - 1 };

	while (curPix < topBorder) {
		//Top border
		*curPix = value;
		++curPix;
	}

	while (curPix < sideBorder) {
		//Right border
		*curPix = value;

		curPix += larger;

		//Left border
		*curPix = value;

		++curPix;
	}

	while (curPix < endPix) {
		//Bottom border
		*curPix = value;

		++curPix;
	}
}

inline uint32_t Labelling::stamping(uint32_t* p) 
{	// Calling récursif de l'étiquettage d'un blob
	*p = mCurrentLabel;
	return stampingTo(p + 1)
		+ stampingTo(p - 1)
		+ stampingTo(p - mWidthImage)
		+ stampingTo(p + mWidthImage)
		+ stampingTo(p + mWidthImage + 1)
		+ stampingTo(p + mWidthImage - 1)
		+ stampingTo(p - mWidthImage - 1)
		+ stampingTo(p - mWidthImage + 1)
		+ 1;
}

inline uint32_t Labelling::stampingTo(uint32_t* p) 
{	//Est-ce que le pixel est blanc?
	return (*p == white) ? stamping(p) : 0;
}