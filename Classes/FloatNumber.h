#ifndef FOLATNUMBER_H_
#define FOLATNUMBER_H_

#include "cocos2d.h"
USING_NS_CC;
class FloatNumber : public Node
{
public:
	FloatNumber();
	~FloatNumber();
public:
	static FloatNumber* create(int number,const int fontSize,Point begin);
	bool init(int number, const int fontSize, Point begin);
	void floatIn();
private:
	int _fontSize;
	Point _begin;
	Label* _label;
};

#endif