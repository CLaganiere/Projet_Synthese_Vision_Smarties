#ifndef SHAPE_EVALUATOR_H
#define SHAPE_EVALUATOR_H

#include "DescriptorCalculation.h"
#include "Smarthies.h"

class ShapeEvaluator : public DescriptorCalculation
{
public:
	ShapeEvaluator() = default;
	~ShapeEvaluator() override = default;

	std::vector<img_t *> perform(std::vector <img_t*> const & vectImage) override;
};

#endif // SHAPE_EVALUATOR_H