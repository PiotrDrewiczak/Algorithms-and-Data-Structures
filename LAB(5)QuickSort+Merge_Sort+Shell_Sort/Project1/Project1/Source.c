#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <cstdbool>
#include <Windows.h>

int tablica[100000];
int tablica1[100000];
int tablica2[100000];
int tablica3[100000];
int tab[100000];
int licznik = 0;
double tablica_poteg[100];
double tablica_poteg2[100];

void zapis_do_pliku(int a)
{
	FILE *plik;
	plik = fopen("plik.txt", "w");
	fprintf(plik,"[&] LICZBY NIE POSORTOWANE\n");
	for (int i = 0; i < a; i++)
		fprintf(plik, "[%i]", tablica3[i]);
	fprintf(plik, "\n\n[&] LICZBY POSORTOWANE QUICKSORTEM\n");
	for (int i = 0; i < a; i++)
		fprintf(plik, "[%i]", tablica[i]);
	fprintf(plik, "\n\n[&] LICZBY POSORTOWANE MERGESORTEM\n");
	for (int i = 0; i < a; i++)
		fprintf(plik, "[%i]", tablica2[i]);
	fprintf(plik, "\n\n[&] LICZBY POSORTOWANE SHELLSORTEM\n");
	for (int i = 0; i < a; i++)
		fprintf(plik, "[%i]", tablica1[i]);

	fclose(plik);
}

void shellsort(int a)
{
	int j;
	int pomocnicza;
	int x;
	int licznik10 = 0;
	for (x = 1; pow(2.0, x) - 1 < a; x++);
	x--;

	for (; x > 0; x--)
	{
		int h = pow(2.0, x) - 1;

		printf("[&] TWOJE POTEGI DO SHELL SORT=%i\n", h);

		for (int i = h; i < a; i++)
		{
			pomocnicza = tablica1[i];

			for (j = i; j - h >= 0 && pomocnicza < tablica1[j - h]; j -= h)
			{
				tablica1[j] = tablica1[j - h];
				licznik10++;
			}
				

			tablica1[j] = pomocnicza;
		}
	}
	printf("[&] ILOSC ZAMIAN SHELL SORT :%i", licznik10);
}

int mergesort(int mala, int srodek, int duza)
{
	int licznik = 0;
	int i;
	int m;
	int k;
	int l;
	l = mala;
	i = mala;
	m = srodek + 1;

	while ((l <= srodek) && (m <= duza))
	{

		if (tablica2[l] <= tablica2[m]){
			tab[i] = tablica2[l];
			l++;
		}
		else{
			tab[i] = tablica2[m];
			m++;
		}
		i++;
	}

	if (l>srodek)
	{
		for (k = m; k <= duza; k++)
		{
			tab[i] = tablica2[k];
			i++;
			licznik++;
		}
	}
	else
	{
		for (k = l; k <= srodek; k++)
		{
			tab[i] = tablica2[k];
			i++;
			licznik++;
		}
	}

	for (k = mala; k <= duza; k++)
	{
		tablica2[k] = tab[k];
		licznik++;
	}
	return licznik;
}

int dzielenie2(int mala, int duza)
{
	int srodek;

	if (mala<duza)
	{
		srodek = (mala + duza) / 2;
		dzielenie2(mala, srodek);
		dzielenie2(srodek + 1, duza);
		mergesort(mala, srodek, duza);
	}
	return licznik;
}



int dzielenie(int tablica[], int p, int r) 
{
	
	int x = tablica[p];
	int i = p, j = r;
	int pomocnicza;
	while (true) 
	{
		while (tablica[j] > x)
			j--;
		while (tablica[i] < x)
			i++;
		if (i < j)
		{
			pomocnicza = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = pomocnicza;
			i++;
			j--;
			licznik++;
		}
		else
			return j;
	}

}

void quicksort(int tablica[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = dzielenie(tablica, p, r);
		quicksort(tablica, p, q);
		quicksort(tablica, q + 1, r); 
	}
}

/*void funkcja_poteg(int a)
{
	double i = 0;
	int li = -1;
	int licznik = 0;
	int k;
	while (tablica_poteg[li] < a)
	{
		li++;
		i++;
		tablica_poteg[li] = pow(2, i) - 1;
		licznik++;
	}
	printf("[&] TWOJE POTEGI DO SHELL SORT:");
	for (li = 0; li < licznik-1; li++)
		printf("%.lf ", tablica_poteg[li]);
	for (k=0,li = licznik-2; li > -1; li--,k++)
	{
		tablica_poteg2[k] = tablica_poteg[li];
	}

	printf("\n");
}
*/
void funkcja_random(int a)
{
	srand(time(NULL));
	printf("[&] LOSOWANIE LICZB Z ZAKRESU 0-10000:\n\n");
	for (int i = 0; i < a; i++)
	{
		int a = rand() % 10000;
		tablica[i] = a;
		tablica1[i] = a;
		tablica2[i] = a;
		tablica3[i] = a;
	}
}

int main()
{
	int n;
	int a;
	printf("[&] PODAJ ILOSC ELEMENTOW:");
	scanf_s("%i", &n);
	funkcja_random(n);
	int czas = GetTickCount();
	quicksort(tablica, 0, n - 1);
	int czas1 = GetTickCount();
	printf("[&] CZAS WYKONYWANIA QUICKSORT=%i\n[&] ILOSC ZAMIAN QUICKSORT=%i\n\n", czas1 - czas,licznik);
	int czas4 = GetTickCount();
	a=dzielenie2(0, n - 1);
	int czas5 = GetTickCount();
	printf("[&] CZAS WYKONYWANIA MERGE SORT=%i\n[&] ILOSC ZAMIAN MERGE SORT=%i\n\n", czas5 - czas4,a);
	int czas6 = GetTickCount();
	shellsort(n);
	int czas7 = GetTickCount();
	printf("\n[&] CZAS WYKONYWANIA SHELL SORT=%i", czas7 - czas6);
	zapis_do_pliku(n);
	system("PAUSE");
	return 0;
}