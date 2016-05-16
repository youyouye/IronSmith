#ifndef SQUMOULD_H_
#define SQUMOULD_H_
#include "cocos2d.h"
#include "Constant.h"
#include "Mould.h"
USING_NS_CC;
class SquMould : public Mould
{
public:
	SquMould();
	~SquMould();
public:
	static SquMould* create();
	bool init();
	Sprite* getMouldSprite();
	void generateMineralMould(int type);
public:
	CC_SYNTHESIZE(Sprite*,_squMouldSprite,SquMouldSprite);
	CC_SYNTHESIZE(int,_mouldMineralType,MouldMineralType);
};

#endif