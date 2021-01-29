#include "FileImageSaver.h"

FileImageSaver::FileImageSaver(QObject * parent)
	: QObject(parent)
{
}

void FileImageSaver::saveImage(QImage const & image)
{
	QDateTime liveTime = QDateTime::currentDateTime();

	if (image.format() == QImage::Format_Invalid) {
		throw std::invalid_argument("Image invalide");
	}

	image.save("D:\\Donnees\\ImagesSmarties\\Image_Processed_"+ liveTime.toString("yyyy-MM-dd-HH-mm-ss")+".JPG");
}

void FileImageSaver::saveLightCard(QImage const & image)
{
	QDateTime liveTime = QDateTime::currentDateTime();

	if (image.format() == QImage::Format_Invalid) {
		throw std::invalid_argument("Image invalide");
	}

	image.save("D:\\Donnees\\ImagesSmarties\\Light_Card_Of_Process_" + liveTime.toString("yyyy-MM-dd-HH-mm-ss") + ".JPG");

}

void FileImageSaver::saveImageDebug(QImage const & image)
{
	QDateTime liveTime = QDateTime::currentDateTime();

	if (image.format() == QImage::Format_Invalid) {
		throw std::invalid_argument("Image invalide");
	}

	image.save("D:\\Donnees\\ImagesSmarties\\Image_Debug_" + liveTime.toString("yyyy-MM-dd-HH-mm-ss") + ".JPG");
}

void FileImageSaver::saveDataDebug(std::vector<Color> &vectColor)
{
	QDateTime liveTime = QDateTime::currentDateTime();
	QFile file("D:\\Donnees\\ImagesSmarties\\data_debug"+liveTime.toString("yyyy-MM-dd") + ".csv");
	if (file.open(QFile::WriteOnly | QFile::Truncate))
	{
		QTextStream output(&file);

		for (auto & color : vectColor) {
			output << color.minChanel0() << ";" << color.maxChanel0() << ";"
				<< color.minChanel1() << ";" << color.maxChanel1() << ";"
				<< color.minChanel2() << ";" << color.maxChanel2() << ";"
				<< color.tag() << "\n";
		}
		file.close();
	}

}
