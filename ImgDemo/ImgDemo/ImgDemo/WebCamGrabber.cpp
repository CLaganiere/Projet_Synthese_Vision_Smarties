#include "WebCamGrabber.h"

WebCamGrabber::WebCamGrabber(QObject * parent)
	: QObject(parent)
{
	mCamera = new QCamera(this);
	mCamera->setCaptureMode(QCamera::CaptureStillImage);

	mCameraImageCapture = new QCameraImageCapture(mCamera, this);
	mCameraImageCapture->setBufferFormat(QVideoFrame::Format_ARGB32);
	mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToBuffer);

	QObject::connect(mCameraImageCapture, &QCameraImageCapture::imageCaptured, [this](int id, const QImage& preview) { emit imageCaptured(preview); });
	QObject::connect(mCameraImageCapture, &QCameraImageCapture::readyForCaptureChanged, this, &WebCamGrabber::readyForCaptureChanged);
}

void WebCamGrabber::connect()
{
	mCamera->start();
	if (mCamera->state() == QCamera::ActiveState) {
		emit connected();
	}
}

void WebCamGrabber::disconnect()
{
	mCamera->stop();
	emit disconnected();
}

bool WebCamGrabber::isConnected() const
{
	return mCamera->state() == QCamera::ActiveState;
}

bool WebCamGrabber::isReady() const
{
	QCamera::State s{ mCamera->state() };
	return mCameraImageCapture->isReadyForCapture();
}

void WebCamGrabber::capture()
{
	mCameraImageCapture->capture();
}
