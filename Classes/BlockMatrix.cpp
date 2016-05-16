#include "BlockMatrix.h"
#include "Block.h"
#include "BlackSmithLayer.h"
#include "Mineral.h"
#include "Mould.h"
#include "FloatNumber.h"

BlockMatrix::BlockMatrix()
{
}


BlockMatrix::~BlockMatrix()
{
}
BlockMatrix* BlockMatrix::create(BlackSmithLayer* layer)
{
	BlockMatrix* blockMatrix = new BlockMatrix();
	if (blockMatrix && blockMatrix->init(layer))
	{
		blockMatrix->autorelease();
		return blockMatrix;
	}
	CC_SAFE_DELETE(blockMatrix);
	return nullptr; 
}
bool BlockMatrix::init(BlackSmithLayer* layer)
{
	smithLayer = layer;
	memset(blocks,0,sizeof(Block*)*ROW_NUM*COL_NUM);
	initMatrix();
	return true;
}
void BlockMatrix::initMatrix()
{
	for (int i = 0; i < ROW_NUM;i++){
		for (int j = 0; j < COL_NUM;j++){
			Block* block = Block::create();
			blocks[i][j] = block;
			block->setIndexRow(i);
			block->setIndexCol(j);
			block->getBlockSprite()->setPosition(Point(60+j*72,473-i*72));
			block->getBlockSprite()->setAnchorPoint(Point(0.5,0.5));
			this->addChild(block);
		}
	}
}
void BlockMatrix::convertToIndex(Vec2 location)
{
	auto touchLocation = location;
	int indexJ = ceil(((int)(location.x) - 25) / 70);
	int indexI = ceil(abs(((int)(location.y) - 150) / 70 -4));
	CCLOG("IndexI,IndexJ£º%d,%d",indexI,indexJ);
	checkIndexForChoice(indexI,indexJ);
}
void BlockMatrix::checkIndexForChoice(int x, int y)
{
	bool isFree = blocks[x][y]->isFree();
	CCLOG("IsFree£º%d",isFree);
	if (isFree)
	{
		blocks[x][y]->initMineral();
		blocks[x][y]->setIsMineral(true);

		CallFunc* remove1 = CallFunc::create([=](){
			if (blocks[x][y]->getMineralType() == 1)
			{
				checkMineralForRemove(x, y, 1);
				generateNewMineral(x, y, 1);
			}
		});
		CallFunc* remove2 = CallFunc::create([=](){
			if (blocks[x][y]->getMineralType() == 2)
			{
				checkMineralForRemove(x, y, 2);
				generateNewMineral(x, y, 2);
			}
		});
		CallFunc* remove3 = CallFunc::create([=](){
			if (blocks[x][y]->getMineralType() == 3)
			{
				checkMineralForRemove(x, y, 3);
				generateNewMineral(x, y, 3);
			}
		});
		CallFunc* remove4 = CallFunc::create([=](){
			if (blocks[x][y]->getMineralType() == 4)
			{
				checkMineralForRemove(x, y, 4);
				generateNewMineral(x, y, 4);
			}
		});
		Sequence* seq = Sequence::create(DelayTime::create(0.7), remove1, DelayTime::create(0.3), remove2, DelayTime::create(0.3), remove3, DelayTime::create(0.3), remove4, NULL);
		this->runAction(seq);
	}
}
void BlockMatrix::checkMineralForRemove(int x, int y,int type)
{
	selectedList.clear();
	deque<Block*> travelList;
	travelList.push_back(blocks[x][y]);
	deque<Block*>::iterator it;
	for (it = travelList.begin(); it != travelList.end();){
		Block* block = *it;
		Block* linkBlock = nullptr;
		int indexI = block->getIndexRow();
		int indexJ = block->getIndexCol();
		//ÉÏ
		if (indexI-1 >= 0 && (linkBlock = blocks[indexI - 1][indexJ]))
		{
			if (!linkBlock->getisSelected() && linkBlock->getIsMineral() && linkBlock->getMineralType() == type){
				travelList.push_back(blocks[indexI-1][indexJ]);
			}
		}
		//ÏÂ
		if (indexI + 1 < ROW_NUM && (linkBlock = blocks[indexI + 1][indexJ]) && linkBlock->getMineralType() == type)
		{
			if (!linkBlock->getisSelected() && linkBlock->getIsMineral())
				travelList.push_back(blocks[indexI + 1][indexJ]);
		}
		//×ó
		if (indexJ - 1 >= 0 && (linkBlock = blocks[indexI][indexJ - 1]) && linkBlock->getMineralType() == type){
			if (!linkBlock->getisSelected() && linkBlock->getIsMineral())
				travelList.push_back(blocks[indexI][indexJ - 1]);
		}
		//ÓÒ  
		if (indexJ + 1 < COL_NUM && (linkBlock = blocks[indexI][indexJ + 1]) && linkBlock->getMineralType() == type){
			if (!linkBlock->getisSelected() && linkBlock->getIsMineral())
				travelList.push_back(blocks[indexI][indexJ + 1]);
		}
		if (!block->getisSelected())
		{
			block->setisSelected(true);
			selectedList.push_back(block);
		}
		travelList.pop_front();
		it = travelList.begin();
	}
}
void BlockMatrix::generateNewMineral(int x,int y,int type)
{
	if (selectedList.size() == 1)
	{
		selectedList.at(0)->setisSelected(false);
	}
	else if (selectedList.size() == 2)
	{
		selectedList.at(0)->setisSelected(false);
		selectedList.at(1)->setisSelected(false);
	}
	else 
	{
		int mineralLevel = type;
		auto it = selectedList.begin();
		Block* block = *it;
		block->setisSelected(false);
		block->generateMineral(mineralLevel+1);
		it++;
		for (; it != selectedList.end(); it++){
			Block* itBlock = *it;
			itBlock->setIsMineral(false);
			itBlock->setisSelected(false);
			itBlock->mineral->removeFromParentAndCleanup(true);
		}
		Point floatPoint = blocks[x][y]->getBlockSprite()->getPosition();
		FloatNumber* floatNumber = FloatNumber::create(mineralLevel*2, 30, floatPoint);
		this->addChild(floatNumber);
		floatNumber->floatIn();
	}
}
Vec2 BlockMatrix::checkMouldForSet(Vec2 location)
{
	CCLOG("Mould:%f,%f",location.x,location.y);
	auto touchLocation = location;
	if (touchLocation.y<150  || touchLocation.y >545)
	{
		return Vec2(-1,-1);
	}
	int indexJ = ceil(((int)(location.x) - 25) / 70); 
	int indexI = ceil(abs(((int)(location.y) - 150) / 70 - 4));
	return Vec2(indexI,indexJ);
}
bool BlockMatrix::checkMouldForRemove(int x, int y, int type)
{
	if (blocks[x][y]->isFree())
	{
	//	Block* block = blocks[x][y];
	//	block->initMould(type);
	//	block->setIsMould(true);
		return true;
	}
	return false;
}
Block* BlockMatrix::getBlockAtIndex(int x, int y)
{
	if (blocks[x][y] != nullptr){
		return blocks[x][y];
	}
}
bool BlockMatrix::checkMouldMineralForUp(int x, int y, int Mouldtype)
{
	checkMineralForRemove(x,y,1);
	if (!generateNewMould(x, y, 1,Mouldtype)){
		checkMineralForRemove(x,y,2);
		if (!generateNewMould(x, y, 2, Mouldtype))
		{
			checkMineralForRemove(x,y,3);
			if (!generateNewMould(x, y, 3, Mouldtype))
			{
				checkMineralForRemove(x, y, 4);
				if (!generateNewMould(x, y, 4, Mouldtype))
				{
					return false;
				}
			}
		}
	}
}
bool BlockMatrix::generateNewMould(int x, int y, int type,int mouldType)
{
	if (selectedList.size() == 1)
	{
		selectedList.at(0)->setisSelected(false);
	}
	else if (selectedList.size() == 2)
	{
		selectedList.at(0)->setisSelected(false);
		selectedList.at(1)->setisSelected(false);
	}
	else
	{
		int mineralLevel = type;
		auto it = selectedList.begin();
		Block* block = *it;
		block->initMould(mouldType);
		block->setIsMould(true);
		block->setisSelected(false);
		block->generateMould(mineralLevel);
		it++;
		for (; it != selectedList.end(); it++){
			Block* itBlock = *it;
			itBlock->setIsMineral(false);
			itBlock->setisSelected(false);
			itBlock->mineral->removeFromParentAndCleanup(true);
		}
		Point floatPoint = blocks[x][y]->getBlockSprite()->getPosition();
		FloatNumber* floatNumber = FloatNumber::create(mineralLevel * 2, 30, floatPoint);
		this->addChild(floatNumber);
		floatNumber->floatIn();
		return true;
	}
	return false;
}
