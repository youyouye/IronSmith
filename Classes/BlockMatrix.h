#ifndef BLCOKMATRIX_H_
#define BLCOKMATRIX_H_
#include "cocos2d.h"
#include <deque>
USING_NS_CC;
using namespace std;
class BlackSmithLayer;
class Block;
class BlockMatrix : public Node
{
public:
	BlockMatrix();
	~BlockMatrix();
public:
	static BlockMatrix* create(BlackSmithLayer* layer);
	bool init(BlackSmithLayer* layer);
	void initMatrix();
	void convertToIndex(Vec2 location);
	void checkIndexForChoice(int x,int y);
	void checkMineralForRemove(int x, int y, int type);
	void generateNewMineral(int x, int y, int type);
	//∑≈÷√ƒ£æﬂ£∫
	Vec2 checkMouldForSet(Vec2 location);
	/*
	*1.SquMould ;2.TiltMould ;3.VerMould; 
	*/
	bool checkMouldForRemove(int x,int y,int type);
	/*
	*@param	type:mouldType[0]
	*/
	bool checkMouldMineralForUp(int x,int y,int type);
	bool generateNewMould(int x,int y,int mineralType,int mouldType);
	Block* getBlockAtIndex(int x,int y);
public:
	const static int ROW_NUM = 5;
	const static int COL_NUM = 6;
private:
	BlackSmithLayer* smithLayer;
	Block* blocks[5][6];
	deque<Block*> selectedList;
};

#endif