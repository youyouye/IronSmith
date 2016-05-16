#include "StartLayer.h"
#include "Constant.h"
using namespace std;
StartLayer::StartLayer(void)
{
}


StartLayer::~StartLayer(void)
{
}

bool StartLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	CCLOG("Size£º%d,%d",visibleSize.width,visibleSize.height);
	CCLOG("Origin£º%d,%d",origin.x,origin.y);
	initTexture();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(StartLayer::onClickToStart, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}
void StartLayer::backMusic()
{
	
}
void StartLayer::gotoMainGame(float ft)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	sm->goMainScene();
}
void StartLayer::initTexture()
{
	Director::getInstance()->getTextureCache()->addImage(TILE_NORMAL);
	Director::getInstance()->getTextureCache()->addImage(TILE_BURNT);
	Director::getInstance()->getTextureCache()->addImage(TILE_MAGIC);
	Director::getInstance()->getTextureCache()->addImage(MATERIAL_C);
	Director::getInstance()->getTextureCache()->addImage(MATERIAL_F);
	Director::getInstance()->getTextureCache()->addImage(MATERIAL_Ag);
	Director::getInstance()->getTextureCache()->addImage(MATERIAL_Au);
	Director::getInstance()->getTextureCache()->addImage(MOULD_TILT);
	Director::getInstance()->getTextureCache()->addImage(MOULD_VER);
	Director::getInstance()->getTextureCache()->addImage(MOULD_SQU);
	Director::getInstance()->getTextureCache()->addImage(BLACKSMITH_BK);

	Director::getInstance()->getTextureCache()->addImage(TILTTILT_CU);
	Director::getInstance()->getTextureCache()->addImage(TILTTILT_FE);
	Director::getInstance()->getTextureCache()->addImage(TILTTILT_AG);
	Director::getInstance()->getTextureCache()->addImage(TILTTILT_AU);
	Director::getInstance()->getTextureCache()->addImage(SQUTILT_CU);
	Director::getInstance()->getTextureCache()->addImage(SQUTILT_FE);
	Director::getInstance()->getTextureCache()->addImage(SQUTILT_AG);
	Director::getInstance()->getTextureCache()->addImage(SQUTILT_AU);
	Director::getInstance()->getTextureCache()->addImage(VERTILT_CU);
	Director::getInstance()->getTextureCache()->addImage(VERTILT_FE);
	Director::getInstance()->getTextureCache()->addImage(VERTILT_AG);
	Director::getInstance()->getTextureCache()->addImage(VERTILT_AU);

}
bool StartLayer::onClickToStart(Touch* touch, Event* event)
{
	sm->goMainScene();
	return true;
}
