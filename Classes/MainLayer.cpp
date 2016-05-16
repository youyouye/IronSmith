#include "MainLayer.h"
#include "Constant.h"

MainLayer::MainLayer()
{
}


MainLayer::~MainLayer()
{
}
bool MainLayer::init()
{
	if (!Layer::init())
	{
		return false;

	}
	Size visibleSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	CCLOG("Size:%f,%f",visibleSize.width,visibleSize.height);
	CCLOG("Point:%f,%f",origin.x,origin.y);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MainLayer::onClickToStart, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}
bool MainLayer::onClickToStart(Touch* touch, Event* event)
{
	sm->goBlackSmithScene();
	return true;
}
