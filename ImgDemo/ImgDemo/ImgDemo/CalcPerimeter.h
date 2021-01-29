#ifndef CALCUL_PERIMETER_H
#define CALCUL_PERIMETER_H

#include "DescriptorCalculation.h"
class CalcPerimeter : public DescriptorCalculation
{
public:
	CalcPerimeter() = default;
	~CalcPerimeter()override = default;

	std::vector<img_t *> perform(std::vector <img_t*> const & vectImage) override;
};

#endif // CALCUL_PERIMETER_H
