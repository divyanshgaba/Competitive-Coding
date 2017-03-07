#include <stdio.h>
#include <conio.h>
int gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN};
enum direction dir;
void Setup()
{
	gameOver = 0;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw()
{
	int i,j,k,print;
	for (i = 0; i < width+2; i++)
	printf("*");
	printf("\n");

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (j == 0)
			       printf("*");
			if (i == y && j == x)
				printf("O");
			else if (i == fruitY && j == fruitX)
				printf("F");
			else
			{
				print=0;
				for (k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						printf("o");
						print = 1;
					}
				}
				if (!print)
					printf(" ");
			}


			if (j == width - 1)
				printf("*");
		}
		printf("\n");
	}

	for (i = 0; i < width+2; i++)
		printf("*");
	printf("\n");
	printf("score=%d",score);
}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = 1;
			break;
		}
	}
}
void Logic()
{
	int prevX = tailX[0],i;
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

	for (i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = 1;

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}
int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		}
	return 0;
}
