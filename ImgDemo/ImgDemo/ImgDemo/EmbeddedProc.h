#ifndef EMBEDDED_PROC_H
#define EMBEDDED_PROC_H

#include "Img_t.h"

class EmbeddedProc
{
public:
	EmbeddedProc() = default;
	virtual ~EmbeddedProc() = default;

	virtual std::vector<img_t *> perform(std::vector <img_t*> const & vectImage)=0;

protected:
	img_t image;
};

#endif // EMBEDDED_PROC_H
