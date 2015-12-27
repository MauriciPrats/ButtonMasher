#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Gameplay/GridCell.h"

USING_NS_CC;

class Grid
{
public:
	Grid(int rows,int cols,cocos2d::Node* container);
	std::vector<GridCell*>* getGridCellsInCross(int posx, int posy, bool includeSelf, int distance);
	std::vector<GridCell*>* getGridCellsInX(int posx, int posy, bool includeSelf, int distance);
	std::vector<GridCell*>* getGridCellsInCircle(int posx, int posy, bool includeSelf, int distance);
private:
	std::vector<std::vector<GridCell*> > gridCells;
	bool insideBounds(int posx, int posy);
};