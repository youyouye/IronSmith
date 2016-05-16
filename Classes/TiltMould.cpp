#include "TiltMould.h"


TiltMould::TiltMould()
{
}


TiltMould::~TiltMould()
{
}

TiltMould* TiltMould::create()
{
	TiltMould* tiltMould = new TiltMould();
	tiltMould->init();
	tiltMould->autorelease();
	return tiltMould;
}
bool TiltMould::init()
{
	_tiltMouldSprite = Sprite::create(MOULD_TILT);
	_mouldMineralType = 0;
	this->addChild(_tiltMouldSprite, 30);
	return true;
}
Sprite* TiltMould::getMouldSprite()
{
	return _tiltMouldSprite;
}
void TiltMould::generateMineralMould(int type)
{
	Texture2D* textureCu = Director::getInstance()->getTextureCache()->getTextureForKey(TILTTILT_CU);
	Texture2D* textureFe = Director::getInstance()->getTextureCache()->getTextureForKey(TILTTILT_FE);
	Texture2D* textureAg = Director::getInstance()->getTextureCache()->getTextureForKey(TILTTILT_AG);
	Texture2D* textureAu = Director::getInstance()->getTextureCache()->getTextureForKey(TILTTILT_AU);

	if (type == 1)
	{
		_mouldMineralType = 1;
		_tiltMouldSprite->setTexture(textureCu);
	}
	else if (type == 2)
	{
		_mouldMineralType = 2;
		_tiltMouldSprite->setTexture(textureFe);
	}
	else if (type == 3)
	{
		_mouldMineralType = 3;
		_tiltMouldSprite->setTexture(textureAg);
	}
	else if (type == 4)
	{
		_mouldMineralType = 4;
		_tiltMouldSprite->setTexture(textureAu);
	}
}

