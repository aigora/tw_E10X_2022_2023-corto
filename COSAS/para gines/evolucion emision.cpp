#include <stdio.h>
#include <stdlib.h>
typedef struct tipo
{
	char tipo[50];
}tipo;
typedef struct sc
{
	double sc[29];
}sc;
typedef struct dia
{
	int dia[24];
	int year[24];
}dia;
typedef struct resultadosguardados
{
	tipo energia;
	dia fecha;
	double resultados;
}resultadosguardados;
int main()
{
	tipo tipoemision[2];
	FILE *f;
	dia fecha={{1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12},
	{2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022}};
	f=fopen("C:/Users/jiaha/OneDrive/Escritorio/TRABAJO INFO/Evolucion_Potencia2.csv","r");
	if (f==NULL)
	{
		printf("Error al abrir archivo");
		return -1;
	}
	else
	{
		printf("El archivo se ha abierto correctamente");
		sc datos[24];
		int i=0,j=0;
		int cont=0;
		char s;
		int estructura=2;
		while (fscanf(f,"%c",&s)!=EOF)
		{
			if(s=='\n')
			{
				cont++;
			}
			if(cont==5)
			{
				break;
			}
		}
		for(i=0;i<estructura;i++)
			fscanf(f,"%[^,]s",tipoemision[i].tipo);
			
	}
}
