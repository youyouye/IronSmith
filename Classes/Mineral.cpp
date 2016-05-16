#include "Mineral.h"


Mineral::Mineral()
{
}


Mineral::~Mineral()
{
}


bool Mineral::init(int type)
{
	_mineralType = type;
	if (type == 1)
	{
		Texture2D* textureC = Director::getInstance()->getTextureCache()->getTextureForKey(MATERIAL_C);
		_mineralSprite = Sprite::createWithTexture(textureC);
	}
	else if (type == 2)
	{
		Texture2D* textureF = Director::getInstance()->getTextureCache()->getTextureForKey(MATERIAL_F);
		_mineralSprite = Sprite::createWithTexture(textureF);
	}
	else if (type == 3)
	{
		Texture2D* textureAg = Director::getInstance()->getTextureCache()->getTextureForKey(MATERIAL_Ag);
		_mineralSprite = Sprite::createWithTexture(textureAg);
	}
	else if (type == 4)
	{
		Texture2D* textureAu = Director::getInstance()->getTextureCache()->getTextureForKey(MATERIAL_Au);
		_mineralSprite = Sprite::createWithTexture(textureAu);
	}
	this->addChild(_mineralSprite,30);
	return true;
}
Mineral* Mineral::create(int type)
{
	Mineral* mineral = new Mineral();
	mineral->init(type);
	mineral->autorelease();
	return mineral;
}
void Mineral::changeMineralType(int type)
{
	_mineralType = type;
	if (type == 1)
	{
		Texture2D* textureC = Director::getInstance()->getTextureCache()->getTextureForKey(MATERIAL_C);
		_mineralSprite->setTexture(textureC);
	}
	else if (type == 2)
	{
		Texture2D* textureF = Director::getInstance()->getTextureCache()->getTextureForKey(MATERIAL_F);
		_mineralSprite->setTexture(textureF);
	}
	else if (type == 3)
	{
		Texture2D* textureAg = Director::getInstance()->getTextureCache()->getTextureForKey(MATERIAL_Ag);
		_mineralSprite->setTexture(textureAg);
	}
	else if (type == 4)
	{
		Texture2D* textureAu = Director::getInstance()->getTextureCache()->getTextureForKey(MATERIAL_Au);
		_mineralSprite->setTexture(textureAu);
	}
}
