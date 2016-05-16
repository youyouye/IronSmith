#ifndef STARTLAYER_H_
#define STARTLAYER_H_
#include "cocos2d.h"
#include "Constant.h"
#include "SceneManager.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
class StartLayer : public Layer
{
public:
	StartLayer(void);
	~StartLayer(void);

	SceneManager* sm;
	void gotoMainGame(float ft);
	virtual bool init();
	void initTexture();
	void backMusic();
	bool onClickToStart(Touch* touch, Event* event);
	CREATE_FUNC(StartLayer);
};

#endif