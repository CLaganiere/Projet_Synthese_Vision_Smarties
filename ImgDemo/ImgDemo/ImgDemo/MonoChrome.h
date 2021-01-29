
#ifndef MONOCHROME_H
#define MONOCHROME_H

#include "UnyProc.h"
class MonoChrome : public UnyProc
{
public:
	MonoChrome() = default;
	~MonoChrome()override = default;

	std::vector<img_t *> perform(std::vector <img_t*> const & vectImage) override;

private:

};

#endif // MONOCHROME_H