#include "GUEngine.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling, true);
	QApplication a(argc, argv);
	GUEngine w;
	w.setWindowTitle(QString::fromLatin1("Détecteur de smarties"));
	w.show();
	return a.exec();
}
