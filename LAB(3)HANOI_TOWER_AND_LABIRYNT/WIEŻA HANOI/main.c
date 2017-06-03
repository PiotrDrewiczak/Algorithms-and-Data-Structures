#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int i,n,a;

int wieza(int a,char b,char c,char d)
{
if(a<1)
{
	return 0;
}
	
else if(a>0)
	{	
	wieza(a-1,b,d,c);
	printf("%c ---> %c\n",b,d);
	wieza(a-1,c,b,d);
	}		
	
}

int main()
{
	printf("PROGRAM WIEZA HANOI!\nPODAJ ILOSC KRAZKOW:");
	scanf_s("%i",&n);
	a=pow(2,n)-1;
	printf("DLA N=%i KRAZKOW POTRZEBA %i RUCHOW!\n",n,a);
	wieza(n,'1','2','3');
	system("PAUSE");
	return 0;
}
