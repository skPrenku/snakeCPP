#pragma once
#include <iostream>

struct food {
	int posX;
	int posY;
	int powerUp;
	food();
	food(int power);
	void randomPosition();
};