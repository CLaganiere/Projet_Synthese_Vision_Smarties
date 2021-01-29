#ifndef PROCESS_H
#define PROCESS_H

#include "Img_t.h"

class Process
{
	virtual img_t & perform(img_t const & ImageOne);
	virtual img_t & perform(std::vector <img_t *> const &vectImage);
};
#endif // PROCESS_H
