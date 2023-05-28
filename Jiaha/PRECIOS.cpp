#include <stdio.h>
#include <stdlib.h>

typedef struct nombre
{
    char nombre[50];
    int ano[6];
} nombre;

typedef struct dia
{
    int mes[24];
    int year[24];
} dia;

typedef struct data
{
    double energia2[9];
} data;

typedef struct resultadosguardados
{
    nombre energia;
    dia fecha;
    double resultados;
} resultadosguardados;

void ranking(double suma[], int n, nombre nombreenergia[]);
void mesmax(data datos[], int cantidadenergias, nombre nombreenergia[]);
void diferencias(data datos[], int cantidadenergias, nombre nombreenergia[]);
const char *obtmes(int mes);
void analizarVariacion(float precios[], int numAnos);
void calcularPromedio(float precios[], int numAnos);
int main() 
{
    float precios[6] = {60.6,64.4,53.41, 40.38, 118.69, 204.35};
    int numAnos = sizeof(precios) / sizeof(float);
	printf("Variacion de coste\n");
    analizarVariacion(precios, numAnos);
	printf("\nLa disminución en los precios de 2019 a 2020 se debió al impacto de la pandemia del COVID-19.\n");
    printf("El aumento en los precios de 2021 a 2022 se debió a la guerra en Ucrania y sus efectos en el mercado.\n\n");
    printf("Promedio\n");
    calcularPromedio(precios, numAnos);
    return 0;
}
void analizarVariacion(float precios[], int numAnos) 
{
    float variacionTotal=0.0;

    for (int i = 1; i < numAnos; i++) {
        float variacion = ((precios[i]-precios[i-1]) / precios[i - 1]) * 100;
        variacionTotal += variacion;

        if (variacion < 0) 
		{
            printf("El coste de MWh %d a %d: ha dismunuido %.2f%%\n", 2017 + i - 1, 2017 + i, -variacion);
        } else {
            printf("El coste de MWh %d a %d: ha aumentado %.2f%%\n", 2017 + i - 1, 2017 + i, variacion);
        }
    }

    if (variacionTotal < 0) 
	{
        printf("El coste de MWh total ha disminuido %.2f%%\n", -variacionTotal);
    } else {
        printf("El coste de MWh total ha aumentado %.2f%%\n", variacionTotal);
    }
}
void calcularPromedio(float precios[], int numAnos) 
{
    float sumaPrecios = 0.0;
    for (int i=0;i<numAnos;i++) 
	{
        sumaPrecios += precios[i];
    }
    float promedioPrecios = sumaPrecios / numAnos;
    printf("El promedio de los precios es: %.2f euro/MWh\n", promedioPrecios);
}
