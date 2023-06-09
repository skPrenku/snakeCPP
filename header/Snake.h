#pragma once
#include "../header/gameDefs.h"
#include <vector>

struct tail {
	 int posX = 0;
	int posY = 0;
	int prevPosX = 0;
	int prevPosY = 0;

};

struct snake {

	char name = 'O';

	int posX = 0;
	int posY = 0;
	int prevPosX = 0;
	int prevPosY = 0;
	snake();
	snake(int x, int y);
	std::vector<tail> snakeTail;

};

void growTail(snake& snakeHead);
bool tailPosition(snake& Snake, int x, int y);