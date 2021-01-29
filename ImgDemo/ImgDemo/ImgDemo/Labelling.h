#ifndef LABELLING_H
#define LABELLING_H

#include "UnyProc.h"
#include "BlobsInfo.h"

class Labelling : public UnyProc
{
public:

	Labelling() = delete;
	Labelling(int imageWidth, int imageHeight);
	~Labelling()override =default;

	std::vector<img_t *> perform(std::vector <img_t*> const & vectImage) override;

	void setBlobsPtr(std::vector<Blobs> * blobs);
private:
	void borderReset(img_t &curImage, uint32_t value);
	uint32_t stampingTo(uint32_t* p);
	uint32_t stamping(uint32_t* p);

	std::vector<img_t> mVectImageLabel;
	std::vector<Blobs> * vectBlobsPtr;
	int mWidthImage;
	int mHeightImage;
	uint32_t mCurrentLabel;
	uint32_t white{ 0xFF'FF'FF'FF };
	uint32_t black{ 0xFF'00'00'00 };

};
#endif // LABELLING_H