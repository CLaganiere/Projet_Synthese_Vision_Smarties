#ifndef AVERAGE_IMAGE_H
#define AVERAGE_IMAGE_H

#include "MultiProc.h"

class AverageImage: public MultiProc
{
public:
	AverageImage(int const imageWidth, int const imageHeight);
	~AverageImage()override;

	std::vector<img_t*> perform(std::vector <img_t *> const & vectImage);

private:
	int mWidthImage;
	int mHeightImage;

	std::vector<img_t*> mVectResult;
};
#endif // AVERAGE_IMAGE_H
