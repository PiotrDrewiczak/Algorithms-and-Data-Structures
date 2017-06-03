#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100


int main() {

	int licznik_wzoru;
	char w[MAX] = { 'A', 'B', 'C', 'D', 'A', 'B', 'G' };
	int t[MAX] = { 0 };
	licznik_wzoru = 7;
	t[0] = 0;


	int i = 1;
	int j = 0;
	do {
		if (w[i] == w[j])
		{
			t[i] = j + 1;
			j = j + 1;
			i++;
		}
		else if (w[i] != w[j] && j == 0)
		{
			t[i] = 0;   //i wykonaj kolejnπ iteracjÍ dla i
			i++;
		}
		else if (w[i] != w[j] && j > 0) {
			j = t[j - 1];    // i sprawdü poprzednie punkty

		}


	} while (i != licznik_wzoru);



	printf("TABLICA PREFIKSO-SUFIKSOW:");
	for (int i = 0; i<licznik_wzoru; i++)
	{
		printf("%i", t[i]);
	}
	printf("\n\n");


	int k = 0, l = 0;
	int dlugosc_tekstu = 15;
	char tekst[MAX] = { 'A', 'B', 'C', 'E', 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D', 'A', 'B', 'G' };
	printf("TWOJ TEKST TO:");
	for (int i = 0; i <dlugosc_tekstu; i++)
		printf("%c", tekst[i]);

	printf("\nTWOJ WZOR TO:");
	for (int i = 0; i < licznik_wzoru; i++)
		printf("%c", w[i]);

	printf("\n");
	while (k + l < dlugosc_tekstu)
	{
		if (w[k] == tekst[k + l])
		{
			if (k == licznik_wzoru - 1)
			{
				printf("ZNALEZIONO WZOR!\n");
				break;
			}
			else  k = k + 1;
		}
		else
		{
			if (k > 0)
			{
				l = l + k - t[k - 1];
				k = t[k - 1];
			}
			else
			{
				k = 0;
				l = l + 1;
			}
		}
	}
	printf("SZUKANY WZOR ZNAJDUJE SIE NA %i MIEJSCU\n", l);





	system("pause");
	return 0;
}


