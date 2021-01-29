#include "ProcessManager.h"



ProcessManager::ProcessManager(QObject *parent)
	:QObject(parent)
{
}

void ProcessManager::add(EmbeddedProc * process, std::vector<img_t *> *inputImg, std::vector<img_t *> *outputImg)
{
	mListProcess.push_back({ process, inputImg, outputImg });
}

void ProcessManager::executeSpecificProc(int pos)
{
	if (pos >= 0 && pos <= mListProcess.size()) {
		int curPos{};
		for (std::list< Data_Proc>::iterator it{ mListProcess.begin() }; it != mListProcess.end(); ++it) {

			if (curPos == pos) {
				*it->outputImg = it->process->perform(*it->inputImg);
				emit  imgProcessed(*(*it->outputImg)[0]);
			}
			++curPos;
		}
	}
}

void ProcessManager::process()
{
	int index{}, sizeList{ static_cast<int>(mListProcess.size())-1 };
	for (std::list< Data_Proc>::iterator it{ mListProcess.begin() }; it != mListProcess.end(); ++it) {
		
		*it->outputImg = it->process->perform(*it->inputImg);

		emit  imgProcessed(*(*it->outputImg)[0]);

		if (index == sizeList) {
			int a = it->outputImg->size();
			emit  imgFinale(*(*it->outputImg)[0]);
		}
		++index;
	}
}



