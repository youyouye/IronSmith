#include "BlackSmithLayer.h"
#include "BlockMatrix.h"
#include "SceneManager.h"
#include "Block.h"
#include "Mould.h"
#include "SquMould.h"
#include "TiltMould.h"
#include "VerMould.h"

BlackSmithLayer::BlackSmithLayer()
{
}


BlackSmithLayer::~BlackSmithLayer()
{
}
bool BlackSmithLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	initClickEvent();
	initBKLayer();
	initBlock();
	initMould();
	initMouldEvent();
	return true;
}
void BlackSmithLayer::initBlock()
{
	blockMatrix = BlockMatrix::create(this);
	this->addChild(blockMatrix,100);
}
void BlackSmithLayer::initBKLayer()
{
	Texture2D* textureBlock = Director::getInstance()->getTextureCache()->getTextureForKey(BLACKSMITH_BK);
	Sprite* background = Sprite::createWithTexture(textureBlock);
	background->setPosition(Point(240,205));
	background->setScale(0.6,0.75);
	this->addChild(background,50);
	cursor = Sprite::create(CURSOR);
	this->addChild(cursor,100);
}
void BlackSmithLayer::initClickEvent()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(BlackSmithLayer::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(BlackSmithLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
bool BlackSmithLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	return true;
}
void BlackSmithLayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto location = touch->getLocation();
	CCLOG("ClickLocation£º%f,%f",location.x,location.y);
	if (location.y >150 )
	{
		blockMatrix->convertToIndex(location);
	}
}
void BlackSmithLayer::initMould()
{
	for (int i = 0; i < 3;i++){
		mouldType[i] = CCRANDOM_0_1() * 3 + 1;
	}
	Texture2D* textureBlock = Director::getInstance()->getTextureCache()->getTextureForKey(TILE_NORMAL);
	Sprite* block1 = Sprite::createWithTexture(textureBlock);
	block1->setPosition(Point(240,100));
	block1->setScale(0.7);
	this->addChild(block1,60);
	Sprite* block2 = Sprite::createWithTexture(textureBlock);
	block2->setPosition(Point(293,82));
	block2->setScale(0.35,0.35);
	this->addChild(block2, 60);
	Sprite* block3 = Sprite::createWithTexture(textureBlock);
	block3->setPosition(Point(328, 82));
	block3->setScale(0.35, 0.35);
	this->addChild(block3, 60);
	Texture2D* texture1 = Director::getInstance()->getTextureCache()->getTextureForKey(MOULD_SQU);
	Texture2D* texture2 = Director::getInstance()->getTextureCache()->getTextureForKey(MOULD_TILT);
	Texture2D* texture3 = Director::getInstance()->getTextureCache()->getTextureForKey(MOULD_VER);
	if (mouldType[2] == 1)
	{
		mouldBlock3 = Sprite::createWithTexture(texture1);
	}
	else if (mouldType[2] == 2)
	{
		mouldBlock3 = Sprite::createWithTexture(texture2);
	}
	else if (mouldType[2] == 3)
	{
		mouldBlock3 = Sprite::createWithTexture(texture3);
	}
	if (mouldType[1] == 1)
	{
		mouldBlock2 = Sprite::createWithTexture(texture1);
	}
	else if (mouldType[1] == 2)
	{
		mouldBlock2 = Sprite::createWithTexture(texture2);
	}
	else if (mouldType[1] == 3)
	{
		mouldBlock2 = Sprite::createWithTexture(texture3);
	}
	if (mouldType[0] == 1)
	{
		mould = SquMould::create();
	}
	else if (mouldType[0] == 2)
	{
		mould = TiltMould::create();
	}
	else if (mouldType[0] == 3)
	{
		mould = VerMould::create();
	}
	mouldBlock2->setPosition(Point(293, 82));
	mouldBlock2->setScale(0.35,0.35);
	this->addChild(mouldBlock2,62);
	mouldBlock3->setPosition(Point(328, 82));
	mouldBlock3->setScale(0.35, 0.35);
	this->addChild(mouldBlock3,62);
	mould->setPosition(Point(240, 100));
	mould->setScale(0.7);
	this->addChild(mould,62);
}
void BlackSmithLayer::initMouldEvent()
{
	mouldListener = EventListenerTouchOneByOne::create();
	mouldListener->setSwallowTouches(true);
	mouldListener->onTouchBegan = [](Touch* touch, Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(locationInNode))
		{
			log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
			return true;
		}
		return false;
	};
	mouldListener->onTouchMoved = [=](Touch* touch, Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setPosition(target->getPosition() + touch->getDelta());
		Vec2 index = blockMatrix->checkMouldForSet(target->getPosition());
		int indexI = (int)index.x; int indexJ = (int)index.y;
		if (indexI >= 0 && indexI <= 4 && indexJ >= 0 && indexJ <= 5)
		{
			cursor->setVisible(true);
			cursor->setPosition(blockMatrix->getBlockAtIndex(indexI,indexJ)->getBlockSprite()->getPosition());
		}
	};
	mouldListener->onTouchEnded = [=](Touch* touch, Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		log("sprite onTouchesEnded.. ");
		if (target == mould->getMouldSprite())
		{
			cursor->setVisible(false);
			Vec2 locationInNode = target->getPosition();
			Vec2 index = blockMatrix->checkMouldForSet(locationInNode);
			if (index.x >= 0 && index.x <= 4 && index.y >= 0 && index.y <= 5)
			{
				bool isSetMould = blockMatrix->checkMouldForRemove((int)index.x, (int)index.y, mouldType[0]);
				if (isSetMould)
				{
					if (blockMatrix->checkMouldMineralForUp(index.x, index.y, mouldType[0])){
						moveDownMould();
					}
					else
					{
						mould->getMouldSprite()->runAction(MoveTo::create(0.5, Point(0, 0)));
					}
				}
				else
				{
					mould->getMouldSprite()->runAction(MoveTo::create(0.5, Point(0, 0)));
				}
			}
			else
			{
				mould->getMouldSprite()->runAction(MoveTo::create(0.5, Point(0,0)));
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouldListener,mould->getMouldSprite());
}
void BlackSmithLayer::moveDownMould()
{
	mould->removeFromParentAndCleanup(true);
	mouldType[0] = mouldType[1];
	mouldType[1] = mouldType[2];
	mouldType[2] = CCRANDOM_0_1() * 3 + 1;
	if (mouldType[0] == 1)
	{
		mould = SquMould::create();
	}
	else if (mouldType[0] == 2)
	{
		mould = TiltMould::create();
	}
	else if (mouldType[0] == 3)
	{
		mould = VerMould::create();
	}
	mould->setPosition(Point(240, 100));
	mould->setScale(0.7);
	this->addChild(mould,62);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouldListener, mould->getMouldSprite());
}
