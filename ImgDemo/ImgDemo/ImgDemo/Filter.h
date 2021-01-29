#ifndef FILTER_H
#define FILTER_H

#include "UnyProc.h"
#include "KernelFilter.h"

class Filter : public UnyProc
{
public:
	Filter() = default;
	~Filter() override= default;

protected:
	KernelFilter mKernelFilter;
};

#endif // FILTER_H