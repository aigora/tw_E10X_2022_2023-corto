#include <stdio.h>
#include <stdlib.h>
typedef struct nombre
{
	char nombre[50];
}nombre;
typedef struct dia
{
	int mes[24];
	int year[24];
}dia;
typedef struct data
{
	double energia2[9];
}data;
typedef struct resultadosguardados
{
	nombre energia;
	dia fecha;
	double resultados;
}resultadosguardados;
int main()
{
	nombre nombreenergia[9];
	FILE *pf;
	dia fecha={{1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12},
	{2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022}};
	pf=fopen("C:/Users/jiaha/Downloads/asd2.csv","r");
	if (pf==NULL)
	{
		printf("Error al abrir el archivo");
		return -1;
	}
	else
	{
		printf("El archivo se ha abierto correctamente\n");
		data datos[24];
		int i=0;
		int j=0;
		int contador=0;
		char x;
		int cantidadenergias=9;
		while(fscanf(pf,"%c",&x)!=EOF)
		{
			if(x=='\n')
			{
				contador++;
			}
			if (contador==5)
			{
			break;
			}
		}
		for (i=0; i<cantidadenergias; i++)  
        {
            fscanf(pf, "%[^,]s", nombreenergia[i].nombre);
            for (j=0; j<24; j++) // 24 datos en cada energia 
            {
                fscanf(pf, ",%lf", &datos[j].energia2[i]);
		    }
        }
        
        			int panel;
					int cantidadenergia=9;
					printf("Opciones a realizar\n1-Clasificacion produccion de CO2");
					scanf("%i",&panel);
					switch (panel)
					{
					case 1:
						float suma=0.0;
						for(i=0;i<cantidadenergias;i++)
						{
							for(j=0;j<=11;j++)
						{
						suma += datos[j].energia2[i];
							printf("%f\n",suma);
						}
						}
					break;
					}
	}
	fclose(pf);
	return 0;
}
    
