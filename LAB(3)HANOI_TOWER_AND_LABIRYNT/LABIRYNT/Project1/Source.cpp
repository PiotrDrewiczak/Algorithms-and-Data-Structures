#include <stdio.h>
#include <stdlib.h>
#include <cstdbool>


char labirynt[6][6] = { { 3, 1, 0, 0, 1, 1 }, { 0, 1, 0, 0, 1, 1 }, { 0, 1, 0, 1, 1, 0 }, { 0, 1, 1, 0, 1, 1 }, { 1, 0, 1, 0, 0, 0 }, { 1, 0, 1, 1, 1, 4 } };
int licznik = 0;
void funkcja(void)
{

	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			printf("%i", labirynt[j][i]);
		}
		printf("\n");
	}
}

int lab(int x, int y)
{
	licznik++;
	labirynt[x][y] = 2; // SCIEZKA PRZEBYTA
	if (x<3 || x>-1 && y<3 || y>-1)
	{
		if (labirynt[x + 1][y] == 3)
		{
			return lab(x + 1, y);
		}
		else if (labirynt[x][y + 1] == 3)
		{
			return lab(x, y + 1);
		}
		else if (labirynt[x - 1][y] == 3)
		{
			return lab(x - 1, y);
		}
		else if (labirynt[x][y - 1] == 3)
		{
			return lab(x, y - 1);
		}
		else if (labirynt[x + 1][y] == 1)
		{
			return lab(x + 1, y);
		}
		else if (labirynt[x][y + 1] == 1)
		{
			return lab(x, y + 1);
		}
		else if (labirynt[x][y - 1] == 1)
		{
			return lab(x, y - 1);
		}
		else if (labirynt[x - 1][y] == 1)
		{
			return lab(x - 1, y);
		}
		else
		{
			if (labirynt[0][0] == 2)
			{
				printf("GRATULACJE,ZNALAZLES WYJSCIE W %i KROKACH\n\n", licznik - 1);
				return 1;
			}

			else
			{
				printf("PRZYKRO MI, WYKONALES %i KROKOW ALE NIE ZNALAZLES WYJSCIA\n\n", licznik - 1);
				return 1;
			}

		}

	}

	return 1;
}

int main()
{
	int a = 5;
	int b = 5;
	printf("PROGRAM LABIRYNT 3X3!\n\n[*]~~0~~OZNACZAJA SCIANE\n[*]~~1~~OZNACZAJA TRASE\n[*]~~2~~OZNACZAJA TRASE PRZEBYTA\n[*]~~3~~OZNACZA WYJSCIE\n[*]~~4~~OZNACZA MIEJSCE ROZPOCZECIA\n\n");
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			printf("%i", labirynt[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	lab(a, b);
	funkcja();
	system("PAUSE");
	return 0;
}