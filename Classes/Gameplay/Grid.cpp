#include "Gameplay/Grid.h"
#include "Gameplay/GridCell.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Constants.h"

Grid::Grid(int rows, int cols,cocos2d::Node* container) {

	gridCells = std::vector<std::vector<GridCell*> >(cols);
	for (int i = 0; i < cols; ++i) { gridCells[i] = std::vector<GridCell*>(rows); }


	float panelWidth = container->getBoundingBox().size.width;
	float panelHeight = container->getBoundingBox().size.height;
	float offset = Constants::getInstance().sideOffset;
	float divisionBetweencolumns = Constants::getInstance().divisionBetweenGridTiles;

	float width = (panelWidth - (offset * 2) - (divisionBetweencolumns * (cols - 1))) / cols;
	float height = (panelHeight - (offset * 2) - (divisionBetweencolumns * (rows - 1))) / rows;

	for (int j = 0; j < cols; ++j) {
		for (int i = 0; i < rows; ++i) {
			Color3B colorCell = Constants::getInstance().tileColor1;
			if ((i + j) % 2 == 0) { colorCell = Constants::getInstance().tileColor2; }
			cocos2d::Vec2 cellPosition = cocos2d::Vec2(offset + (j*width) + (j*(divisionBetweencolumns)) + (width / 2), offset + (i*height) + (i*(divisionBetweencolumns)) + (height / 2));

			gridCells[j][i] = new GridCell(colorCell, i, j, cellPosition, width, height, container);
		}
	}
}

std::vector<GridCell*>* Grid::getGridCellsInCross(int posx, int posy, bool includeSelf, int distance) {
	std::vector<GridCell*>* result = new std::vector<GridCell*>(0);
	if (insideBounds(posx,posy)) {
		if (includeSelf) { result->push_back(gridCells[posx][posy]); }
		for (int i = 1; i <= distance; ++i) {
			if (insideBounds(posx + i, posy)) { result->push_back(gridCells[posx + i][posy]); }
			if (insideBounds(posx - i, posy)) { result->push_back(gridCells[posx - i][posy]); }
			if (insideBounds(posx, posy + i)) { result->push_back(gridCells[posx][posy + i]); }
			if (insideBounds(posx, posy - i)) { result->push_back(gridCells[posx][posy - i]); }
		}
	}
	return result;
}

std::vector<GridCell*>* Grid::getGridCellsInX(int posx, int posy, bool includeSelf, int distance) {
	std::vector<GridCell*>* result = new std::vector<GridCell*>(0);
	if (insideBounds(posx, posy)) {
		if (includeSelf) { result->push_back(gridCells[posx][posy]); }
		for (int i = 1; i <= distance; ++i) {
			if (insideBounds(posx + i, posy + i)) { result->push_back(gridCells[posx + i][posy + i]); }
			if (insideBounds(posx - i, posy + i)) { result->push_back(gridCells[posx - i][posy + i]); }
			if (insideBounds(posx + i, posy - i)) { result->push_back(gridCells[posx + i][posy - i]); }
			if (insideBounds(posx - i, posy - i)) { result->push_back(gridCells[posx - i][posy - i]); }
		}
	}
	return result;
}

std::vector<GridCell*>* Grid::getGridCellsInCircle(int posx, int posy, bool includeSelf, int distance) {
	std::vector<GridCell*>* result = new std::vector<GridCell*>(0);
	if (insideBounds(posx, posy)) {
		if (includeSelf) { result->push_back(gridCells[posx][posy]); }
		for (int i = 1; i <= distance; ++i) {
			if (insideBounds(posx + i, posy)) { result->push_back(gridCells[posx + i][posy]); }
			if (insideBounds(posx - i, posy)) { result->push_back(gridCells[posx - i][posy]); }
			if (insideBounds(posx, posy + i)) { result->push_back(gridCells[posx][posy + i]); }
			if (insideBounds(posx, posy - i)) { result->push_back(gridCells[posx][posy - i]); }
			if (insideBounds(posx + i, posy + i)) { result->push_back(gridCells[posx + i][posy + i]); }
			if (insideBounds(posx - i, posy + i)) { result->push_back(gridCells[posx - i][posy + i]); }
			if (insideBounds(posx + i, posy - i)) { result->push_back(gridCells[posx + i][posy - i]); }
			if (insideBounds(posx - i, posy - i)) { result->push_back(gridCells[posx - i][posy - i]); }
		}
	}
	return result;
}

bool Grid::insideBounds(int posx, int posy) {
	return posx < gridCells.size() && posx >= 0 && posy < gridCells[0].size() && posy >= 0;
}