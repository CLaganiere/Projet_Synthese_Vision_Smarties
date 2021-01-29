#ifndef ARGBFORMAT_H
#define ARGBFORMAT_H

#include "ModifColor.h"
class ARGBFormat : public ModifColor
{
public:
	ARGBFormat() = default;
	~ARGBFormat()override = default;

	std::vector<img_t *> perform(std::vector<img_t *> const & vectImage) override;
};

#endif // ARGBFORMAT_H