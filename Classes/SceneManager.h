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
	void goMainScene();	//������
	void goImperialScene();	//�ʳ�
	void goStoreScene();	//�̵�
	void goBlackSmithScene();	//������
	void goAuctionScene();	//������
	void goBattleScene();	//ս������
	void goBackpackScene();	//��������
	void playEffect();
};

#endif 