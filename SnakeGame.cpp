// SnakeGame.cpp

#include <iostream>
#include <conio.h>
#include <Windows.h>

const int MaxX{ 30 };
const int MaxY{ 15 };
char GameBoard[MaxY][MaxX];
int TailX[50];
int TailY[50];
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

void SetBoard()
{
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
}
void GameLogic()
{
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
	// if eat self GAME OVER
	for (int i = 1; i < tail; i++)
	{
		if (snakeX == TailX[i] && snakeY == TailY[i]) GameOn = false;
	}
	// Food regeneration
	if (snakeY == foodY && snakeX == foodX)
	{
		foodY = (rand() % (MaxY - 2) + 1);
		foodX = (rand() % (MaxX - 2) + 1);
		++tail;
		/*TailX[0] = snakeX;
		TailY[0] = snakeY;*/
	}
	// code for running into the walls
	if (snakeX == MaxX - 1) snakeX = 1;
	if (snakeX == 0) snakeX = MaxX - 2;
	if (snakeY == MaxY - 1) snakeY = 1;
	if (snakeY == 0)snakeY = MaxY - 2;
	
}

int main()
{
	srand((unsigned)time(NULL));
	foodY = (rand() % (MaxY - 2) + 1);
	foodX = (rand() % (MaxX - 2) + 1);
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
