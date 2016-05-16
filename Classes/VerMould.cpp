#include "VerMould.h"


VerMould::VerMould()
{
}


VerMould::~VerMould()
{
}
VerMould* VerMould::create()
{
	VerMould* verMould = new VerMould();
	verMould->init();
	verMould->autorelease();
	return verMould;
}
bool VerMould::init()
{
	_verMouldSprite = Sprite::create(MOULD_VER);
	_mouldMineralType = 0;
	this->addChild(_verMouldSprite, 30);
	return true;
}
Sprite* VerMould::getMouldSprite()
{
	return _verMouldSprite;
}
void VerMould::generateMineralMould(int type)
{
	Texture2D* textureCu = Director::getInstance()->getTextureCache()->getTextureForKey(VERTILT_CU);
	Texture2D* textureFe = Director::getInstance()->getTextureCache()->getTextureForKey(VERTILT_FE);
	Texture2D* textureAg = Director::getInstance()->getTextureCache()->getTextureForKey(VERTILT_AG);
	Texture2D* textureAu = Director::getInstance()->getTextureCache()->getTextureForKey(VERTILT_AU);

	if (type == 1)
	{
		_mouldMineralType = 1;
		_verMouldSprite->setTexture(textureCu);
	}
	else if (type == 2)
	{
		_mouldMineralType = 2;
		_verMouldSprite->setTexture(textureFe);
	}
	else if (type == 3)
	{
		_mouldMineralType = 3;
		_verMouldSprite->setTexture(textureAg);
	}
	else if (type == 4)
	{
		_mouldMineralType = 4;
		_verMouldSprite->setTexture(textureAu);
	}
}
