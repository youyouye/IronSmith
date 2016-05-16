#include "SceneManager.h"
#include "Constant.h"
#include "MainLayer.h"
#include "StartLayer.h"
#include "BlackSmithLayer.h"
SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}
void SceneManager::createScene()
{
	startScene = Scene::create();
	StartLayer* layer = StartLayer::create();
	layer->sm = this;
	startScene->addChild(layer);
}
void SceneManager::goMainScene()
{
	mainScene = Scene::create();
	MainLayer* layer = MainLayer::create();
	layer->sm = this;
	mainScene->addChild(layer);
	auto ss = TransitionMoveInB::create(0.5, mainScene);
	Director::getInstance()->replaceScene(ss);
}
void SceneManager::goImperialScene()
{
}
void SceneManager::goStoreScene()
{
}
void SceneManager::goBlackSmithScene()
{
	blackSmithScene = Scene::create();
	BlackSmithLayer* layer = BlackSmithLayer::create();
	layer->sm = this;
	blackSmithScene->addChild(layer);
	auto ss = TransitionMoveInB::create(0.5, blackSmithScene);
	Director::getInstance()->replaceScene(ss);
}
void SceneManager::goAuctionScene()
{
}
void SceneManager::goBattleScene()
{
}
void SceneManager::goBackpackScene()
{
}
void SceneManager::playEffect()
{
}