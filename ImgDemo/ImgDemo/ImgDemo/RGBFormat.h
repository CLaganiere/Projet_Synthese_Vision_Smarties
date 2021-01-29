#ifndef RGBFORMAT_H
#define RGBFORMAT_H

#include "ModifColor.h"
class RGBFormat : public ModifColor
{
public:
	RGBFormat() = default;
	~RGBFormat()override = default;

	std::vector<img_t *> perform(std::vector<img_t *> const & vectImage) override;
};

#endif // RGBFORMAT_H