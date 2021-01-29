#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

struct Color
{
public:
	Color() = default;
	Color(uint8_t minC0, uint8_t maxC0, uint8_t minC1, uint8_t maxC1, uint8_t minC2, uint8_t maxC2, int tag);
	~Color() = default;

	uint8_t minChanel0() const;
	uint8_t minChanel1() const;
	uint8_t minChanel2() const;

	uint8_t maxChanel0() const;
	uint8_t maxChanel1() const;
	uint8_t maxChanel2() const;

	void setChanel0(uint8_t minC0, uint8_t maxC0);
	void setChanel1(uint8_t minC1, uint8_t maxC1);
	void setChanel2(uint8_t minC2, uint8_t maxC2);

	void setAllChanels(uint8_t minC0, uint8_t maxC0, uint8_t minC1, uint8_t maxC1, uint8_t minC2, uint8_t maxC2);

	int tag() const;

private:

	uint8_t mMinChanel0;
	uint8_t mMinChanel1;
	uint8_t mMinChanel2;
			 
	uint8_t mMaxChanel0;
	uint8_t mMaxChanel1;
	uint8_t mMaxChanel2;

	int mTag;

};

#endif // COLOR_H


