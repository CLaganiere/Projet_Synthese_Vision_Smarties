#ifndef CALCUL_COMPLEXITY_H
#define CALCUL_COMPLEXITY_H

#include "DescriptorCalculation.h"
class CalcComplexity : public DescriptorCalculation
{
public:
	CalcComplexity() = default;
	~CalcComplexity()override = default;

	std::vector<img_t *> perform(std::vector <img_t*> const & vectImage) override;
};

#endif // CALCUL_COMPLEXITY_H
