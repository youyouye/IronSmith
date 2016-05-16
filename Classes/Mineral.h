#ifndef MINERAL_H_
#define MINERAL_H_
#include "cocos2d.h"
#include "Constant.h"
USING_NS_CC;

class Mineral : public Node
{
public:
	Mineral();
	~Mineral();
public:
	static Mineral* create(int type);
	bool init(int type);
public:
	CC_SYNTHESIZE(Sprite*,_mineralSprite,MineralSprite);
	CC_SYNTHESIZE(int,_mineralType,MineralType);
public:
	void changeMineralType(int type);
};

#endif