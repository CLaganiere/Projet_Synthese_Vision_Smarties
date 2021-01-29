#ifndef DESCRIPTOR_CALCULATION_H
#define DESCRIPTOR_CALCULATION_H

#include "UnyProc.h"
#include "BlobsInfo.h"
#include "Smarthies.h"

class DescriptorCalculation : public UnyProc
{
public:
	DescriptorCalculation();
	~DescriptorCalculation()override = default;

	std::vector<img_t *> perform(std::vector <img_t*> const & vectImage) override;

	void setBlobsPtr(std::vector<Blobs> *blobs);
	std::vector<int> const resultReply();

private:
	void drawCross(int *startPix, int const * endPix, int const x, int const y, int const width, int const height);

	std::vector<Blobs>* vectBlobsPtr;
	std::vector<int> mVectTotalSmarthies;
	uint32_t colorRed{ 0xFF'FF'00'00 };
	int sizeCross{ 8 };

};

#endif // DESCRIPTOR_CALCULATION_H
