#ifndef BLOB_EXTRACTOR_H
#define BLOB_EXTRACTOR_H

#include "FillingArea.h"
class BlobExtractor
{
public:
	BlobExtractor() = default;
	~BlobExtractor()= default;

	img_t & processLabeling(img_t const & ImageOne);

private:

	void deadBorder();
	void parkourImage();
	void pixelIdentificator(int x, int y);
	void pixelIdentificator(int x, int y, int value);
	void blobNeighboor(int x1, int y1, int x2, int y2);
	void facadePixelCounter(int x, int y, int labelNumber);
	void addDataBlob(int x, int y, int label);
	void sortDataBlob();
	//bool compareDataBlob(Blob const & objInfo1, Blob const & objInfo2);


	int mHeight;
	int mWidth;
	long int deadPixel;
	int currentPixel;

};

#endif // BLOB_EXTRACTOR_H