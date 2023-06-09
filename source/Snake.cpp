#include "../header/Snake.h"
#include "../header/gameDefs.h"

snake::snake(int x, int y)   {
	posX = x;
	posY = y;
	prevPosX = posX;
	prevPosY = posY;
}

snake::snake() {
	posX = (WIDTH / 2);
	posY =  (HEIGHT / 2);
	prevPosX = posX;
	prevPosY = posY;

}

void growTail(snake& snakeHead) {
	tail t;
	snakeHead.snakeTail.push_back(t);
	
}

bool tailPosition(snake & Snake, int x, int y) {
	for (std::size_t i = 0; i < Snake.snakeTail.size(); i++) {
		if ((Snake.snakeTail[i].posX == x) && (Snake.snakeTail[i].posY == y))
			return true;
	}

	return false;
}