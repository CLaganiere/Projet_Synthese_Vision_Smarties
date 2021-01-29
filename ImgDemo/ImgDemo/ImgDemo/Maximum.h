#ifndef MAXIMUM_H
#define MAXIMUM_H

#include "Filter.h"
class Maximum : public Filter
{
public:
	Maximum(KernelFilter kernel, int const imageWidth, int const imageHeight);
	~Maximum()override = default;

	std::vector<img_t *> perform(std::vector<img_t *> const & vectImage) override;

private:
	int sizeFilter;
	int border;
	int sizeMatFilter;
	int mWidthImage;
	int mHeightImage;

};

#endif // MAXIMUM_H
