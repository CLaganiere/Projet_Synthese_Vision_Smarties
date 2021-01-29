#ifndef WEB_CAM_H
#define WEB_CAM_H

#include <QCamera>
#include <QCameraImageCapture>

class WebCamGrabber : public QObject
{
	Q_OBJECT

public:
	WebCamGrabber(QObject * parent = nullptr);
	~WebCamGrabber()override = default;

	bool isConnected() const;
	bool isReady() const;

public slots:
	void connect();
	void disconnect();
	void capture();

signals:
	void connected();
	void disconnected();
	void imageCaptured(QImage const & image);
	void readyForCaptureChanged(bool ready);

private:
	QCamera * mCamera;
	QCameraImageCapture * mCameraImageCapture;
};

#endif // WEB_CAM_H