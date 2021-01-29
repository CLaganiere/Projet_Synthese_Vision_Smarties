#ifndef FILE_IMAGE_SAVER_H
#define FILE_IMAGE_SAVER_H

#include <QLabel>
#include <QDateTime>
#include <QTimeEdit>
#include <QFile>
#include <QTextStream>

#include "Color.h"

class FileImageSaver : public QObject
{
	Q_OBJECT

public:
	FileImageSaver(QObject * parent = nullptr);
	~FileImageSaver()override = default;

public slots:
	void saveImage(QImage const & image);
	void saveLightCard(QImage const & image);
	void saveImageDebug(QImage const & image);
	void saveDataDebug(std::vector<Color> &vectColor);

};
#endif // FILE_IMAGE_SAVER_H