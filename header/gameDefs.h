#pragma once
#define WIDTH 30					//Snake board size Width and Height
#define HEIGHT 30



#define powerBonus 1				// how much should the snake grow, when eating food
#define FPS 1						// frames per second
#define SPEEDINCREASE_INTERVAL 3	// after 3 food eaten,  speed will be increased
#define SPEEDUPVAL 50				// speedup value wich will be subtracted from the gameSpeed

static int gameSpeed = 500;			// the actual miliseconds of for every frame. half a second/ -> 1000ms == 1 second
static bool gameOver = false;		// gameOver boolian to keep track of game condition if its Over or not.
