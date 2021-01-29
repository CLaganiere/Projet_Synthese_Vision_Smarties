#ifndef OPE__IMG_PROC_H
#define OPE__IMG_PROC_H

#include "FactoryProcess.h"

class OpeImgProc : public FactoryProcess
{
public:
	OpeImgProc()=delete;
	OpeImgProc(int const imageWidth, int const imageHeight);
	~OpeImgProc() override;

	std::vector<EmbeddedProc *> & vectProcess() override;
	size_t sizeVetProcess() override;

};

#endif // OPE__IMG_PROC_H