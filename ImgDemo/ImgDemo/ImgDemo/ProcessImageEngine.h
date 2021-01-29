#ifndef PROCESS_IMAGE_ENGINE_H
#define PROCESS_IMAGE_ENGINE_H

#include <Vector>
#include <QString>
#include "Img_t.h"
#include "Camera.h"

#include "QSimpleImageViewer.h"

//#include "Blobs.h"

//Process de FactoryProcess
#include "FactoryProcess.h"
#include "OpeImgProc.h"
#include "OpeBackImgProc.h"

//Import de Color
#include "Color.h"

//Import du Process Manaher
#include "ProcessManager.h"

#include "IncludeManager.h"

#include "SegmentationDebug.h"

class ProcessImageEngine : public QObject
{
	Q_OBJECT
public:
	ProcessImageEngine(QObject *parent = nullptr);
	~ProcessImageEngine()override;

	void addImage();
	void insertImageToProcess();
	void insertBgToProcess();

	//	Process de préparation, de manipulation et d'extraction de données
	void processBackgroundImg();
	void creationLightCard();
	void processImage(img_t const &imageManip);
	void debugProcess(img_t const &imageManip, 
						uint8_t channel0Min, uint8_t channel0Max,
						uint8_t channel1Min, uint8_t channel1Max, 
						uint8_t channel2Min, uint8_t channel2Max);

	void addBackgroundImage(img_t const &image);

	//	Fonctions supplémentaires
	void setColorToProcess(std::vector<int> vectColor);
	void findResults();
	void deletePrincipalProc(UnyProc * porcessDlt);
	void insertBgProc();
	void deleteBgProc();
	void switchImage(img_t * imageOne, img_t * imageTwo);

	//	Setteur et getteur d'image pour interagir avec GUEngine
	void setImgOriginal(img_t const & image);
	img_t & imgOriginal();
	img_t const & lightCard()const;

	img_t & imgResults();	//À modifier

	void createLightCard(img_t const &image);

private: 
	img_t mImgOriginal;
	img_t mImageProcessed;
	img_t mManipOne;
	img_t mManipTwo;
	img_t mLightCard;
	img_t mImgDebug;
	Camera  mCamera;
	FactoryProcess * mFtyPrincProc;
	FactoryProcess * mFtyBackProc;

	std::vector <img_t *> mVectManipImgOne, mVectManipImgTwo;
	std::vector <img_t *> mVectBkgManipImgOne, mVectBkgManipImgTwo;
	std::vector <img_t> mBackgroundSaver;
	
	std::vector <img_t *> mVectProcessImg;
	std::vector <img_t *> mVectBackImg;
	std::vector <EmbeddedProc *> mPrincipalProc;
	std::vector <EmbeddedProc *> mBackProc;
	ProcessManager mPrincProcessManager;
	ProcessManager mBckgProcessManager;

	SegmentationDebug * mSegmentationDebug{ nullptr };
	Uniformisation * mUniformisationDebug{ nullptr };
	ConvolutionGaussian * mGaussianDebug{ nullptr };
	KernelFilter mKernelDebug;
	
	std::vector<Color> mVectColorInit;
	std::vector<Color> mVectColorProc;
	std::vector<Color> mVectColorDebug;

	std::vector<Blobs> mVectBlobs;
	int curIndexDebugColor{};
	
	QString startResult, restResult;
	std::vector<QString> mColorStringnify;

public slots:
	void prepareProcess(img_t const & image);
	void prepareDebug(img_t const & image);
	void imageToShow(img_t const &image);
	void imageProcessedReceiver(img_t const &image);
	void lightCardReceiver(img_t const &image);
	void processLightCard();
	void getImageProcessed();
	void getLightCard();
	void getImageDebug();
	void getVectColorDebug();
	void addColorToEval(const int &tagColor);
	void imageDebugProcess(img_t const & image);
	void changeDebugColor(const int &tagColor);
	void setVectColorProc(std::vector<Color> const &vectColor);
	void createStringResults(std::vector<int> const &vectResults);

signals:
	void showImage(img_t const & image);
	void imageProcessed(img_t const & image);
	void imageLightCard(img_t const & image);
	void imageDebug(img_t const & image);
	void smarthiesReplied(QString result);
	void debugPrepared();
	void colorFromDebug(std::vector<Color> &vectColor);
};


#endif // PROCESS_IMAGE_ENGINE_H