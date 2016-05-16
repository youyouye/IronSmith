#include "Block.h"
#include "Mineral.h"
#include "Mould.h"
#include "SquMould.h"
#include "TiltMould.h"
#include "VerMould.h"
Block::Block()
{
}


Block::~Block()
{
}
Block* Block::create()
{
	Block* block = new Block();
	block->init();
	block->autorelease();
	return block;
}
bool Block::init()
{
	Texture2D* textureBlock = Director::getInstance()->getTextureCache()->getTextureForKey(TILE_NORMAL);
	_blockSprite = Sprite::createWithTexture(textureBlock);
	_blockSprite->setScale(0.7);
	this->addChild(_blockSprite,30);
	_isMould = false;
	_isMineral = false;
	_isSelected = false;
	return true;
}
void Block::changeBlockType(int type)
{
	if (type == 1)
	{
		Texture2D* textureNormal = Director::getInstance()->getTextureCache()->getTextureForKey(TILE_NORMAL);
		_blockSprite->setTexture(textureNormal);
	}
	else if (type == 2)
	{
		Texture2D* textureMagic = Director::getInstance()->getTextureCache()->getTextureForKey(TILE_NORMAL);
		_blockSprite->setTexture(textureMagic);
	}
	else if (type == 3)
	{
		Texture2D* textureBurning = Director::getInstance()->getTextureCache()->getTextureForKey(TILE_NORMAL);
		_blockSprite->setTexture(textureBurning);
	}
}
bool Block::isFree()
{
	return (_isMineral== 0 && _isMould == 0);
}
Mould* Block::getMould()
{
	return mould;
}
Mineral* Block::getMineral()
{
	return mineral;
}
void Block::initMineral()
{
	mineral = Mineral::create(1);
	mineral->setPosition(Point(50,560));
	this->addChild(mineral,50);
	auto moveTo = MoveTo::create(0.5,_blockSprite->getPosition());
	mineral->runAction(moveTo);
}
void Block::generateMineral(int type)
{
	mineral->changeMineralType(type);
}
int Block::getMineralType()
{
	if (_isMineral){
		return mineral->getMineralType();
	}
	return -1;
}
void Block::initMould(int type)
{
	if (type == 1)
	{
		mould = SquMould::create();
	}
	else if (type == 2)
	{
		mould = TiltMould::create();
	}
	else if (type == 3)
	{
		mould = VerMould::create();
	}
	mould->setPosition(_blockSprite->getPosition());
	mould->setScale(0.7);
	this->addChild(mould,50);
}
void Block::generateMould(int type)
{
	mould->generateMineralMould(type);
}
