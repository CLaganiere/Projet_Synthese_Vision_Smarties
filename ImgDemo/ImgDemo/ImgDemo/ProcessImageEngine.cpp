#include "ProcessImageEngine.h"

ProcessImageEngine::ProcessImageEngine(QObject *parent)
	:QObject(parent)
{
	//mVectColorProc.resize(8);
	//mVectColorProc[0] = Color(104, 177, 25, 187, 142, 234, 0);		//HOODIE Jaune TEST2
	////mVectColorProc[0] = Color(0, 100, 0, 100, 200, 255, 0);		//ColorBlue
	//mVectColorProc[1] = Color(0, 100, 100, 255, 0, 100, 1);		//ColorGreen();
	//mVectColorProc[2] = Color(100, 200, 0, 100, 0, 100, 2);	    //ColorBrown();
	//mVectColorProc[3] = Color(200, 255, 100, 165, 0, 100, 3);	//ColorOrange();
	//mVectColorProc[4] = Color(200, 255, 150, 240, 150, 250, 4);	//ColorPink();
	//mVectColorProc[5] = Color(125, 175, 0, 100, 200, 255, 5);	//ColorPurple();
	//mVectColorProc[6] = Color(200, 255, 0, 75, 0, 75, 6);		//ColorRed();
	//mVectColorProc[7] = Color(200, 255, 200, 255, 0, 75, 7);	//ColorYellow();
	mColorStringnify.resize(8);
	mColorStringnify[0] = "bleu(s)";
	mColorStringnify[1] = "vert(s)";
	mColorStringnify[2] = "brun(s)";
	mColorStringnify[3] = "orange(s)";
	mColorStringnify[4] = "rose(s)";
	mColorStringnify[5] = "mauve(s)";
	mColorStringnify[6] = "rouge(s)";
	mColorStringnify[7] = "jaune(s)";

	mVectColorProc.resize(8);
	mVectColorProc[0] = Color(104, 177, 25, 187, 142, 234, 0);

	mVectColorDebug.resize(1);
	mVectColorDebug[0] = Color(0, 255, 0, 255, 0, 255, 0);

	connect(&mPrincProcessManager, &ProcessManager::imgProcessed, this, &ProcessImageEngine::imageToShow);
	connect(&mBckgProcessManager,  &ProcessManager::imgProcessed, this, &ProcessImageEngine::imageToShow);

	connect(&mPrincProcessManager, &ProcessManager::imgFinale, this, &ProcessImageEngine::imageProcessedReceiver);
	connect(&mBckgProcessManager,  &ProcessManager::imgFinale, this, &ProcessImageEngine::lightCardReceiver);
}

ProcessImageEngine::~ProcessImageEngine()
{
	for (auto & cur : mVectProcessImg) {
		delete cur;
	}

	for (auto & cur : mVectBackImg) {
		delete cur;
	}
	
	for (auto & cur : mPrincipalProc) {
		delete cur;
	}

	for (auto & cur : mBackProc) {
		delete cur;
	}

	mVectProcessImg.clear();
	mVectBackImg.clear();
	mPrincipalProc.clear();
	mBackProc.clear();
}

void ProcessImageEngine::prepareProcess(img_t const & image)
{
	mImgOriginal = image;
	int imageWidth = image.width();
	int imageHeight = image.height();
	mFtyPrincProc = new OpeImgProc(imageWidth, imageHeight);
	mFtyBackProc = new OpeBackImgProc(imageWidth, imageHeight);
	
	mPrincipalProc = mFtyPrincProc->vectProcess();
	mBackProc = mFtyBackProc->vectProcess();

	//Setup des inputs des process
	static_cast<Uniformisation*>(mPrincipalProc[2])->setLightCard(&mLightCard);
	static_cast<SegmentationNormal*>(mPrincipalProc[4])->setVectColor(&mVectColorProc);
	static_cast<Labelling*>(mPrincipalProc[6])->setBlobsPtr(&mVectBlobs);
	static_cast<DescriptorCalculation*>(mPrincipalProc[7])->setBlobsPtr(&mVectBlobs);
	static_cast<Classification*>(mPrincipalProc[8])->setBeginnigImagePtr(&mImgOriginal);
	static_cast<Classification*>(mPrincipalProc[8])->setVectColorPtr(&mVectColorProc);
	
	//Affectation des porcess au bon ProcessManager
	int index{};
	for (auto & process : mPrincipalProc) {
		if (index &(0x01)) {
			mPrincProcessManager.add(process, &mVectManipImgTwo, &mVectManipImgOne);
		}
		else {
			mPrincProcessManager.add(process, &mVectManipImgOne, &mVectManipImgTwo);
		}
		++index;
	}

	index = 0;
	for (auto & process : mBackProc) {
		if (index &(0x01)) {
			mBckgProcessManager.add(process, &mVectBkgManipImgTwo, &mVectBkgManipImgOne);
		}
		else {
			mBckgProcessManager.add(process, &mVectBkgManipImgOne, &mVectBkgManipImgTwo);
		}
		++index;
	}

	createLightCard(image);
}

void ProcessImageEngine::prepareDebug(img_t const & image)
{
	int imageWidth = image.width();
	int imageHeight = image.height();
	mKernelDebug.setKernelValue(3, 2);

	emit debugPrepared();
	mKernelDebug.setEachPositionValue(imageWidth);
	emit debugPrepared();
	mGaussianDebug = new ConvolutionGaussian(mKernelDebug, imageWidth, imageHeight);
	emit debugPrepared();
	mUniformisationDebug = new Uniformisation(imageWidth, imageHeight);
	mUniformisationDebug->setLightCard(&mLightCard);
	emit debugPrepared();
	mSegmentationDebug = new SegmentationDebug(imageWidth, imageHeight);
	mSegmentationDebug->setVectColor(&mVectColorDebug);
	emit debugPrepared();

	if (mLightCard.format() != img_t::Format_ARGB32) {
		createLightCard(image);
	}
}

void ProcessImageEngine::processImage(img_t const & imageManip)
{
	mImgOriginal = imageManip;
	mVectManipImgOne.resize(1);
	img_t i = imageManip.copy();
	mVectManipImgOne[0] = &i;

	mPrincProcessManager.process();
	createStringResults(static_cast<DescriptorCalculation*>(mPrincipalProc[7])->resultReply());
	
	for (auto & blob : mVectBlobs) {
		blob.clear();
	}
	//	Test des filtres et convolution	-----------------------
	//viewer.setImage(mPrincipalProc.at(2)->perform(imageManip));
	//0=>Median
	//1=>ConvoUniform
	//2=>Maximum
	//3=>Normalisation
	//4=>SegmentationNormal
	//5=>FillingArea
	//6=>DescriptorCalculation
	//7=>Classification
	//	-------------------------------------------------------
}

void ProcessImageEngine::debugProcess(img_t const & imageManip, uint8_t channel0Min, uint8_t channel0Max, uint8_t channel1Min, uint8_t channel1Max, uint8_t channel2Min, uint8_t channel2Max)
{
	mVectColorDebug[curIndexDebugColor].setAllChanels(channel0Min, channel0Max, channel1Min, channel1Max, channel2Min, channel2Max);

	mVectManipImgOne.resize(1);
	img_t i = imageManip.copy();
	mVectManipImgOne[0] = &i;

	mVectManipImgTwo = mGaussianDebug->perform(mVectManipImgOne);
	mVectManipImgOne = mUniformisationDebug->perform(mVectManipImgTwo);
	mVectManipImgTwo = mSegmentationDebug->perform(mVectManipImgOne);
	emit showImage(*mVectManipImgTwo[0]);
	imageDebugProcess(*mVectManipImgTwo[0]);
}

void ProcessImageEngine::processLightCard()
{
	if (mBackgroundSaver.size()) {

		mVectBkgManipImgOne.resize(mBackgroundSaver.size());
		int index{};
		for (auto & image : mBackgroundSaver) {
			mVectBkgManipImgOne[index] = &image;
			++index;
		}
		mBckgProcessManager.process();
	}
}

void ProcessImageEngine::getImageProcessed()
{
	emit imageProcessed(mImageProcessed);
}

void ProcessImageEngine::getLightCard()
{
	emit imageLightCard(mLightCard);
}

void ProcessImageEngine::getImageDebug()
{
	emit imageDebug(mImgDebug);
}

void ProcessImageEngine::getVectColorDebug()
{
	emit colorFromDebug(mVectColorDebug);
}

void ProcessImageEngine::addColorToEval(const int & tagColor)
{
	for (auto & color : mVectColorProc) {
		if (tagColor == color.tag()) {
			return;
		}
	}

	mVectColorProc.push_back(mVectColorInit[tagColor]);
}

void ProcessImageEngine::imageDebugProcess(img_t const & image)
{
	mImgDebug = image;
}

void ProcessImageEngine::changeDebugColor(const int &tagColor)
{
	int id{ NULL };
	for (auto & color : mVectColorDebug) {
		color.tag() == tagColor? id = tagColor : 0;
	}
	if (id == NULL) {
		mVectColorDebug.push_back(Color(0, 255, 0, 255, 0, 255, tagColor));
	}
	curIndexDebugColor = mVectColorDebug.size() - 1;
	mSegmentationDebug->setVectColor(&mVectColorDebug);
	mSegmentationDebug->setCurColorToEval(curIndexDebugColor);
}

void ProcessImageEngine::setVectColorProc(std::vector<Color> const & vectColor)
{
	mVectColorProc.clear();
	for (auto & color : vectColor) {
		mVectColorProc.push_back(color);
	}
}

void ProcessImageEngine::createStringResults(std::vector<int> const &vectResults)
{
	int total{};
	for (auto & blobsSize : vectResults) {
		total += blobsSize;
	}
	startResult = QString::fromLatin1("Il y a présentement ") + QString::number(total) + QString::fromLatin1(" smarties de détecter \n");
	restResult = "";
	int index{};
	for (auto & blobsSize : vectResults) {
		//J'ai insérer des espaces intensionnellement, le \t fesait que tout était trop décaler
		restResult += "   " + QString::number(blobsSize) + " smartie(s) " + mColorStringnify[mVectColorProc[index].tag()] + "\n";
		++index;
	}

	emit smarthiesReplied(startResult + restResult);
}

void ProcessImageEngine::addBackgroundImage(img_t const & image)
{
	mBackgroundSaver.push_back(image.copy());
}

void ProcessImageEngine::setColorToProcess(std::vector<int> vectColor)
{
	mVectColorProc.resize(vectColor.size());

}

void ProcessImageEngine::setImgOriginal(img_t const & image)
{
	mImgOriginal = image;
}

img_t & ProcessImageEngine::imgOriginal() 
{
	return mImgOriginal;
}

img_t const & ProcessImageEngine::lightCard() const
{
	return mLightCard;
}

img_t & ProcessImageEngine::imgResults()
{
	return mManipOne;
}

void ProcessImageEngine::createLightCard(img_t const & image)
{
	int height{ image.height() };
	int width{ image.width() };

	mLightCard = img_t(width, height, img_t::Format_ARGB32);

	unsigned char whitePix{ 255 };
	int * curPix{ (int*)(mLightCard.bits()) };
	int * endPix{ curPix + (width * height) };

	while (curPix < endPix) {

		*curPix = (whitePix << 16) |
			(whitePix << 8) |
			(whitePix << 0) |
			0xFF'00'00'00;

		++curPix;
	}
}

void ProcessImageEngine::imageToShow(img_t const &image)
{
	emit showImage(image);
}

void ProcessImageEngine::imageProcessedReceiver(img_t const & image)
{
	mImageProcessed = image;
}

void ProcessImageEngine::lightCardReceiver(img_t const & image)
{
	mLightCard = image;
}

