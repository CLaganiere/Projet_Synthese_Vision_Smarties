#ifndef UNIFROMISATION_H
#define UNIFROMISATION_H

#include "MultiProc.h"
class Uniformisation : public MultiProc
{
public:
	Uniformisation(int const imageWidth, int const imageHeight);
	~Uniformisation()override = default;

	std::vector<img_t*> perform(std::vector <img_t *> const &vectImage) override;
	std::vector<img_t*> performOneOfMany(std::vector<img_t*> const & vectImage);
	void setLightCard(img_t * lightcard);

private:
	int mWidthImage;
	int mHeightImage;

	img_t * mLightCard;
};

#endif // UNIFROMISATION_H