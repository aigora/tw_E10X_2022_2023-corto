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
	double emision[9];
}data;
typedef struct resultadosguardados
{
	nombre energia;
	dia fecha;
	double resultados;
}resultadosguardados;
void minimo(data datos[], int cantidadenergias, nombre nombreenergia[]);
const char* obtmesano(int mes);
int main()
{
	nombre nombreenergia[9];
	FILE *g;

	dia alarma={{1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12},
	{2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2020,2020,2020,2020,2020,2020,2020,2020,2020,2020,2020,2020}};
	g=fopen("C:/Users/jiaha/Downloads/Estado_Alarma2.csv","r");
	if (g==NULL)
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
		int conta=0;
		char y;
		int cantidadenergias=9;
		while(fscanf(g,"%c",&y)!=EOF)
		{
			if(y=='\n')
			{
				conta++;
			}
			if (conta==5)
			{
			break;
			}

		}
		
		for (i=0; i<cantidadenergias; i++)
        {
            fscanf(g, "%[^,]s", nombreenergia[i].nombre);
            for (j=0; j<24; j++)
            {
                fscanf(g, ",%lf",&datos[j].emision[i]);
		    }
        }
        minimo(datos,cantidadenergias,nombreenergia);
       
        fclose(g);
    }
}
void minimo(data datos[], int cantidadenergias, nombre nombreenergia[])
{
    int i, j, min;
    for (i = 0; i < cantidadenergias; i++) {
        printf("\n%s\n", nombreenergia[i].nombre);
        double min_emision = datos[0].emision[i];
        min = 0;
        
        for (j = 1; j < 24; j++) {
            if (datos[j].emision[i] < min_emision) {
                min_emision = datos[j].emision[i];
                min = j;
            }
        }
        
        printf("Mes con menor emisión: %s\n", obtmesano(min + 1));
        printf("Emisión mínima: %.3f\n", min_emision);
        
        double max_emision = datos[0].emision[i];
        int max = 0;
        
        for (j = 1; j < 24; j++) {
            if (datos[j].emision[i] > max_emision) {
                max_emision = datos[j].emision[i];
                max = j;
            }
        }
        
        printf("Mes con mayor emisión: %s\n", obtmesano(max + 1));
        printf("Emisión máxima: %.3f\n", max_emision);
        
        double diferencia = max_emision - min_emision;
        printf("Diferencia: %.3f\n", diferencia);
    }
}
const char* obtmesano(int mes)
{
    switch (mes)
	{
        case 1: return "Enero 2019";
        case 2: return "Febrero 2019";
        case 3: return "Marzo 2019";
        case 4: return "Abril 2019";
        case 5: return "Mayo 2019";
        case 6: return "Junio 2019";
        case 7: return "Julio 2019";
        case 8: return "Agosto 2019";
        case 9: return "Septiembre 2019";
        case 10: return "Octubre 2019";
        case 11: return "Noviembre 2019";
        case 12: return "Diciembre 2019";
        case 13: return "Enero 2020";
        case 14: return "Febrero 2020";
        case 15: return "Marzo 2020";
        case 16: return "Abril 2020";
        case 17: return "Mayo 2020";
        case 18: return "Junio 2020";
        case 19: return "Julio 2020";
        case 20: return "Agosto 2020";
        case 21: return "Septiembre 2020";
        case 22: return "Octubre 2020";
        case 23: return "Noviembre 2020";
		case 24: return "Diciembre 2020";
        default: return "Mes inválido";
    }
}
