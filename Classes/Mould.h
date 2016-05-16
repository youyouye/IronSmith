#ifndef MOULD_H_
#define MOULD_H_
#include "cocos2d.h"
USING_NS_CC;
class Mould : public Node
{
public:
	Mould();
	~Mould();
public:
	virtual Sprite* getMouldSprite();
	virtual void generateMineralMould(int type);
};

#endif