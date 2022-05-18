// SnakeGame.cpp 

// Use the arrows to move the snake around the board. 
// Try to eat the 'X' that randomly gererates. 
// Grow your tail as long as you can! 
// If you reverse back onto yourself you will die. 
// If you run into you self you will die. 
// If you run into a wall you will pop back out of the other side.

#include <iostream>
#include <conio.h>
#include <Windows.h>

const int MaxX{ 30 };
const int MaxY{ 15 };
char GameBoard[MaxY][MaxX];
const int max{ 50 };
int TailX[max];
int TailY[max];
int temp1X{};
int temp1Y{};
int temp2X{};
int temp2Y{};
int prevSnakeX{};
int prevSnakeY{};
int foodY{};
int foodX{};
int snakeX = (MaxX -1) / 2;
int snakeY = (MaxY -1) / 2;
int tail{ 0 };
char input{};
enum Movement { UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80 };
bool GameOn{ true };
bool amGoingDown{ false };
bool amGoingUp{ false };
bool amGoingLeft{ false };
bool amGoingRight{ false };

void SetBoard()
{
	srand((unsigned)time(NULL));
	foodY = (rand() % (MaxY - 2) + 1);
	foodX = (rand() % (MaxX - 2) + 1);
	for (int i = 0; i < MaxY; i++)
	{
		for (int j = 0; j < MaxX; j++)
		{
			if (i == 0 || i == MaxY - 1 || j == 0 || j == MaxX - 1) GameBoard[i][j] = '#';
			else GameBoard[i][j] = ' ';
		}
	}
	GameBoard[snakeY][snakeX] = 'O'; 
}
void DrawBoard()
{
	system("CLS");
	if(input) GameBoard[prevSnakeY][prevSnakeX] = ' ';
	GameBoard[foodY][foodX] = 'X';
	if (tail)
	{
		for (int i = 0; i < tail; i++)
			GameBoard[TailY[i]][TailX[i]] = 'o';
	}
	GameBoard[snakeY][snakeX] = 'O';
	for (int i = 0; i < MaxY; i++)
	{
		for (int j = 0; j < MaxX; j++)
		{
			std::cout << GameBoard[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "Score: " << tail;
}
void GetUserInput()
{
	if (_kbhit()) input = _getch();

	// if you reverse direction you die, 
			// this is the only way out of 4 attempts that i could get to work immediately upon reversal. 
	if (tail)
	{
		switch (input)
		{
		case UP:
			if (amGoingDown) GameOn = false;
			amGoingLeft = false;
			amGoingRight = false;
			amGoingUp = true;
			break;
		case LEFT:
			if (amGoingRight) GameOn = false;
			amGoingLeft = true;
			amGoingDown = false;
			amGoingUp = false;
			break;
		case RIGHT:
			if (amGoingLeft) GameOn = false;
			amGoingDown = false;
			amGoingRight = true;
			amGoingUp = false;
			break;
		case DOWN:
			if (amGoingUp) GameOn = false;
			amGoingLeft = false;
			amGoingRight = false;
			amGoingDown = true;
			break;
		default: break;
		}
	}
}
void GameLogic()
{
	// move tail along the board behind the head.
	// this could probably be inproved because i think as it is now if you were to pause the game 
			// the tail would dissapear. but maybe not and it is functional...
	if (tail)
	{
		GameBoard[TailY[tail -1]][TailX[tail-1]] = ' ';
		for (int i = 0; i < tail; i++)
		{
			if (i == 0)
			{
				temp1X = TailX[i];
				temp1Y = TailY[i];
				TailX[i] = snakeX;
				TailY[i] = snakeY;
				continue;
			}
			else if (i % 2)
			{
				temp2X = TailX[i];
				temp2Y = TailY[i];
				TailX[i] = temp1X;
				TailY[i] = temp1Y;
				continue;
			}
			else
			{
				temp1X = TailX[i];
				temp1Y = TailY[i];
				TailX[i] = temp2X;
				TailY[i] = temp2Y;
			}
		}
	}
	prevSnakeX = snakeX;
	prevSnakeY = snakeY;
	switch (input)
	{
	case UP:
		--snakeY;
		break;
	case LEFT:
		--snakeX;
		break;
	case RIGHT:
		++snakeX;
		break;
	case DOWN:
		++snakeY;
		break;
	default: break;
	}
	// if you eat yourself GAME OVER
		for (int i = 1; i < tail; i++)
		{
			if (snakeX == TailX[i] && snakeY == TailY[i]) GameOn = false;
		}
	
	// if food is eaten
	if (snakeY == foodY && snakeX == foodX)
	{
		foodY = (rand() % (MaxY - 2) + 1);
		foodX = (rand() % (MaxX - 2) + 1);
		++tail;
		if (tail == 50)
		{
			GameOn = false;
			std::cout << "YOU HAVE BEATEN THE GAME!!!!!" << std::endl;
		}
		// This is to "initialize" the Tail[] value at the new index, so that it is something other than a '0'. 
				// This value being a '0' was causing the GameBoard[0][0] location to be a ' ' instead of a '#'. 
		TailX[tail - 1] = prevSnakeX;
		TailY[tail - 1] = prevSnakeY;
	}
	// when running into the walls pop out the other side
	if (snakeX == MaxX - 1) snakeX = 1;
	if (snakeX == 0) snakeX = MaxX - 2;
	if (snakeY == MaxY - 1) snakeY = 1;
	if (snakeY == 0)snakeY = MaxY - 2;
	
}
int main()
{
	SetBoard();
	while (GameOn)
	{
		DrawBoard();
		GetUserInput();
		GameLogic();
		Sleep(15);
	}
	std::cout << "\n\nGAME OVER!!!" << std::endl;
}
