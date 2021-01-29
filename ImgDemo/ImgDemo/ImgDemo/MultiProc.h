#ifndef MULTIPROC_H
#define MULTIPROC_H

#include "EmbeddedProc.h"

class MultiProc : public EmbeddedProc
{
public:
	MultiProc() = default;
	~MultiProc() override = default;
};
#endif // MULTIPROC_H