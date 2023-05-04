#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	int *dia;
	int hora;
	int real;
	int prevista;
	int programada;	
}	energia;
energia
int main ()
{
	int temp [50];
	char a;
	int cont=0;
	FILE *pf;
	pf= fopen("C:/Users/jiaha/Downloads/ENERO/Enero.txt","r");
	if (pf==NULL)
	{
		printf("Error al abrir fichero\n");
		return -1;
	}
	else
	{
		printf("El fichero se ha abierto correctamente\n");
		return 0;
	}	
	while (!feof(f))
	{
		fgets(temp;50,f);
		cont++;
	}
	return 0;
	
}

