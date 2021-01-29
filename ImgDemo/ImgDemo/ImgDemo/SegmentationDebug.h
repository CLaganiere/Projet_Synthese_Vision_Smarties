#ifndef SEGEMNTATION_DEBUG_H
#define SEGEMNTATION_DEBUG_H

#include <array>

#include "UnyProc.h"
#include "Color.h"

class SegmentationDebug : public UnyProc
{
public:
	SegmentationDebug(int const imageWidth, int const imageHeight);
	~SegmentationDebug()override;

	//img_t & perform(img_t const &ImageOne, Color* color) override;
	//img_t & perform(img_t const & ImageOne, std::vector<std::vector<float>> const & floatImage, Color* color) override;

	std::vector<img_t *> perform(std::vector <img_t*> const & vectImage) override;

	void setVectColor(std::vector<Color> * vectColor);
	void setColor(int index, Color color);
	void setCurColorToEval(const int &index);

private:

	void rgbhsv(img_t &manipImage);
	void hsvrgb(img_t &manipImage);

	std::vector<img_t *> mVectImage;
	std::vector<Color> * mVectColor;
	uint32_t black{ 0xFF'00'00'00 };
	uint32_t white{ 0xFF'FF'FF'FF };
	int mWidthImage;
	int mHeightImage;
	int mCurColor{};

	static constexpr size_t sLutSize{ 256 * 256 * 256 };
	std::array<uint32_t, sLutSize> mRgb2Hsv;
	std::array<uint32_t, sLutSize> mHsv2Rgb;
};

#endif // SEGEMNTATION_DEBUG_H