#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define MAX 100

void menu1();
float oblicz[MAX];
char stos[MAX]="";
char wyjscie[MAX]="";
int liczba,i;
int wskaznik_stos=-1;
int wskaznik_wyjscie=-1;
char symbol,a;
int obliczenia=0;
float obliczenia2=0;
int j=0;


void obliczanie_wyrazenia(void)
{
	for (i=0;i<=wskaznik_wyjscie;i++)
			{
				if(wyjscie[i]!='+' || wyjscie[i]!='-' || wyjscie[i]!='*' || wyjscie[i]!='/')	
				{
					if (wyjscie[i]=='+')
					{
						obliczenia2=oblicz[j-2]+oblicz[j-1];
						oblicz[j-1]=0;
						oblicz[j-2]=obliczenia2;
						j=j-1;
					}
					else if (wyjscie[i]=='-')
					{
						
				obliczenia2=oblicz[j-2]-oblicz[j-1];
						oblicz[j-1]=0;
						oblicz[j-2]=obliczenia2;
						j=j-1;
					}
					else if (wyjscie[i]=='*')
					{
						
				obliczenia2=oblicz[j-2]*oblicz[j-1];
						oblicz[j-1]=0;
						oblicz[j-2]=obliczenia2;
						j=j-1;
					}
					else if (wyjscie[i]=='/')
					{
						
						obliczenia2=oblicz[j-2]/oblicz[j-1];
						oblicz[j-1]=0;
						oblicz[j-2]=obliczenia2;
						j=j-1;
					}
					else
					{	printf("PODAJ LICZBE:");
						scanf_s("%i",&obliczenia);	
						oblicz[j]=obliczenia;
						j=j+1;		
					}
				
				}
		
				
			}
		printf("WYNIKIEM TWOJEGO WYRAZENIA JEST:%f",oblicz[0]);
		printf("\n")	;				
system("PAUSE")	;
exit(0);
}

void koniec(void)
{
printf("ZAKONCZENIE WPROWADZANIA, ZRZUCAM WSZYSTKO DO WYJSCIA\n");
	for(i=MAX-1;i>-1;i--)
		{
			if(stos[i]!=0)
			{
			wskaznik_wyjscie=wskaznik_wyjscie+1;
			wyjscie[wskaznik_wyjscie]=stos[i];
			stos[i]=0;		
			}
		wskaznik_stos=-1;
		}
system("PAUSE");
}

void push_nawiasy(char x)
{
	if(wskaznik_stos==MAX-1)
		{
			printf("TWOJ STOS JEST PELNY!\n");
		}
	else if (x=='(')	
		{
			printf("DODANO ZNAK DO STOSU\n");
			wskaznik_stos=wskaznik_stos+1;
			stos[wskaznik_stos]=x;
			system("PAUSE");
		}
	else
		{
			printf("DODANO NAWIAS ZAMYKAJACY, WRZUCAM WNETRZE NAWIASU DO WYJSCIA!\n");
		do
		{
		a=0;
		wskaznik_wyjscie=wskaznik_wyjscie+1;
		a=stos[wskaznik_stos];
		wyjscie[wskaznik_wyjscie]=a;
		stos[wskaznik_stos]=0;
		wskaznik_stos=wskaznik_stos-1;
		}while(stos[wskaznik_stos]!='(');
		system("PAUSE");
		stos[wskaznik_stos]=0;
		wskaznik_stos=wskaznik_stos-1;
	}
	
}

void push_dodawanie_odejmowanie(char x)
{
if(wskaznik_stos==MAX-1)
	{
		printf("TWOJ STOS JEST PELNY!\n");
	}
else if(stos[wskaznik_stos]=='+' || stos[wskaznik_stos]=='-' || stos[wskaznik_stos]=='*' || stos[wskaznik_stos]=='/')
	{
		printf("TWOJ POPRZEDNI ZNAK MIAL TAKI SAM PRIORYTET LUB WYZSZY\nDODAJE POPRZEDNI ZNAK DO WYJSCIA A TEN W JEGO MIEJSCE\n");
		a=stos[wskaznik_stos];
		wskaznik_wyjscie=wskaznik_wyjscie+1;
		wyjscie[wskaznik_wyjscie]=a;
		stos[wskaznik_stos]=0;
		stos[wskaznik_stos]=x;
			
	}
else
	{
	wskaznik_stos=wskaznik_stos+1;
	stos[wskaznik_stos]=x;
	printf("DODANO ELEMENT DO STOSU\n");
	}
	system("PAUSE");
}


void push_mnozenie_dzielenie(char x)
{
	if(wskaznik_stos==MAX-1)
	{
		printf("TWOJ STOS JEST PELNY!\n");
	}
	else if(stos[wskaznik_stos]=='*' || stos[wskaznik_stos]=='/')
	{
		printf("TWOJ POPRZEDNI ZNAK MIAL TAKI SAM PRIORYTET LUB WYZSZY\nDODAJE POPRZEDNI ZNAK DO WYJSCIA A TEN W JEGO MIEJSCE\n");
		a=stos[wskaznik_stos];
		wskaznik_wyjscie=wskaznik_wyjscie+1;
		wyjscie[wskaznik_wyjscie]=a;
		stos[wskaznik_stos]=0;
		stos[wskaznik_stos]=x;
	}
	else
	{
	wskaznik_stos=wskaznik_stos+1;
	stos[wskaznik_stos]=x;
	printf("DODANO ELEMENT DO STOSU\n");	
	}
	
	a=0;
	system("PAUSE");
}

void push_symbol(char x)
{
	if(wskaznik_wyjscie==MAX-1)
	{
		printf("TWOJA TABLICA WYJSCIOWA JEST PELNA!\n");
	}
	
	else
	{
	wskaznik_wyjscie=wskaznik_wyjscie+1;
	wyjscie[wskaznik_wyjscie]=x;
	printf("DODANO ZNAK DO TABLICY WYJSCIOWEJ\n");
	}
	
	system("PAUSE");
}


void pop(void)
{
		if(wskaznik_stos==-1)
		{
			printf("TWOJ STOS JEST PUSTY\n");	
		}
		else
		{
			
			printf("ODJETO SYMBOL ZE STOSU I DODANO DO WYJSCIA\n");
			wskaznik_wyjscie=wskaznik_wyjscie+1;
			wyjscie[wskaznik_wyjscie]=stos[wskaznik_stos];
			stos[wskaznik_stos]=0;
			wskaznik_stos=wskaznik_stos-1;	
		}
	system("PAUSE");
}

void peek(void)
{
	if(wskaznik_stos==-1)
		{
			printf("TWOJ STOS JEST PUSTY\n");	
		}
	else
		{
			printf("TWOJ ELEMENT NA SZCZYCIE STOSU TO:%c\n",stos[wskaznik_stos]);
		}
		system("PAUSE");
}
void size(void)
{	


	printf("TWOJE ELEMENTY STOSU TO:");
			for(i=0;i<MAX;i++)
			{
			printf("%c",stos[i]);
			}
			
			printf("\nTWOJE ELEMENTY WYJSCIA TO:");
			for(i=0;i<MAX;i++)
			{
			printf("%c",wyjscie[i]);
			}
			printf("\n");
			
		system("PAUSE");
}
void empty(void)
{
	if(wskaznik_stos==-1)
		{
			printf("TWOJ STOS JEST PUSTY\n");	
		}
		else
		{
			printf("TWOJ STOS NIE JEST PUSTY\n");	
		}
system("PAUSE");
}

int main() 
{	
	menu1();
	system("PAUSE");
	return 0;
}
void menu1(void)
{	
do
{
	system("cls");
	printf("1-DODAJ ELEMENT DO STOSU");
	printf("\n2-ODEJMIJ ELEMENT ZE STOSU");
	printf("\n3-SPRAWDZ ELEMENTY STOSU");
	printf("\n4-SPRAWDZ CZY STOS JEST PUSTY");
	printf("\n5-WYSWIETL ELEMENT NA SZCZYCIE\n6-OBLICZ WYRAZENIE\n7-WYJSCIE\n-----------------------\n");
	printf("PODAJ LICZBE:");
	scanf_s("%i",&liczba);
	
	switch(liczba)
	{
		case 1:
			{
		printf("PODAJ SYMBOL:");
		scanf_s("%s",&symbol);
		if(symbol=='*' || symbol=='/')
			{
		push_mnozenie_dzielenie(symbol);	
			}
		else if(symbol=='+' || symbol=='-')
			{
			push_dodawanie_odejmowanie(symbol);
			}
		else if (symbol=='(' || symbol==')')
			{
				push_nawiasy(symbol);
			}
		else
			{
		push_symbol(symbol);
			}
		break;
			}
		case 2:
			{
			pop();
			break;
			}
		case 3:
			{			
			size();
			break;
			}
		case 4:
			{
			empty();
			break;		
			}
		case 5:
			{
			peek();	
			break;
			}
		case 6:
			{
			printf("OBLICZANIE WYRAZENIA!\n");
		obliczanie_wyrazenia();
		break;
			}
		case 7:
			{
			printf("NASTEPUJE WYJSCIA\n");
			system("PAUSE");
			exit(0);
			break;
			}
	}

}	while(liczba!=7);

}
