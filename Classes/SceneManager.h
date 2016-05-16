#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "cocos2d.h"
USING_NS_CC;
class SceneManager
{
public:
	SceneManager(void);
	~SceneManager(void);

public:
	Scene* startScene;
	Scene* mainScene;
	Scene* imperialScene;
	Scene* storeScene;
	Scene* blackSmithScene;
	Scene* auctionScene;
	Scene* battleScene;
	Scene* backpackScene;

public:
	void createScene();
	void goMainScene();	//主场景
	void goImperialScene();	//皇城
	void goStoreScene();	//商店
	void goBlackSmithScene();	//铁匠铺
	void goAuctionScene();	//拍卖行
	void goBattleScene();	//战斗场景
	void goBackpackScene();	//背包场景
	void playEffect();
};

#endif 