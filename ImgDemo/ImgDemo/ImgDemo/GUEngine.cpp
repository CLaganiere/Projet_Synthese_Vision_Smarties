#include "GUEngine.h"
#include <QCameraInfo>
#include <QVBoxLayout>
#include "QSimpleImageGrabber.h"

#include <algorithm>
#include <QMessageBox>


GUEngine::GUEngine(QWidget *parent)
	: QMainWindow(parent),
	mOptionWebCam{ new QPushButton(QString::fromLatin1("Prendre une image avec la caméra")) },
	mOptionDoc{ new QPushButton(QString::fromLatin1("Choisir une image déjà existante")) },
	mOptionRetour{ new QPushButton(QString::fromLatin1("Retour à la page précédente")) },
	mConnectButton{ new QPushButton("Connecter") },
	mDisconnectButton{ new QPushButton(QString::fromLatin1("Déconnecter")) },
	mCaptureOneButton{ new QPushButton("Capturer une image") },
	mCaptureContinuouslyButton{ new QPushButton("Capture en continue") },
	mOpionSave{new  QPushButton("Sauvegarder l'image") },
	mCaptureBckgButton{ new QPushButton("Capturer une image") },
	mProcessLightCard{ new QPushButton(QString::fromLatin1("Créer la carte d'éclairage")) },
	mOpionSaveLightCard{ new QPushButton("Sauvegarder la carte") },	
	mOptionLightCard{ new QPushButton(QString::fromLatin1("Construire la carte d'éclairage")) },
	mOptionProcImg{ new QPushButton("Analyser une image") },
	mChooseImage{ new QPushButton("Importer une image")},
	mLoadPredefinedImage{ new QPushButton(QString::fromLatin1("Ouvrir une image prédéfini"))},
	mInputImage{ new QSimpleImageViewer },
	mProcessedImage{ new QSimpleImageViewer },
	mCapturingContinuously{ false },
	mOptionDebug{new QPushButton(QString::fromLatin1("Mode de débuggage")) }, 
	mOpionSaveDebug{new  QPushButton(QString::fromLatin1("Sauvegarder l'image de débug")) },
	mOpionSaveDataDebug{new  QPushButton(QString::fromLatin1("Sauvegarder les données des couleurs")) },
	checkBtnBlue{ new QCheckBox("Bleu")},
	checkBtnGreen{ new QCheckBox("Vert") },
	checkBtnBrown{ new QCheckBox("Brun") },
	checkBtnOrange{ new QCheckBox("Orange") },
	checkBtnPink{ new QCheckBox("Rose") },
	checkBtnPurple{ new QCheckBox("Mauve") },
	checkBtnRed{ new QCheckBox("Rouge") },
	checkBtnYellow{ new QCheckBox("Jaune") },
	hsvIntervals{ new QNIntervalScrollBar(3) },
	progressBar{ new QProgressBar()}, 
	progressBarDebugPrep{ new QProgressBar()},
	AnswerLabel{new QLabel("Calcul en cours...")},
	buttonColorGroup{new QButtonGroup()}
{
	ui.setupUi(this);

	progressBar->setOrientation(Qt::Horizontal);
	progressBar->setRange(0, 100);
	progressBar->setValue(0);
	
	progressBarDebugPrep->setOrientation(Qt::Horizontal);
	progressBarDebugPrep->setRange(0, 100);
	progressBarDebugPrep->setValue(0);

	QFont font = AnswerLabel->font();
	font.setPointSize(9);
	AnswerLabel->setFont(font);

	mOptionWebCam->setMinimumHeight(200);
	mOptionDoc->setMinimumHeight(200);
	mConnectButton->setMaximumWidth(200);
	mDisconnectButton->setMaximumWidth(200);
	mCaptureOneButton->setMaximumWidth(200);
	mCaptureContinuouslyButton->setMaximumWidth(200);
	mOpionSave->setMaximumWidth(200);
	mOptionRetour->setMaximumWidth(200);
	mChooseImage->setMaximumWidth(200);
	mLoadPredefinedImage->setMaximumWidth(200);
	mCaptureBckgButton->setMaximumWidth(200);
	mProcessLightCard->setMaximumWidth(200);
	mOpionSaveLightCard->setMaximumWidth(200);
	mOptionLightCard->setMaximumWidth(200);
	mOptionProcImg->setMaximumWidth(200);
	mOptionDebug->setMaximumWidth(200);
	AnswerLabel->setMaximumWidth(200);
	mOpionSaveDebug->setMaximumWidth(200);
	mOpionSaveDataDebug->setMaximumWidth(200);

	//Check box
	checkBtnBlue->setMaximumWidth(75);
	checkBtnGreen->setMaximumWidth(75);
	checkBtnBrown->setMaximumWidth(75);
	checkBtnOrange->setMaximumWidth(75);
	checkBtnPink->setMaximumWidth(75);
	checkBtnPurple->setMaximumWidth(75);
	checkBtnRed->setMaximumWidth(75);
	checkBtnYellow->setMaximumWidth(75);
	
	mOptionWebCam->setMinimumHeight(50);
	mOptionDoc->setMinimumHeight(50);
	mConnectButton->setMinimumHeight(50);
	mDisconnectButton->setMinimumHeight(50);
	mCaptureOneButton->setMinimumHeight(50);
	mCaptureContinuouslyButton->setMinimumHeight(50);
	mOpionSave->setMinimumHeight(50);
	mOptionRetour->setMinimumHeight(50);
	mChooseImage->setMinimumHeight(50);
	mLoadPredefinedImage->setMinimumHeight(50);
	mCaptureBckgButton->setMinimumHeight(50);
	mProcessLightCard->setMinimumHeight(50);
	mOpionSaveLightCard->setMinimumHeight(50);
	mOptionLightCard->setMinimumHeight(50);
	mOptionProcImg->setMinimumHeight(50);
	mOptionDebug->setMinimumHeight(50);
	mOpionSaveDebug->setMinimumHeight(50);
	mOpionSaveDataDebug->setMinimumHeight(50);
	AnswerLabel->setMaximumHeight(50);
	progressBar->setMinimumHeight(20);
	progressBarDebugPrep->setMinimumHeight(20);

	//Check box
	checkBtnBlue->setMinimumHeight(25);
	checkBtnGreen->setMinimumHeight(25);
	checkBtnBrown->setMinimumHeight(25);
	checkBtnOrange->setMinimumHeight(25);
	checkBtnPink->setMinimumHeight(25);
	checkBtnPurple->setMinimumHeight(25);
	checkBtnRed->setMinimumHeight(25);
	checkBtnYellow->setMinimumHeight(25);

	buttonColorGroup->addButton(checkBtnBlue);
	buttonColorGroup->addButton(checkBtnGreen);
	buttonColorGroup->addButton(checkBtnBrown);
	buttonColorGroup->addButton(checkBtnOrange);
	buttonColorGroup->addButton(checkBtnPink);
	buttonColorGroup->addButton(checkBtnPurple);
	buttonColorGroup->addButton(checkBtnRed);
	buttonColorGroup->addButton(checkBtnYellow);
	buttonColorGroup->setExclusive(true);
	checkBtnBlue->setChecked(true);

	auto setupInterval{ [](QNIntervalScrollBar * i, QVector<QString> const & titles) {
		i->setMinimumWidth(250);
		i->setMaximumWidth(600);
		i->setMaximumHeight(250);
		i->setTitle(titles, 55);
		i->setRange(0, 255);
		i->setIntervalToRange();
	} };
	setupInterval(hsvIntervals, { "Hue", "Saturation", "Value" });

	QHBoxLayout * hLayoutCheckBtn{ new QHBoxLayout };
	QVBoxLayout * vLayoutCheckBtnOne{ new QVBoxLayout };
	QVBoxLayout * vLayoutCheckBtnTwo{ new QVBoxLayout };

	vLayoutCheckBtnOne->addWidget(checkBtnBlue);
	vLayoutCheckBtnOne->addWidget(checkBtnGreen);
	vLayoutCheckBtnOne->addWidget(checkBtnBrown);
	vLayoutCheckBtnOne->addWidget(checkBtnOrange);

	vLayoutCheckBtnTwo->addWidget(checkBtnPink);
	vLayoutCheckBtnTwo->addWidget(checkBtnPurple);
	vLayoutCheckBtnTwo->addWidget(checkBtnRed);
	vLayoutCheckBtnTwo->addWidget(checkBtnYellow);
	
	hLayoutCheckBtn->addLayout(vLayoutCheckBtnOne);
	hLayoutCheckBtn->addLayout(vLayoutCheckBtnTwo);

	QVBoxLayout * vLayoutOne{ new QVBoxLayout };
	vLayoutOne->addWidget(mOptionWebCam);
	vLayoutOne->addWidget(mOptionDoc);
	vLayoutOne->addWidget(mOptionDebug);

	vLayoutOne->addWidget(mChooseImage);
	vLayoutOne->addWidget(mLoadPredefinedImage);

	vLayoutOne->addWidget(mConnectButton);
	vLayoutOne->addWidget(mDisconnectButton);
	vLayoutOne->addWidget(mCaptureOneButton);
	vLayoutOne->addWidget(mCaptureContinuouslyButton);
	vLayoutOne->addWidget(mOpionSave);

	vLayoutOne->addWidget(mCaptureBckgButton);
	vLayoutOne->addWidget(mProcessLightCard);
	vLayoutOne->addWidget(mOpionSaveLightCard);

	vLayoutOne->addWidget(mOptionLightCard);
	vLayoutOne->addWidget(mOptionProcImg);

	vLayoutOne->addWidget(mOpionSaveDebug);
	vLayoutOne->addWidget(mOpionSaveDataDebug);

	vLayoutOne->addWidget(hsvIntervals);
	vLayoutOne->addWidget(AnswerLabel);
	
	vLayoutOne->addLayout(hLayoutCheckBtn);
	vLayoutOne->addWidget(mOptionRetour);

	QVBoxLayout * vLayoutTwo{ new QVBoxLayout };
	vLayoutTwo->addWidget(mInputImage);
	vLayoutTwo->addWidget(mProcessedImage);
	vLayoutTwo->addWidget(progressBar);
	vLayoutTwo->addWidget(progressBarDebugPrep);

	QHBoxLayout * hLayoutOne{ new QHBoxLayout };
	hLayoutOne->addLayout(vLayoutOne);
	hLayoutOne->addLayout(vLayoutTwo);

	QWidget * centralWidget{ new QWidget };
	centralWidget->setLayout(hLayoutOne);

	setCentralWidget(centralWidget);

	connect(mOptionLightCard, &QPushButton::clicked, this, &GUEngine::lightCardChoice);
	connect(mOptionProcImg, &QPushButton::clicked, this, &GUEngine::processImageChoice);

	connect(mOptionWebCam, &QPushButton::clicked, this, &GUEngine::webCamChoice);
	connect(mOptionDoc, &QPushButton::clicked, this, &GUEngine::docCamChoice);
	connect(mOptionDebug, &QPushButton::clicked, this, &GUEngine::debugChoice);

	//Retour au menu principale
	connect(mOptionRetour, &QPushButton::clicked, this, &GUEngine::principalMenuChoice);

	//	Caméra	------------------
	//Connection à la caméra
	connect(mConnectButton, &QPushButton::clicked, this, &GUEngine::connectCamera);
	
	//Déconnection à la caméra
	connect(mDisconnectButton, &QPushButton::clicked, this, &GUEngine::disconnectCamera);
	
	//Capture d'une image
	connect(mCaptureOneButton, &QPushButton::clicked, this, &GUEngine::captureOne);
	
	//Set de la capture d'image en continu
	connect(mCaptureContinuouslyButton, &QPushButton::clicked, this, &GUEngine::captureContinuously);
	
	//Affiche l'image capturer
	connect(&mWebCamGrabber, &WebCamGrabber::imageCaptured, mInputImage, &QSimpleImageViewer::setImage);

	//Process l'image aquisitionner
	connect(&mWebCamGrabber, &WebCamGrabber::imageCaptured, this, &GUEngine::dispatcher);
	
	//Prêt à prendre une autre image
	connect(&mWebCamGrabber, &WebCamGrabber::readyForCaptureChanged, this, &GUEngine::processReadyToCapture);
	//	-----

	//Connection a process add Image to LightCard process
	connect(mCaptureBckgButton, &QPushButton::clicked, this, &GUEngine::captureOne);

	//Connection a process LightCard
	connect(mProcessLightCard, &QPushButton::clicked, &mProcessEngine, &ProcessImageEngine::processLightCard);

	//	Fichier externe	--------------
	//	Acquisition d'image de l'ordinateur
	connect(mChooseImage, &QPushButton::clicked, this, &GUEngine::openImage);
	connect(mLoadPredefinedImage, &QPushButton::clicked, this, &GUEngine::loadOne);
	
	//Affiche l'image capturer
	connect(&mFileImageGrabber, &FileImageGrabber::imageLoaded, mInputImage, &QSimpleImageViewer::setImage);
	connect(&mFileImageGrabber, &FileImageGrabber::imageLoaded, this, &GUEngine::processNormal);
	
	//Connection avec ProcessImageEngine pour afficher les images résultantes des process
	connect(&mProcessEngine, &ProcessImageEngine::showImage, mProcessedImage, &QSimpleImageViewer::setImage);
	connect(&mProcessEngine, &ProcessImageEngine::showImage, this, &GUEngine::processEnded);

	//Preparation du debug
	connect(&mProcessEngine, &ProcessImageEngine::debugPrepared, this, &GUEngine::debugPreparation);

	//Sauvegarde d'une image
	connect(mOpionSave, &QPushButton::clicked, &mProcessEngine, &ProcessImageEngine::getImageProcessed);
	connect(&mProcessEngine, &ProcessImageEngine::imageProcessed, &mFileImageSaver, &FileImageSaver::saveImage);

	//Sauvegarde de la carte d'éclairage
	connect(mOpionSaveLightCard, &QPushButton::clicked, &mProcessEngine, &ProcessImageEngine::getLightCard);
	connect(&mProcessEngine, &ProcessImageEngine::imageLightCard, &mFileImageSaver, &FileImageSaver::saveLightCard);
	
	//Sauvegarde d'une image en mode debug
	connect(mOpionSaveDebug, &QPushButton::clicked, &mProcessEngine, &ProcessImageEngine::getImageDebug);
	connect(&mProcessEngine, &ProcessImageEngine::imageDebug, &mFileImageSaver, &FileImageSaver::saveImageDebug);

	connect(mOpionSaveDataDebug, &QPushButton::clicked, &mProcessEngine, &ProcessImageEngine::getVectColorDebug);
	connect(&mProcessEngine, &ProcessImageEngine::colorFromDebug, &mFileImageSaver, &FileImageSaver::saveDataDebug);

	//Connect la phrase résiultante à l'affichage	
	connect(&mProcessEngine, &ProcessImageEngine::smarthiesReplied, this, &GUEngine::setResultText);

	//Connection a file GRABBER au set vector color
	connect(&mFileImageGrabber, &FileImageGrabber::colorLoaded, &mProcessEngine, &ProcessImageEngine::setVectColorProc);

	//Connection des couleurs
	connect(checkBtnBlue,	&QCheckBox::clicked, this, &GUEngine::colorDispatcher);
	connect(checkBtnGreen,	&QCheckBox::clicked, this, &GUEngine::colorDispatcher);
	connect(checkBtnBrown,	&QCheckBox::clicked, this, &GUEngine::colorDispatcher);
	connect(checkBtnOrange, &QCheckBox::clicked, this, &GUEngine::colorDispatcher);
	connect(checkBtnPink,	&QCheckBox::clicked, this, &GUEngine::colorDispatcher);
	connect(checkBtnPurple, &QCheckBox::clicked, this, &GUEngine::colorDispatcher);
	connect(checkBtnRed,	&QCheckBox::clicked, this, &GUEngine::colorDispatcher);
	connect(checkBtnYellow, &QCheckBox::clicked, this, &GUEngine::colorDispatcher);

	modificationMenu();
	updateGui();
}

void GUEngine::principalMenuChoice() {
	if (menu >= 1 && menu <= 5 && mWebCamGrabber.isConnected()) {
		disconnectCamera();
		mInputImage->clear();
		mProcessedImage->clear();
	}

	if (menu > 1 && menu < 4) {
		menu = 1;
		processCountLightCard = 0;
		processCount = 0;
		progressBar->setValue(processCountLightCard);
	}
	else {
		menu = 0;
	}

	modificationMenu();
}

void GUEngine::webCamChoice() {
	menu = 1;
	modificationMenu();
}

void GUEngine::lightCardChoice() {
	menu = 2;
	modificationMenu();
}

void GUEngine::processImageChoice() {
	menu = 3;
	modificationMenu();
}

void GUEngine::docCamChoice()
{
	menu = 4;
	modificationMenu();
}

void GUEngine::debugChoice()
{
	menu = 5;
	modificationMenu();
}

void GUEngine::connectCamera()
{
	mWebCamGrabber.connect();
	updateGui();
}

void GUEngine::disconnectCamera()
{
	mWebCamGrabber.disconnect();
	updateGui();
}

void GUEngine::captureOne()
{
	processCountLightCard = 0;
	progressBar->setValue(processCountLightCard);
	mWebCamGrabber.capture();
	updateGui();
}

void GUEngine::loadOne()
{
	mFileImageGrabber.loadImage();
	updateGui();
}

void GUEngine::captureContinuously()
{
	mCapturingContinuously = !mCapturingContinuously;
	mWebCamGrabber.capture();
	updateGui();
}

void GUEngine::processReadyToCapture(bool ready)
{
	if (ready && mCapturingContinuously) {
		mWebCamGrabber.capture();
	}
}

void GUEngine::processEnded()
{
	if (menu == 2) {
		++processCountLightCard;
		progressBar->setValue(processCountLightCard*20);
	}
}

void GUEngine::debugPreparation()
{
	++debugPrepState;
	progressBarDebugPrep->setValue(debugPrepState*20);
}

void GUEngine::colorDispatcher()
{
	if (checkBtnBlue->isChecked()) {
		currentColorDebug = 0;
	}
	else if (checkBtnGreen->isChecked()) {
		currentColorDebug = 1;
	}
	else if (checkBtnBrown->isChecked()) {
		currentColorDebug = 2;
	}
	else if (checkBtnOrange->isChecked()) {
		currentColorDebug = 3;
	}
	else if (checkBtnPink->isChecked()) {
		currentColorDebug = 4;
	}
	else if (checkBtnPurple->isChecked()) {
		currentColorDebug = 5;
	}
	else if (checkBtnRed->isChecked()) {
		currentColorDebug = 6;
	}
	else if (checkBtnYellow->isChecked()) {
		currentColorDebug = 7;
	}
	mProcessEngine.changeDebugColor(currentColorDebug);
}

void GUEngine::modificationMenu() {
	if (menu == 0) {
		// Menu de départ 
		mOptionWebCam->show();
		mOptionDoc->show();
		mOptionDebug->show();
		mChooseImage->hide();
		mLoadPredefinedImage->hide();

		mOptionLightCard->hide();
		mOptionProcImg->hide();

		hsvIntervals->hide();

		mConnectButton->hide();
		mDisconnectButton->hide();
		mCaptureOneButton->hide();
		mCaptureOneButton->hide();
		mCaptureContinuouslyButton->hide();
		mOpionSave->hide();
		mCaptureBckgButton->hide();
		mProcessLightCard->hide();
		mOpionSaveLightCard->hide();
		mOptionRetour->hide();
		AnswerLabel->hide();
		progressBar->hide();
		progressBarDebugPrep->hide();
		mOpionSaveDebug->hide();
		mOpionSaveDataDebug->hide();

		checkBtnBlue->hide();
		checkBtnGreen->hide();
		checkBtnBrown->hide();
		checkBtnOrange->hide();
		checkBtnPink->hide();
		checkBtnPurple->hide();
		checkBtnRed->hide();
		checkBtnYellow->hide();

		mInputImage->clear();
		mProcessedImage->clear();
	}
	else if (menu == 1) {
		// Menu de choix de capture d'image
		mOptionWebCam->hide();
		mOptionDoc->hide();
		mOptionDebug->hide();

		mOptionLightCard->show();
		mOptionProcImg->show();

		mConnectButton->hide();
		mDisconnectButton->hide();
		mCaptureOneButton->hide();
		mCaptureContinuouslyButton->hide();
		mOpionSave->hide();
		mCaptureBckgButton->hide();
		mProcessLightCard->hide();
		mOpionSaveLightCard->hide();
		AnswerLabel->hide();
		progressBar->hide();

		mOptionRetour->show();
	}
	else if (menu == 2) {
		// Menu de carte d'éclairage
		mOptionLightCard->hide();
		mOptionProcImg->hide();

		mConnectButton->show();
		mDisconnectButton->show();
		mCaptureBckgButton->show();
		mProcessLightCard->show();
		mOpionSaveLightCard->show();
		mOptionRetour->show();
		progressBar->show();
		AnswerLabel->hide();

	}
	else if (menu == 3) {
		// Menu de process d'image
		mOptionLightCard->hide();
		mOptionProcImg->hide();

		mConnectButton->show();
		mDisconnectButton->show();
		mCaptureOneButton->show();
		mCaptureContinuouslyButton->show();
		mOpionSave->show();
		AnswerLabel->show();

		mOptionRetour->show();
	}
	else if (menu == 4){
		// Menu de sélection d'image à
		// partir de l'explorateur des fichiers
		mOptionWebCam->hide();
		mOptionDoc->hide();
		mOptionDebug->hide();

		mChooseImage->show();
		mLoadPredefinedImage->show();
		AnswerLabel->show();
		mOptionRetour->show();
	}
	else {
		//	Menu de débuggage
		mOptionWebCam->hide();
		mOptionDoc->hide();
		mOptionDebug->hide();

		mConnectButton->show();
		mDisconnectButton->show();
		mCaptureOneButton->show();
		mCaptureContinuouslyButton->show();
		mOpionSaveDataDebug->show();
		mOpionSaveDebug->show();
		progressBarDebugPrep->show();

		checkBtnBlue->show();
		checkBtnGreen->show();
		checkBtnBrown->show();
		checkBtnOrange->show();
		checkBtnPink->show();
		checkBtnPurple->show();
		checkBtnRed->show();
		checkBtnYellow->show();

		hsvIntervals->show();

		mOptionRetour->show();
	}
}

void GUEngine::updateGui()
{
	bool cameraConnected{ mWebCamGrabber.isConnected() };
	mConnectButton->setEnabled(!cameraConnected);
	mDisconnectButton->setEnabled(cameraConnected);
	mCaptureOneButton->setEnabled(cameraConnected && !mCapturingContinuously);
	mCaptureContinuouslyButton->setEnabled(cameraConnected);
	mOpionSave->setEnabled(cameraConnected);
	mCaptureContinuouslyButton->setText(mCapturingContinuously ? QString::fromLatin1("Arrêter la capture en continue") : "Capture en continue");
	mOpionSave->setEnabled(cameraConnected);

	mCaptureBckgButton->setEnabled(cameraConnected);
	mProcessLightCard->setEnabled(cameraConnected);
	mOpionSaveLightCard->setEnabled(cameraConnected);
	mOpionSaveDebug->setEnabled(cameraConnected);
	mOpionSaveDataDebug->setEnabled(cameraConnected);

	checkBtnBlue->setEnabled(cameraConnected);
	checkBtnGreen->setEnabled(cameraConnected);
	checkBtnBrown->setEnabled(cameraConnected);
	checkBtnOrange->setEnabled(cameraConnected);
	checkBtnPink->setEnabled(cameraConnected);
	checkBtnPurple->setEnabled(cameraConnected);
	checkBtnRed->setEnabled(cameraConnected);
	checkBtnYellow->setEnabled(cameraConnected);
}

void GUEngine::processNormal(img_t const & image)
{
	if (mFirstProcess) {
		mFileImageGrabber.loadColorDebug();
		mProcessEngine.prepareProcess(image);
		mFirstProcess = false;
	}

	if (menu == 2) {
		mProcessEngine.addBackgroundImage(image);
	}
	else {
		mProcessEngine.processImage(image);
	}
}

void GUEngine::processDebug(img_t const & image)
{
	if (mFirstDebug) {
		mProcessEngine.prepareDebug(image);
		mFirstDebug = false;
	}

	mProcessEngine.debugProcess(image,
		hsvIntervals->interval(0).lower(), hsvIntervals->interval(0).upper(),
		hsvIntervals->interval(1).lower(), hsvIntervals->interval(1).upper(),
		hsvIntervals->interval(2).lower(), hsvIntervals->interval(2).upper());
}

void GUEngine::dispatcher(img_t const & image)
{
	if (menu == 5) {
		processDebug(image);
	}
	else {
		processNormal(image);
	}
}

void GUEngine::setResultText(QString message)
{
	AnswerLabel->setText(message);
}

void GUEngine::openImage()
{
	QString filename(QFileDialog::getOpenFileName(this, "Choissisez une image", "/home/", tr("Image Files (*.png *.jpg *.bmp)")));

	if (!filename.isEmpty()) {
		QImage importImage;
		importImage.load(filename);
		if (importImage.isNull()) {
			QMessageBox::information(this, "Load image", "The specified image is invalid.");
		}
		else {
			importImage = importImage.scaled(importImage.width() / 3.5, importImage.height() / 3.5);
			mInputImage->setImage(importImage);
			processNormal(importImage);
		}
	}
}