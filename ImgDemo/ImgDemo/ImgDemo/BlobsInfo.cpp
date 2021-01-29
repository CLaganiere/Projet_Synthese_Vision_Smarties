#include "BlobsInfo.h"

BlobsInfo::BlobsInfo(int xVal, int yVal, int areaVal)
{
	this->x = xVal;
	this->y = yVal;
	this->area = areaVal;
}

bool BlobsInfo::operator==(BlobsInfo const & b) const
{
	return this->x == b.x && this->y && b.y && this->area == b.area ? true : false;
}