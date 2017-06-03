#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define N 50


int tablica[N];
int tablicap[N];
int tablicap2[N];
int i;
int j = 1;
int pomocnicza, pomocnicza2;
int licznik = 0, licznik2 = 0, licznik3 = 0;

void print(void)
{
	FILE *plik;
	plik = fopen("laborka.txt", "w");
	fprintf(plik,"[#]-SORTOWANIE BABELKOWE!-\n\n");
	fprintf(plik,"TWOJE ELEMENTY W TABLICY:");
	for (i = 0; i < N; i++)
		fprintf(plik," %i ", tablica[i]);
	fprintf(plik,"\nWYKONANO %i PRZESUNIEC\n", licznik);
	fprintf(plik,"\n[#]-SORTOWANIE SELECTION!-\n\n");
	fprintf(plik,"TWOJE ELEMENTY W TABLICY:");
	for (i = 0; i < N; i++)
		fprintf(plik," %i ", tablicap[i]);
	fprintf(plik,"\nWYKONANO %i PRZESUNIEC\n\n", licznik2);
	fprintf(plik,"\n[#]-SORTOWANIE INSERTION!-\n\n");
	fprintf(plik,"TWOJE ELEMENTY W TABLICY:");
	for (i = 0; i < N; i++)
		fprintf(plik," %i ", tablicap2[i]);
	fprintf(plik,"\nWYKONANO %i PRZESUNIEC\n\n", licznik3);
	fclose(plik);
}		


void insertion(int a)
{
	for (i = 1; i < N; i++)
	{
		pomocnicza = tablicap2[i];
		for (j = i; j > 0; j--)
			if (pomocnicza < tablicap2[j - 1])
			{
				tablicap2[j] = tablicap2[j - 1];
				tablicap2[j - 1] = pomocnicza;
				licznik3++;
			}
			else
			{
				tablicap2[j] = pomocnicza;
				j = 0;
			}

	}
	int czas5 = GetTickCount();
	printf("CZAS WYKONYWANIA INSERTION SORT: %i milisekund\n", czas5 - a);
}

void selection(int a)
{	
	for (j = N-1; j > -1; j--)
		{
			for (i = 0; i < j + 1; i++)
			{
				if (pomocnicza <= tablicap[i])
				{
					pomocnicza = tablicap[i]; //SZUKAMY NAJWIEKSZEGO ELEMENTU BADZ ROWNEGO!
					pomocnicza2 = i; // MIEJSCE NAJWIEKSZEGO ELEMENTU W TABLICY!

				}
			}
			
				if (pomocnicza == tablicap[j])
				{
					licznik2 = licznik2 + 0;
				}

				else
				{	
					tablicap[pomocnicza2] = tablicap[j];
					tablicap[j] = pomocnicza;
					licznik2 = licznik2 + 1;
				}
				pomocnicza = 0;
		}
	int czas4 = GetTickCount();
	printf("CZAS WYKONYWANIA SELECTION SORT: %i milisekund\n", czas4 - a);

}

void bubble(int a)
{
	for (j = 0; j < N; j++)
	for (i = 0; i < N-1; i++)
		if (tablica[i+1] < tablica[i])
		{
			pomocnicza = tablica[i+1];
			tablica[i+1] = tablica[i];
			tablica[i] = pomocnicza;
			pomocnicza = 0;
			licznik++;
		}
	int czas3 = GetTickCount();
	printf("CZAS WYKONYWANIA BUBBLE SORT: %i milisekund\n", czas3 - a);
	}

void tabliczka(void)
{
	for (i = 0; i < N; i++)
	{ 
		tablicap[i] = tablica[i];
		tablicap2[i] = tablica[i];
	}
}

void random(void)
{
	FILE *plik;
	plik = fopen("wejscie.txt", "w");
	srand(time(NULL));
	fprintf(plik,"TWOJE WYLOSOWANE LICZBY:\n");
	for (i = 0; i < N; i++)
	{
		tablica[i] = rand()%10000;
		fprintf(plik,"%d,", tablica[i]);
	}
	fprintf(plik,"\n");
	fclose(plik);
	tabliczka();
}


int main()
{
	random();
	int czas = GetTickCount();
	bubble(czas);
	int czas1 = GetTickCount();
	selection(czas1);
	int czas2 = GetTickCount();
	insertion(czas2);
	print();
	system("PAUSE");
	return 0;
}