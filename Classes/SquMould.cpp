#include "SquMould.h"


SquMould::SquMould()
{
}


SquMould::~SquMould()
{
}
SquMould* SquMould::create()
{
	SquMould* squMould = new SquMould();
	squMould->init();
	squMould->autorelease();
	return squMould;
}
bool SquMould::init()
{
	_squMouldSprite = Sprite::create(MOULD_SQU);
	_mouldMineralType = 0;
	this->addChild(_squMouldSprite,30);
	return true;
}
Sprite* SquMould::getMouldSprite()
{
	return _squMouldSprite;
}
void SquMould::generateMineralMould(int type)
{
	Texture2D* textureCu = Director::getInstance()->getTextureCache()->getTextureForKey(SQUTILT_CU);
	Texture2D* textureFe = Director::getInstance()->getTextureCache()->getTextureForKey(SQUTILT_FE);
	Texture2D* textureAg = Director::getInstance()->getTextureCache()->getTextureForKey(SQUTILT_AG);
	Texture2D* textureAu = Director::getInstance()->getTextureCache()->getTextureForKey(SQUTILT_AU);

	if (type == 1)
	{
		_mouldMineralType = 1;
		_squMouldSprite->setTexture(textureCu);
	}
	else if (type == 2)
	{
		_mouldMineralType = 2;
		_squMouldSprite->setTexture(textureFe);
	}
	else if (type == 3)
	{
		_mouldMineralType = 3;
		_squMouldSprite->setTexture(textureAg);
	}
	else if (type == 4)
	{
		_mouldMineralType = 4;
		_squMouldSprite->setTexture(textureAu);
	}
}