#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include "UnyProc.h"

#include "BlobsInfo.h"
#include "Color.h"

class Classification : public UnyProc
{
public:
	Classification(int width, int height);
	~Classification()override = default;

	std::vector<img_t *> perform(std::vector <img_t*> const & vectImage) override;

	void setBeginnigImagePtr(img_t * firstImage);
	void setVectColorPtr(std::vector<Color> * vectColor);

private:
	int mWidthImage;
	int mHeightImage;
	std::vector<Color> * vectColorPtr{ nullptr };
	std::vector<img_t*> mVectImage{ nullptr };
	img_t * mPtrImageBegin{nullptr};
	uint32_t colorRed{ 0xFF'FF'00'00 };
	uint32_t black{ 0xFF'00'00'00 };
	uint32_t white{ 0xFF'FF'FF'FF };
};

#endif // CLASSIFICATION_H