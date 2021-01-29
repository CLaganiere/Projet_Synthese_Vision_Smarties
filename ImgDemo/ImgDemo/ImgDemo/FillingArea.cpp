#include "FillingArea.h"

FillingArea::FillingArea(int imageWidth, int imageHeight)
	:mWidthImage{ imageWidth },
	mHeightImage{ imageHeight }
{

	image = img_t(mWidthImage, mHeightImage, img_t::Format_ARGB32);
	qBlack = qRgb(0, 0, 0);
	qWhite = qRgb(255, 255, 255);
	qRemVal = qRgb(150, 120, 100);

}

FillingArea::~FillingArea()
{
	for (auto & curImage : mVectImage) {
		delete curImage;
	}

	mVectImage.clear();
}

void FillingArea::setVectImage(int size)
{
	for (auto & curImage : mVectImage) {
		delete curImage;
	}

	mVectImage.resize(size);

	for (auto & curImage : mVectImage) {
		curImage = new img_t(mWidthImage, mHeightImage, img_t::Format_ARGB32);
	}
}

std::vector<img_t*> FillingArea::perform(std::vector<img_t*> const & vectImage)
{
	
	if (vectImage.size() != mVectImage.size()) {
		setVectImage(vectImage.size());
	}

	int index{};
	for (auto & curImage : vectImage) {

		image = *curImage;

		//Étape 1 - Bordure à blanc
		borderReset(black);

		//Étape 2 - Remplir en noir 
		int * curPix{ reinterpret_cast<int*>(image.bits()) };
		int * endPix{ curPix + image.width() * image.height()};
		fill2(curPix, 0, 0, black, white, image.width(), endPix);

		//Étape 3 - Inverse B
		reverseImage();

		//Étape 4 - OU || inclusif de l'image A et B
		combineImage(curImage, index);

		++index;
	}

	return mVectImage;
}

void FillingArea::borderReset(uint32_t value)
{
	int * curPix{ reinterpret_cast<int*>(image.bits()) };
	int * endPix{ curPix + (mWidthImage * mHeightImage) };
	int * manipPix{};
	int * topBorder{ curPix + mWidthImage};
	int * sideBorder{ curPix + (mWidthImage * (mHeightImage-1)) };
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

void FillingArea::filling(int x, int y, unsigned char const curVal, unsigned char const remVal)
{
	ReplacingList mReplacingList;

	if (pixValue(x,y) != curVal) {
		return;
	}
	else {
		mReplacingList.add(x, y);
	}

	for (int i{}; i < mReplacingList.mPixelList.size(); ++i) {
		int x{ mReplacingList[i].posX };
		int y{ mReplacingList[i].posY };
		
		if (pixValue(x, y) == curVal) {

			int left{ x };
			while (left >= 0 && pixValue(left, y) == curVal) {
				setPixValue(left, y, remVal);

				if (y > 0 && pixValue(left, y-1) == curVal) {
					mReplacingList.add(left, y - 1);
				}
				if (y < mHeightImage-1 && pixValue(left, y+1) == curVal) {
					mReplacingList.add(left, y + 1);
				}
				--left;
			}
			if (left >= 0) {
				if (y > 0 && pixValue(left, y - 1) == curVal) {
					mReplacingList.add(left, y - 1);
				}
				if (y < mHeightImage - 1 && pixValue(left, y + 1) == curVal) {
					mReplacingList.add(left, y + 1);
				}
			}

			int right{ x + 1 };
			while (right < mWidthImage && pixValue(right, y) == curVal) {
				setPixValue(right, y, remVal);

				if (y > 0 && pixValue(right, y - 1) == curVal) {
					mReplacingList.add(right, y - 1);
				}
				if (y < image.height() - 1 && pixValue(right, y + 1) == curVal) {
					mReplacingList.add(right, y + 1);
				}
				++right;
			}
			if (right < mWidthImage) {
				if (y > 0 && pixValue(right, y - 1) == curVal) {
					mReplacingList.add(right, y - 1);
				}
				if (y < mHeightImage-1 && pixValue(right, y + 1) == curVal) {
					mReplacingList.add(right, y + 1);
				}
			}
		}
	}

	for (auto & pixel : mReplacingList.mPixelList) {
		setPixValue(pixel.posX, pixel.posY, remVal);
	}
}

void FillingArea::fillingQColor(int x, int y, QRgb curVal, QRgb remVal)
{
	ReplacingList mReplacingList;

	if (image.pixel(x, y) != curVal) {
		return;
	}
	else {
		mReplacingList.add(x, y);
	}

	for (int i{}; i < mReplacingList.mPixelList.size(); ++i) {
		int x{ mReplacingList[i].posX };
		int y{ mReplacingList[i].posY };

		if (image.pixel(x, y) == curVal) {

			int left{ x };
			while (left >= 0 && image.pixel(left, y) == curVal) {
				setPixValue(left, y, remVal);

				if (y > 0 && image.pixel(left, y - 1) == curVal) {
					mReplacingList.add(left, y - 1);
				}
				if (y < mHeightImage - 1 && image.pixel(left, y + 1) == curVal) {
					mReplacingList.add(left, y + 1);
				}
				--left;
			}
			if (left >= 0) {
				if (y > 0 && image.pixel(left, y - 1) == curVal) {
					mReplacingList.add(left, y - 1);
				}
				if (y < mHeightImage - 1 && image.pixel(left, y + 1) == curVal) {
					mReplacingList.add(left, y + 1);
				}
			}

			int right{ x + 1 };
			while (right < mWidthImage && image.pixel(right, y) == curVal) {
				setPixValue(right, y, remVal);

				if (y > 0 && image.pixel(right, y - 1) == curVal) {
					mReplacingList.add(right, y - 1);
				}
				if (y < image.height() - 1 && image.pixel(right, y + 1) == curVal) {
					mReplacingList.add(right, y + 1);
				}
				++right;
			}
			if (right < mWidthImage) {
				if (y > 0 && image.pixel(right, y - 1) == curVal) {
					mReplacingList.add(right, y - 1);
				}
				if (y < mHeightImage - 1 && image.pixel(right, y + 1) == curVal) {
					mReplacingList.add(right, y + 1);
				}
			}
		}
	}

	for (auto & pixel : mReplacingList.mPixelList) {
		image.setPixel(pixel.posX, pixel.posY, remVal);
	}
}

unsigned char FillingArea::pixValue(int x, int y)
{
	if (x < 0 && x >= mWidthImage && y < 0 && y >= mHeightImage) {
		throw std::out_of_range("Index des pixels invalieds lors du getter de la valeur");
	}
	int * curPix{ reinterpret_cast<int*>(image.bits() + x + (mWidthImage*y)) };
	unsigned char a{ static_cast<unsigned char>((*curPix & 0x00'FF'00'00) >> 16) };
	return a;
}

void FillingArea::setPixValue(int x, int y, unsigned char value)
{
	if (x < 0 && x >= mWidthImage && y < 0 && y >= mHeightImage) {
		throw std::out_of_range("Index des pixels invalieds lors du getter de la valeur");
	}
	int * curPix{ reinterpret_cast<int*>(image.bits() + x + (mWidthImage*y)) };
	*curPix = (value << 16) |
			(value<< 8) |
			(value << 0) |
			0xFF'00'00'00;
}

void FillingArea::reverseImage()
{
	int * curPix{ reinterpret_cast<int*>(image.bits()) };
	int * endPix{ curPix + (mWidthImage * mHeightImage) };

	while (curPix < endPix) {
		
		*curPix = *curPix == black ? white : black;

		++curPix;
	}
}

void FillingArea::combineImage(img_t * imgOne, int index)
{
	int * curPix{ (int*)(mVectImage[index]->bits()) };
	int * endPix{ curPix + (mWidthImage * mHeightImage) };
	int * curImgOne{ reinterpret_cast<int*>(imgOne->bits()) };
	int * curImgTwo{ reinterpret_cast<int*>(image.bits()) };
	
	while (curPix < endPix) {
		*curPix = *curImgOne == white || *curImgTwo == white ? white : black;

		++curImgOne;
		++curImgTwo;
		++curPix;
	}
}

void ReplacingList::add(int posX, int posY)
{
	mPixelList.push_back({ posX, posY });
}

void ReplacingList::remove(int index)
{
	mPixelList.erase(mPixelList.begin() + index);
}

Pixel ReplacingList::operator[](int index)
{
	return mPixelList[index];
}

