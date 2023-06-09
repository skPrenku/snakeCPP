// snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <thread>
#include "header/Snake.h"
#include "header/gameDefs.h"
#include "header/controller.h"
#include "header/food.h"



using namespace std;


int DrawMap(snake &snakeHead, food &f);

int foodCounter = 0;
int SpeedMeter = 1;

int main()
{
	snake snakeHead;
	food f;
	

	std::thread t1(Directions);



	while (!gameOver) //while gameOver is not True, the function DrawMap will loop, with 2 parameters, the snake Object and the food Object
	{

		DrawMap(snakeHead, f);

	}

	cout << "--GameOver--\n";
	t1.join();
	return 0;
}

int DrawMap(snake& snakeHead , food & snakeFood)
{
	moveSnake(snakeHead);
	
	system("cls");
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++) {
			
		

			 if ((j == 0 || j == WIDTH - 1) || (i == 0 || i == HEIGHT - 1)) 
			 {		
				
					cout << "#";
			 }
			 else if (snakeFood.posX == snakeHead.posX && snakeFood.posY == snakeHead.posY) //if SnakeHead bumps into Food, the Food will spawn in a random Position, and the snakeTail will grow
			 {
				 
				 snakeFood.randomPosition();
				 growTail(snakeHead);
				 foodCounter++;
				 if (foodCounter == SPEEDINCREASE_INTERVAL) {
					 gameSpeed -= 50; //speed to manage the game speed (reduces the miliseconds for the SLeep() Loop for every frame
					 foodCounter = 0;
					 SpeedMeter += 5;//speedMeter is just for the user to keep track of the game speeding up
				 }
				
			 }
			 else if (snakeFood.posX == j && snakeFood.posY == i) {
				 cout << "F";
			 }	
			 else if ((snakeHead.posX == j) && (snakeHead.posY == i))
			 {
				 if (tailPosition(snakeHead, j, i))
					gameOver = true;
				 cout << snakeHead.name;	

			 }
			 else if (tailPosition(snakeHead, j, i)) // if i & j, are equal to a tail x,y Position, this function will return true
			 { 
				 cout << 'o';
			 }
			 else
				cout << " ";
			
		}
		cout << endl;
	}

	cout << "GameSpeed: " << SpeedMeter << " SnakeSize: " << snakeHead.snakeTail.size() << endl;;
	//cout << "Food Position: X: " << snakeFood.posX << "Y: "<< snakeFood.posY << endl;

	Sleep(gameSpeed / FPS);

	return 0;
}

