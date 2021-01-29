#ifndef CONVOLUTION_UNIFORM_H
#define CONVOLUTION_UNIFORM_H

#include "Convolution.h"

class ConvolutionUniform : public Convolution
{
public:
	ConvolutionUniform() = delete;
	ConvolutionUniform(KernelFilter kernel, int const imageWidth, int const imageHeight);
	~ConvolutionUniform() override = default;

	std::vector<img_t*> perform(std::vector<img_t*>const & vectImage) override;

private:
	int border;
	int sizeMatFilter;
	int mWidthImage;
	int mHeightImage;

	float valueRf;
	float valueGf;
	float valueBf;
	unsigned char valueR;
	unsigned char valueG;
	unsigned char valueB;
};


#endif // CONVOLUTION_UNIFORM_H