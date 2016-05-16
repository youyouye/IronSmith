#include "FloatNumber.h"


FloatNumber::FloatNumber()
{
}


FloatNumber::~FloatNumber()
{
}
FloatNumber* FloatNumber::create(int number, const int fontSize, Point begin)
{
	FloatNumber* ret = new FloatNumber();
	if (ret && ret->init(number, fontSize, begin))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}
bool FloatNumber::init(int number, const int fontSize, Point begin)
{
	_begin = begin;
	char string[12] = {0};
	sprintf(string,"+%d",number);
	_label = Label::create(string,"Verdana-Bold",fontSize);
	_label->setPosition(begin);
	this->addChild(_label);
	return true;
}
void FloatNumber::floatIn()
{
	MoveBy* move = MoveBy::create(0.5f,Vec2(0,100));
	FadeOut* fadeOut = FadeOut::create(1.5f);
	CallFunc* removeC = CallFunc::create([this](){
		this->removeFromParentAndCleanup(true);
	});
	Sequence* action = Sequence::create(move, DelayTime::create(1.0f), removeC,NULL);
	_label->runAction(action);
}