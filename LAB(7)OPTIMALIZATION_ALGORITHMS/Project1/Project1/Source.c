#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
int tablica1[MAX];

void f_max(int z, int c)
{
	int licznik1 = 1;
	int licznik2 = 1;
	int pomocnicza = 0;
	int licznikpomoc = 1;
	for (int i = 1; i < MAX; i++)
	{
		if ((tablica1[i] - c)>z)
		{
			z = tablica1[i] - c;
			licznik1 = i + 1;
			pomocnicza = c;
		}
		else if (tablica1[i]<c)
		{
			licznikpomoc = licznik2;
			c = tablica1[i];
			licznik2 = i + 1;
		}

	}
	if (licznik2 > licznik1)
	{
		c = pomocnicza;
		licznik2 = licznikpomoc;
	}

	printf("NAJWIEKSZY ZYSK:%i\nOSIAGNIEMY GO KUPUJAC AKCJE DNIA %i ZA %i I SPRZEDAJAC DNIA %i ZA %i\n", z, licznik2, c, licznik1, z + c);


}

int main()
{
	int z = 0;
	srand(time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		tablica1[i] = rand() % 100;
		printf("%i ", tablica1[i]);
	}
	printf("\n");
	int c = tablica1[0];
	f_max(z, c);

	system("PAUSE");
	return 0;
}