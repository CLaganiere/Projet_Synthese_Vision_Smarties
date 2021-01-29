#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include "IncludeManager.h"

struct Data_Proc {
	EmbeddedProc * process;
	std::vector<img_t*> *inputImg;
	std::vector<img_t*> *outputImg;
};

class ProcessManager: public QObject
{
	Q_OBJECT
public:
	ProcessManager(QObject *parent = nullptr);
	~ProcessManager()override = default;

	void add(EmbeddedProc * process, std::vector<img_t *> *inputImg, std::vector<img_t *> *outputImg);
	void executeSpecificProc(int pos);

	void process();

signals:
	void imgProcessed(img_t const & image);
	void imgFinale(img_t const & image);

private:
	std::list<Data_Proc> mListProcess;
};

#endif // PROCESS_MANAGER_H