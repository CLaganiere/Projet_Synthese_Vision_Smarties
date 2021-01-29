#ifndef CALCUL_AREA_H
#define CALCUL_AREA_H

#include "DescriptorCalculation.h"
class CalcArea : public DescriptorCalculation
{
public:
	CalcArea() = default;
	~CalcArea()override = default;

	std::vector<img_t *> perform(std::vector <img_t*> const & vectImage) override;
};

#endif // CALCUL_AREA_H
