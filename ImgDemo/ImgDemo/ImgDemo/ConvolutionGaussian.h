#ifndef CONVOLUTION_GAUSSIAN_H
#define CONVOLUTION_GAUSSIAN_H

#include "Convolution.h"

class ConvolutionGaussian : public Convolution
{
public:
	ConvolutionGaussian() = delete;
	ConvolutionGaussian(KernelFilter kernel, int const imageWidth, int const imageHeight);
	~ConvolutionGaussian() override = default;

	//img_t & perform(img_t const & ImageOne) override;
	std::vector<img_t*> perform(std::vector<img_t*> const & vectImage) override;

private:
	int border;
	int sizeMatFilter;
	int mWidthImage;
	int mHeightImage;

	double valueRd;
	double valueGd;
	double valueBd;
	unsigned char valueR;
	unsigned char valueG;
	unsigned char valueB;
};


#endif // CONVOLUTION_GAUSSIAN_H