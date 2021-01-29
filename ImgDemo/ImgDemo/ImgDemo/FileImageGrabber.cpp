#include "FileImageGrabber.h"

FileImageGrabber::FileImageGrabber(QObject * parent)
	: QObject(parent)
{

}

void FileImageGrabber::openImage()
{
	//QString filename(QFileDialog::getOpenFileName(this, "Select image to load", "/home/", tr("Image Files (*.png *.jpg *.bmp)")));

	//if (!filename.isEmpty()) {
	//	loadImage(filename);
	//}
}

void FileImageGrabber::loadImage()
{
	importedImage.load("D:\\Donnees\\ImagesSmarties\\Smarties_Level1_04.JPG");

	if (importedImage.format() == QImage::Format_Invalid) {
		throw std::invalid_argument("Image invalide");
	}

	emit imageLoaded(importedImage.scaled(importedImage.width() / 4, importedImage.height() / 4));
}

void FileImageGrabber::loadColorDebug()
{
	QDateTime liveTime = QDateTime::currentDateTime();
	QFile file("D:\\Donnees\\ImagesSmarties\\data_debug" + liveTime.toString("yyyy-MM-dd") + ".csv");
	if (!file.open(QIODevice::ReadOnly)) {
		return;
	}

	QTextStream input(&file);
	std::vector<int> vectValues;
	vectValues.resize(7);
	while (!input.atEnd())
	{
		QString line = input.readLine();

		int index{};
		for (QString item : line.split(";")) {
			vectValues[index] = item.toInt();
			++index;
		}
		inputVectColor.push_back(Color(vectValues[0], vectValues[1], vectValues[2], vectValues[3], vectValues[4], vectValues[5], vectValues[6]));
	}
	file.close();



	if (inputVectColor.size() > 0) {
		emit colorLoaded(inputVectColor);
	}
}

void FileImageGrabber::setImage(QImage const & image)
{

	QImage myImage;
	myImage = myImage.convertToFormat(QImage::Format_ARGB32);
}
