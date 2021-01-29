#include "Color.h"

Color::Color(uint8_t minC0, uint8_t maxC0, uint8_t minC1, uint8_t maxC1, uint8_t minC2, uint8_t maxC2, int tag)
{
	mMinChanel0 = minC0;
	mMinChanel1 = minC1;
	mMinChanel2 = minC2;

	mMaxChanel0 = maxC0;
	mMaxChanel1 = maxC1;
	mMaxChanel2 = maxC2;

	mTag = tag;
}

uint8_t Color::minChanel0() const
{
	return mMinChanel0;
}

uint8_t Color::minChanel1() const
{
	return mMinChanel1;
}

uint8_t Color::minChanel2() const
{
	return mMinChanel2;
}

uint8_t Color::maxChanel0() const
{
	return mMaxChanel0;
}

uint8_t Color::maxChanel1() const
{
	return mMaxChanel1;
}

uint8_t Color::maxChanel2() const
{
	return mMaxChanel2;
}

void Color::setChanel0(uint8_t minC0, uint8_t maxC0)
{
	mMinChanel0 = minC0;
	mMaxChanel0 = maxC0;
}

void Color::setChanel1(uint8_t minC1, uint8_t maxC1)
{
	mMinChanel1 = minC1;
	mMaxChanel1 = maxC1;
}

void Color::setChanel2(uint8_t minC2, uint8_t maxC2)
{
	mMinChanel2 = minC2;
	mMaxChanel2 = maxC2;
}

void Color::setAllChanels(uint8_t minC0, uint8_t maxC0, uint8_t minC1, uint8_t maxC1, uint8_t minC2, uint8_t maxC2)
{
	mMinChanel0 = minC0;
	mMaxChanel0 = maxC0;

	mMinChanel1 = minC1;
	mMaxChanel1 = maxC1;

	mMinChanel2 = minC2;
	mMaxChanel2 = maxC2;
}

int Color::tag() const
{
	return mTag;
}


