#include "../header/food.h"
#include "../header/gameDefs.h"
#include <windows.h>

food::food() {
	srand(time(0));
	posX = (rand() % (WIDTH - 1)) + 1;
	posY = (rand() % (HEIGHT - 1)) + 1;
	powerUp = 1;
}

food::food(int power) {
	srand(time(0));
	posX = (rand() % (WIDTH - 1)) + 1;
	posY = (rand() % (HEIGHT - 1)) + 1;
	powerUp = power;
}

void food::randomPosition() {
	posX = (rand() % (WIDTH - 1)) + 1;
	posY = (rand() % (HEIGHT - 1)) + 1;
}