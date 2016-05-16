#ifndef BLOCK_H_
#define BLOCK_H_
#include "cocos2d.h"
#include "Constant.h"
USING_NS_CC;
class Mould;
class Mineral;
class Block : public Node
{
public:
	Block();
	~Block();
public:
	static Block* create();
	bool init();
public:
	/*
	*@param:int type
	1:normal 2:magic 3:burning
	*/
	void changeBlockType(int type);
	bool isFree();
public:
	Mould* mould;
	Mineral* mineral;
	Mould* getMould();
	Mineral* getMineral();
	void generateMineral(int type);
	void generateMould(int type);	//øÛ Ø÷÷¿‡
	void initMineral();
	void initMould(int type);
	int getMineralType();
public:
	CC_SYNTHESIZE(Sprite*, _blockSprite, BlockSprite);
	CC_SYNTHESIZE(int, _indexRow, IndexRow);
	CC_SYNTHESIZE(int, _indexCol, IndexCol);
	CC_SYNTHESIZE(bool, _isMineral, IsMineral);
	CC_SYNTHESIZE(bool, _isMould, IsMould);
	CC_SYNTHESIZE(bool, _isSelected, isSelected);
};

#endif
