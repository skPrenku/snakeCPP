#pragma once
#include <Windows.h>
#include "Snake.h"
#include "gameDefs.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

bool moveLeft = false;
bool moveRight = false;
bool moveUp = false;
bool moveDown = false;

void Directions() {
	int key = 0;
	while (!gameOver) {

		if (_kbhit())
		{

			switch (_getch())
			{
			case LEFT:
				if(!moveRight)
				moveLeft = true, moveRight = false, moveUp = false, moveDown = false;
				break;
			case RIGHT:
				if (!moveLeft)
				moveLeft = false, moveRight = true, moveUp = false, moveDown = false;
				break;
			case UP:
				if(!moveDown)
				moveLeft = false, moveRight = false, moveUp = true, moveDown = false;
				break;
			case DOWN:
				if (!moveUp)
				moveLeft = false, moveRight = false, moveUp = false, moveDown = true;
				break;
			default:
				break;
			}
		}
			
	}
	

}
//Snake moving function, and keeping track of all tail parts positions for x,y coordinates.
void moveSnake(snake& snakeHead) {

	//store actual XY snakeHead positions as 'previous' for comming snake Tail parts..
	snakeHead.prevPosX = snakeHead.posX; 
	snakeHead.prevPosY = snakeHead.posY;


	if (snakeHead.snakeTail.size() > 0) {
		
		for (std::size_t i = 0; i < snakeHead.snakeTail.size(); i++)
		{
			if (i == 0)
			{
				snakeHead.snakeTail[i].prevPosX = snakeHead.snakeTail[i].posX;
				snakeHead.snakeTail[i].posX = snakeHead.prevPosX;

				snakeHead.snakeTail[i].prevPosY = snakeHead.snakeTail[i].posY;
				snakeHead.snakeTail[i].posY = snakeHead.prevPosY;
			}
			else {
				snakeHead.snakeTail[i].prevPosX = snakeHead.snakeTail[i].posX;
				snakeHead.snakeTail[i].posX = snakeHead.snakeTail[i-1].prevPosX;

				snakeHead.snakeTail[i].prevPosY = snakeHead.snakeTail[i].posY;
				snakeHead.snakeTail[i].posY = snakeHead.snakeTail[i - 1].prevPosY;
			}

			cout << snakeHead.snakeTail[i].posX << snakeHead.snakeTail[i].prevPosX<< endl;
			cout << snakeHead.snakeTail[i].posY << snakeHead.snakeTail[i].prevPosY << endl<<endl;
		}
		
	}

	if (moveLeft)
		snakeHead.posX--;

	if (moveRight)
		snakeHead.posX++;

	if (moveUp)
		snakeHead.posY--;

	if (moveDown)
		snakeHead.posY++;

}