#ifndef BLACKSMITHLAYER_H_
#define BLACKSMITHLAYER_H_

#include "cocos2d.h" 
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "SceneManager.h"
#include "Constant.h"
class Block;
class Mould;
class BlockMatrix;
USING_NS_CC;
using namespace ui;

class BlackSmithLayer : public Layer
{
public:
	BlackSmithLayer();
	~BlackSmithLayer();
public:
	SceneManager* sm;
public:
	virtual bool init();
	CREATE_FUNC(BlackSmithLayer);
public:
	void initBlock();
	void initBKLayer();
	void initClickEvent();
	void initMould();
	void initMouldEvent();
	void moveDownMould();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
private:
	EventListenerTouchOneByOne* mouldListener;
	BlockMatrix* blockMatrix;
	Mould* mould;
	Sprite* cursor;
	Sprite* mouldBlock3;
	Sprite* mouldBlock2;
	int mouldType[3] ;
};

#endif