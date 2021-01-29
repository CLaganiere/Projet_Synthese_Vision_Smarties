#ifndef KERNEL_FILTER_H
#define KERNEL_FILTER_H

#include <vector>
#include <QImage>
#include<cmath>

class KernelFilter
{
public:
	KernelFilter();
	KernelFilter(std::vector <float> const & weightMatrix, int posEvalX, int posEvalY);
	~KernelFilter() = default;

	int sizeMatrix() const;
	int widthKernel() const;
	
	int posToEval() const;
	int posToEvalX() const;
	int posToEvalY() const;
	int notEvalBorder() const;

	float weightMatrix(int posX, int posY) const;
	void setEachPositionValue(int const image);
	void setKernelValue(int sizeKernel, int conv);

	std::pair<int, float> const & operator[](int index)const;

private:
	int mWidthKernel;
	float mSizeKernel;
	int mPosToEvalX;
	int mPosToEvalY;
	int widthImage;
	std::vector <double> mWeightMatrix;
	std::vector<std::pair<int, double>> mValPosition;
};

#endif // KERNEL_FILTER_H

