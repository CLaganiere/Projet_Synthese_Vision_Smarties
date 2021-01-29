#ifndef FILE_IMAGE_GRABBER_H
#define FILE_IMAGE_GRABBER_H

#include <QLabel>
#include <QFileDialog>
#include <QTimeEdit>
#include <QFile>
#include <QTextStream>

#include "Color.h"

class FileImageGrabber : public QObject
{
	Q_OBJECT

public:
	FileImageGrabber(QObject * parent = nullptr);
	~FileImageGrabber()override = default;

public slots:
	void setImage(QImage const & image);
	void openImage();
	void loadImage();
	void loadColorDebug();

signals:
	void imageLoaded(QImage const & image);
	void colorLoaded(std::vector<Color> const &vectColor);

private:
	QImage importedImage;
	std::vector<Color> inputVectColor;
};
#endif // FILE_IMAGE_GRABBER_H