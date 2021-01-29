#ifndef MEDIAN_H
#define MEDIAN_H

#include "Filter.h"
class Median : public Filter
{
public:
	Median(KernelFilter kernel, int const imageWidth, int const imageHeight);
	~Median()override = default;

	std::vector<img_t *> perform(std::vector<img_t *> const & ImageOne) override;

private:
	int sizeFilter;
	int border;
	int sizeMatFilter;
	int posMidPix;
	int mWidthImage;
	int mHeightImage;

	std::vector<unsigned char> valueR;
	std::vector<unsigned char> valueG;
	std::vector<unsigned char> valueB;

	uint32_t masque0{ 0x00'FF'00'00 };
	uint32_t masque1{ 0x00'00'FF'00 };
	uint32_t masque2{ 0x00'00'00'FF };
	uint32_t masque3{ 0xFF'00'00'00 };
};

#endif // MEDIAN_H