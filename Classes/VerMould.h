#ifndef VERMOULD_H_
#define VERMOULD_H_
#include "cocos2d.h"
#include "Constant.h"
#include "Mould.h"
USING_NS_CC; 

class VerMould : public Mould
{
public:
	VerMould();
	~VerMould();
public:
	static VerMould* create();
	bool init();
	Sprite* getMouldSprite();
	void generateMineralMould(int type);
public:
	CC_SYNTHESIZE(Sprite*,_verMouldSprite,VerMouldSprite);
	CC_SYNTHESIZE(int, _mouldMineralType, MouldMineralType);
};

#endif