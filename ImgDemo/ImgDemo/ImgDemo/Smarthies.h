#ifndef SMARTHIES_H
#define SMARTHIES_H

class Smarthies
{
public:

	static int getMinPerimeter();
	static int getMaxPerimeter();
	static int getMinDiameter();
	static int getMaxDiameter();
	static int getMinAire();
	static int getMaxAire();

private:
	Smarthies() = default;
	~Smarthies() = default;

	static const int minPerimeter{};
	static const int maxPerimeter{};
	static const int minDiametre{};
	static const int maxDiametre{};
	static const int minAire{ 40 };
	static const int maxAire{250};
};

#endif // SMARTHIES_H