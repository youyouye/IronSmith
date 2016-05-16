#ifndef MAINLAYER_H_
#define MAINLAYER_H_
#include "cocos2d.h"
#include "SceneManager.h"
#include "SimpleAudioEngine.h"
class MainLayer : public Layer
{
public:
	MainLayer();
	~MainLayer();
public:
	SceneManager* sm;
	virtual bool init();
	CREATE_FUNC(MainLayer);
	bool onClickToStart(Touch* touch, Event* event);

};

#endif