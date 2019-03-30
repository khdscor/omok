#include <stdio.h>
#include <windows.h>


#define X 20
#define Y 20
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define ESC 27

typedef struct XY {

	int x;

	int y;

}xy;

int ddd(xy ab, int GMap[Y][X], int turn, int i, int k);
void mapsetting();
void putt(int GMap[Y][X]);
void identify(xy, int map[Y][X], int);



gotoxy(int x, int y)

{

	COORD pos = {x,y};
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
int main()

{

	int map[Y][X] = { 0, };
	int z=0;


	printf("스페이스바를 누르면 게임이 시작된다\n");
	printf("ESC를 누르면 게임이 종료된다\n");
	reload:
	z= getch();
	if (z == SPACE)
	{
		system("cls");

		mapsetting();

		putt(map);
	}
	else
		goto reload;
}




void mapsetting(){
	int i = 0, k = 0;
	for (i = 0; i < Y; i++)
	{
		if (i == 0)
		{
			for (k = 0; k < X; k++)
				if (k == 0)
					printf("┌-");
				else if (k == X - 1)
				{
					printf("┐");
					break;
				}
				else
					printf("┬-");
		}
		else if (i == Y - 1) {
			for (k = 0; k < X; k++)
				if (k == 0)
					printf("└-");
				else if (k == X - 1)
				{
					printf("┘");
					break;
				}
				else
					printf("┴-");
		}
		else for (k = 0; k < X; k++)
			if (k == 0)
				printf("├-");
			else if (k == X - 1)
				printf("┤");
			else
				printf("┼-");
		printf("\n");
	}
}

void putt(int map[Y][X])

{

	char b = 0;
	int a;
	int turn = 1;

	xy ab = { 0,0 };
	gotoxy(ab.x * 2, ab.y);
	while (1)

	{
		a = kbhit();
		if (a)

		{

			b = getch();

			switch (b)

			{

			case LEFT:

				if (ab.x > 0)

					ab.x -= 1;

				break;

			case RIGHT:

				if (ab.x < X - 1)

					ab.x += 1;

				break;

			case UP:

				if (ab.y > 0)

					ab.y -= 1;

				break;

			case DOWN:

				if (ab.y < Y - 1)

					ab.y += 1;

				break;
				
			case SPACE:

				if (map[ab.y][ab.x] == 0)
				{
					if (turn == 1)
					{
						map[ab.y][ab.x] = 1;
						printf("○");
						identify(ab, map, turn);
						turn = 2;
					}
					else
					{
						map[ab.y][ab.x] = 2;
						printf("●");
						identify(ab, map, turn);
						turn = 1;
					}
				}

				break;

			case ESC:

				exit(1);

				break;

			}

			gotoxy(ab.x * 2, ab.y);

		}

	}

}

int ddd(xy ab, int map[Y][X], int turn, int i, int k)
{
	if (map[ab.y][ab.x] != turn) 
		return 0;
	if (i == 0) 
	{
		ab.y += k;
	}
	else if (i == 1)

	{
		ab.x += k;
	}

	else if (i == 2) 

	{
		ab.x += k;
		ab.y += k;
	}

	else 

	{
		ab.x += k;
		ab.y -= k;
	}
	return 1 + ddd(ab, map, turn, i, k);
}

void identify(xy ab, int map[Y][X], int turn)

{
	int i = 0, count = 0;

	for (i = 0; i < 4; i++)

	{

		count = 0;
		count += ddd(ab, map, turn, i, 1);
		count += ddd(ab, map, turn, i, -1);
		if (count == 6)
		{
			gotoxy(0, Y);
			if (turn == 1)
				printf(" 흑이");
			else
				printf(" 백이");

			printf(" 승리!");

			getch();

			exit(1);

		}

	}

}
