#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{

	int hora;
	int real;
	int prevista;
	int programada;
}	energia;
energia *enero;
void vaciar(char temp[]);
void copiar(char temp[],int i);
int main ()
{
	char temp [1000];
	int j,i;
	int cont=0;
	char aux;
	FILE *f;
	f= fopen("C:/Users/jiaha/Downloads/ENERO/Enero.txt","r");
	if (f==NULL)
	{
		printf("Error al abrir fichero\n");
		return -1;
	}
	while (!feof(f))
	{
		fgets(temp,1000,f);
		cont++;
	}
	rewind(f);
	enero=(energia*)malloc(cont*sizeof(energia));
	if(enero==NULL)
	{
		printf("Error de memoria");
		return -1;
	}
	for(i=0;!feof(f);i++)
	{
		aux='0';
		vaciar (temp);
		for(j=0;aux!=',';j++)
		{
			aux=fgetc(f);
			if(aux!=',')
			{
				temp[j]=aux;
			}
		}
		copiar(temp,i);
		fgets(temp,50,f);
		enero[i].real=atoi(temp);
		printf("Hora %c real %i",enero[i].hora,enero[i].real);
		}
	return 0;

}
void vaciar(char temp[])
{
	int i;
	for(i=0;i<1000;i++)
	{
		temp[i]='\0';
	}
}
void copiar(char temp[],int i)
{
	int N=strlen(temp)+1;
	enero[i].hora=(char*)malloc(N*sizeof(char));
	if(enero[i].hora==NULL)
	{
		printf("error\n");
		return -1;
	}
	strcpy(enero[i].hora,temp);
}
