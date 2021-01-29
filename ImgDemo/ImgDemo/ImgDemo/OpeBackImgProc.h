#ifndef OPE_BACK_IMG_PROC_H
#define OPE_BACK_IMG_PROC_H

#include "FactoryProcess.h"

class OpeBackImgProc : public FactoryProcess
{
public:
	OpeBackImgProc() =delete;
	OpeBackImgProc(int const imageWidth, int const imageHeight);
	~OpeBackImgProc() override;

	std::vector<EmbeddedProc *> & vectProcess() override;
	size_t sizeVetProcess() override;

};

#endif // OPE_BACK_IMG_PROC_H