#include <stdio.h>
#include <stdlib.h>

char tablica[9][9];

void plansza(void)
{
	int i, j, l;
	int k = 1;

	for (l = 1; l <= 3; l++)
	{

		for (j = 1; j <= 3; j++)
		{
			for (i = 1; i <= 9; i++)
			{
				printf("[%c]", tablica[i - 1][k - 1]);
				if (i % 3 == 0)
				{
					printf("  ");
				}
				if (i % 9 == 0)
				{
					printf("\n");
					k++;
				}

			}

		}
		printf("\n");
	}
}

void koniec(void)
{
	int a;
	printf("\n-----Wyjscie z programu-[1]-----[2]-Reset planszy-----\n");
	scanf_s("%i", &a);
	switch (a)
	{
	case 1:
		{
			exit(0);
		}
	case 2:
	{
		for (int j = 0; j <= 8; j++)
		{
			for (int i = 0; i <= 8; i++)
			{
				tablica[i][j] = NULL;
			}
		}
		system("cls");
		plansza();
	}

	}
}


void ruch(void)
{
	int i;
	int a, b, g, h, c, d, e, f;
	for (i = 1; i <= 81; i++)
	{
		if (i == 1)
		{
			do
			{
				printf("Zaczynamy od srodkowej tabelki, podaj kolumne:<1-3>");
				scanf_s("%i", &a);
				c = a;
				printf("Zaczynamy od srodkowej tabelki, podaj wiersz :<1-3>");
				scanf_s("%i", &b);
				printf("\n");
				d = b;

			} while (c <1 || c>3 || d<1 || d>3);

			tablica[c + 2][d + 2] = 'x';
			plansza();
		}
		else if (i != 1)
		{
			do {
				printf("podaj kolumne:<1-3>");
				scanf_s("%i", &g);
				e = g;
				printf("podaj wiersz:<1-3>");
				scanf_s("%i", &h);
				printf("\n");
				f = h;
			} while ((e <1 || e>3 || f<1 || f>3) || (tablica[((c - 1) * 3) + (e - 1)][((d - 1) * 3) + (f - 1)] == 'o' || tablica[((c - 1) * 3) + (e - 1)][((d - 1) * 3) + (f - 1)] == 'x'));

			tablica[((c - 1) * 3) + (e - 1)][((d - 1) * 3) + (f - 1)] = (i % 2 == 0) ? 'o' : 'x';
			plansza();
			c = g;
			d = h;
		}
		for (int j = 1; j <= 9; j++)
		{
			for (int i = 0; i <= 6; i = i + 3)
			{
				if (tablica[i][j - 1] == 'o' &&	tablica[i + 1][j - 1] == 'o' &&tablica[i + 2][j - 1] == 'o')
				{
					printf("Gracz %c Wygral!\n", tablica[i][j - 1]);
					c = 0;
					d = 0;
					koniec();
				}
				if (tablica[i][j - 1] == 'x' &&tablica[i + 1][j - 1] == 'x'&&tablica[i + 2][j - 1] == 'x')
				{
					printf("Gracz %c Wygral!\n", tablica[i][j - 1]);
					c = 0;
					d = 0;
					koniec();
				}
			}
		}
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 0; j <= 6; j = j + 3)
			{
				if (tablica[i - 1][j] == 'o' && tablica[i - 1][j + 1] == 'o' && tablica[i - 1][j + 2] == 'o')
				{
					printf("Gracz %c Wygral!\n", tablica[i - 1][j]);
					c = 0;
					d = 0;
					koniec();
				}
				if (tablica[i - 1][j] =='x' && tablica[i - 1][j + 1] =='x' && tablica[i - 1][j + 2]=='x')
				{
					printf("Gracz %c Wygral!\n", tablica[i - 1][j]);
					c = 0;
					d = 0;
					koniec();
				}
			}
		}
		/*for (int i = 0; i <= 8; i++)
		{
			for (int j = 0; j <= 8; j++)
			{
				if (tablica[i][j] == 'o' && tablica[i+1][j + 1] == 'o' && tablica[i+2][j + 2] == 'o')
				{
					printf("Gracz %c Wygral!\n", tablica[i - 1][j]);
					c = 0;
					d = 0;
					koniec();
				}
				if (tablica[i - 1][j] == 'x' && tablica[i - 1][j + 1] == 'x' && tablica[i - 1][j + 2] == 'x')
				{
					printf("Gracz %c Wygral!\n", tablica[i - 1][j]);
					c = 0;
					d = 0;
					koniec();
				}
			}
			
			}
			*/
	}
}
int main()
{
	printf("Gra kolko i krzyzyk: \n\n");
	plansza();
	ruch();
	system("PAUSE");
	return 0;
}