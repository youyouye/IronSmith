#ifndef TILTMOULD_H_
#define TILTMOULD_H_
#include "cocos2d.h"
#include "Constant.h"
#include "Mould.h"
USING_NS_CC;

class TiltMould : public Mould
{
public:
	TiltMould();
	~TiltMould();
public:
	static TiltMould* create();
	bool init();
	Sprite* getMouldSprite();
	void generateMineralMould(int type);
public:
	CC_SYNTHESIZE(Sprite*,_tiltMouldSprite,TiltMouldSprite);
	CC_SYNTHESIZE(int, _mouldMineralType, MouldMineralType);

};

#endif