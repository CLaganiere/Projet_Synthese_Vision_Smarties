#ifndef FILLING_AREA_H
#define FILLING_AREA_H

#include "UnyProc.h"
#pragma inline_recursion( on )
#pragma inline_depth( 255 )
//#include "BlobExtractor.h"

struct Pixel{
	int posX;
	int posY;
};

struct ReplacingList {

	std::vector<Pixel> mPixelList;

	ReplacingList() = default;
	~ReplacingList() = default;
	void add(int posX, int posY);
	void remove(int index);
	//void remove(int posX, int posY);
	Pixel operator[](int index);
};

class FillingArea : public UnyProc
{
public:
	FillingArea() = delete;
	FillingArea(int imageWidth, int imageHeight);
	~FillingArea()override;

	std::vector<img_t *> perform(std::vector <img_t*> const & vectImage) override;

private:
	void setVectImage(int size);
	void borderReset(uint32_t value);
	void filling(int x, int y, unsigned char curVal, unsigned char remVal);
	void fillingQColor(int x, int y, QRgb curVal, QRgb remVal);
	unsigned char pixValue(int x, int y);
	void setPixValue(int x, int y, unsigned char value);
	void reverseImage();
	void combineImage(img_t * imgOne, int index);

	//BlobExtractor mBlobExtractor;
	std::vector<img_t *> mVectImage;
	int mWidthImage;
	int mHeightImage;
	std::list<std::pair<int, int>> pixelToChange;
	std::vector<int> mVectPixelValue;

	uint32_t white{ 0xFF'FF'FF'FF };
	uint32_t black{ 0xFF'00'00'00 };
	unsigned char labellingValue{ 50 };
	QRgb qBlack;
	QRgb qWhite;
	QRgb qRemVal;
};

inline int offSet(int x, int y, int lineSize) {

	return x + lineSize*y;
}

inline int * position(int * imagePtr, int x, int y, int lineSize) {

	return imagePtr + offSet(x,y,lineSize);
}

inline unsigned char value(int * imagePtr, int x, int y, int lineSize) {

	return *(imagePtr + x + (lineSize*y));
}

inline void fill2(int * imagePtr, int x, int y, uint32_t curVal, uint32_t remVal, int lineSize, int * imageEnd) {
	
	int * p{ position(imagePtr, x, y, lineSize) };
	if (p < imagePtr || p >= imageEnd || *p != curVal) {
		return;
	}

	*p = remVal;

	fill2(imagePtr, x - 1, y, curVal, remVal, lineSize, imageEnd);
	fill2(imagePtr, x + 1, y, curVal, remVal, lineSize, imageEnd);
	fill2(imagePtr, x, y - 1, curVal, remVal, lineSize, imageEnd);
	fill2(imagePtr, x, y + 1, curVal, remVal, lineSize, imageEnd);
}


#endif // FILLING_AREA_H