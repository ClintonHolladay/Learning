// SnakeGame.cpp

#include <iostream>
#include <conio.h>
#include <Windows.h>

const int MaxX{ 30 };
const int MaxY{ 15 };
char GameBoard[MaxY][MaxX];
int TailX[50];
int TailY[50];
int prevSnakeX{};
int prevSnakeY{};
int foodY{};
int foodX{};
int snakeX = (MaxX -1) / 2;
int snakeY = (MaxY -1) / 2;
int score{ 0 };
int tail{ 0 };
char input{0};
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
	GameBoard[foodY][foodX] = 'X';
	GameBoard[snakeY][snakeX] = 'O';
	for (int i = 0; i < MaxY; i++)
	{
		for (int j = 0; j < MaxX; j++)
		{
			std::cout << GameBoard[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "Score: " << score;
}
void GetUserInput()
{
	if (_kbhit()) input = _getch();
	//if (input) GameBoard[snakeY][snakeX] = ' ';
}
void GameLogic()
{
	if (input)
	{
		GameBoard[snakeY][snakeX] = ' ';
		prevSnakeX = snakeX;
		prevSnakeY = snakeY;
		GameBoard[TailY[0]][TailX[0]] = 'o';
		/*if (tail > 0)
		{
			for (int i = (tail - 1); i < tail; i++)
				GameBoard[TailY[i]][TailX[i]] = 'o';
		}*/
	}
	switch (input)
	{
	case UP:
		--snakeY; break;
	case LEFT:
		--snakeX; break;
	case RIGHT:
		++snakeX; break;
	case DOWN:
		++snakeY; break;
	default: break;
	}
	if (snakeX == MaxX - 1) snakeX = 1;
	if (snakeX == 0) snakeX = MaxX - 2;
	if (snakeY == MaxY - 1) snakeY = 1;
	if (snakeY == 0)snakeY = MaxY - 2;
	if (snakeY == foodY && snakeX == foodX)
	{
		++score;
		foodY = (rand() % (MaxY - 2) + 1);
		foodX = (rand() % (MaxX - 2) + 1);
		++tail;
		TailX[0] = prevSnakeX;
		TailY[0] = prevSnakeY;
	}
}

int main()
{
	srand(time(NULL));
	foodY = rand() % (MaxY -1);
	foodX = rand() % (MaxX -1);
	SetBoard();
	while (GameOn)
	{
		DrawBoard();
		GetUserInput();
		GameLogic();
		Sleep(50);
	}
}

