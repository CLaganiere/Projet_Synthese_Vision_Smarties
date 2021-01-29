#ifndef FACTORY_PROCESS_H
#define FACTORY_PROCESS_H

#include <vector>

#include "IncludeManager.h"

class FactoryProcess
{
public:
	FactoryProcess() = default;
	virtual ~FactoryProcess() = default;

	virtual std::vector<EmbeddedProc *> & vectProcess() = 0;
	virtual size_t sizeVetProcess() = 0;

protected:
	std::vector<EmbeddedProc *> mVectProcess;
	KernelFilter * mKernel;
};


#endif // FACTORY_PROCESS_H