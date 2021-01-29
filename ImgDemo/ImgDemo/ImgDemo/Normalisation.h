#ifndef NORMALISATION_H
#define NORMALISATION_H

#include "UnyProc.h"
class Normalisation : public UnyProc
{
public:
	Normalisation()=default;
	~Normalisation()override=default;

	std::vector<img_t *> perform(std::vector <img_t*> const & vectImage) override;

private:
	float mMinValC0{0};
	float mMaxValC0{0};
	float mMinValC1{0};
	float mMaxValC1{0};
	float mMinValC2{0};
	float mMaxValC2{0};
	unsigned char mCharMax{ 255 };

};

#endif // NORMALISATION_H