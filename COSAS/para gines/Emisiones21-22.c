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
void ranking(double suma[], int n, nombre nombreenergia[]);
void mesmax(data datos[], int cantidadenergias, nombre nombreenergia[]);
void diferencias(data datos[],int cantidadenergias,nombre nombreenergia[]);
const char* obtmes(int mes);
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
            //Creo que sé por qué el carbón se guarda mal. Mañana en llamada te explico. Creo que tengo la solución pero se tarda un poquillo.
            fscanf(pf, "%[^,]s", nombreenergia[i].nombre);
            for (j=0; j<24; j++) // 24 datos en cada energia
            {
                fscanf(pf, ",%lf", &datos[j].energia2[i]);
		    }
        }
        fclose(pf);

        			int panel;
					int cantidadenergia=9;
					double suma[9] = {0,0,0,0,0,0,0,0,0};
					double suma2[9] = {0,0,0,0,0,0,0,0,0};
					printf("Opciones a realizar\n1-Clasificacion produccion de CO2\n2-Maximo emision alcanzado por mes\n3-Progreso respecto CO2\n");
					scanf("%i",&panel);
					switch (panel)
					{
					case 1:
							{

								 for (i = 0; i < cantidadenergias; i++)
							        {
							            for (j = 0; j < 12; j++)
							            {
							                suma[i] += datos[j].energia2[i];
							            }
							        }
							        ranking(suma, cantidadenergias, nombreenergia);
						            printf("Ranking de emisiones de mayor a menor 2021:\n");

						            for (i = 0; i < cantidadenergias; i++)
						            {
						                printf("%s:%.3f", nombreenergia[i].nombre, suma[i]);    // aqui el carbon me sale pegado a lo otro
                                                                                                // He puesto un comentario donde creo que está el "error"
						            }

						            pf=fopen("C:/Users/jiaha/Downloads/asd2.csv","r");
                                    if (pf==NULL)
                                    {
                                        printf("Error al abrir el archivo");
                                        return -1;
                                    }
                                    else
                                    {
                                        contador=0;
                                        printf("El archivo se ha abierto correctamente\n");
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
            //Creo que sé por qué el carbón se guarda mal. Mañana en llamada te explico. Creo que tengo la solución pero se tarda un poquillo.
                                            fscanf(pf, "%[^,]s", nombreenergia[i].nombre);
                                                for (j=0; j<24; j++) // 24 datos en cada energia
                                                {
                                                    fscanf(pf, ",%lf", &datos[j].energia2[i]);
                                                }
                                        }


						        for (i = 0; i < cantidadenergias; i++)//apartir de aqui el 2022 empieza a fallar
							        {
							            for (j =12; j < 24; j++) //2 errores, el primero sé solucionarlo pero el segundo es una fumada: mañana en llamada te cuento.
							            {
							                suma2[i] += datos[j].energia2[i];
							            }
							        }


							        ranking(suma2, cantidadenergias, nombreenergia);
						            printf("\n\nRanking de emisiones de mayor a menor 2022:\n");
						            for (i = 0; i < cantidadenergias; i++)
						            {
						                printf("%s:%.3f", nombreenergia[i].nombre, suma2[i]);
						            }
					break;
						}
					case 2:
						{
							mesmax(datos, cantidadenergias, nombreenergia); //falta 2022
        			break;
						}
					case 3:
						{
							diferencias(datos,cantidadenergias,nombreenergia); //falta 2022
					break;
						}
					}
	fclose(pf);
	return 0;
	}
}
}

void ranking(double suma[], int n, nombre nombreenergia[])
{
    int i, j;
    double temp;
    nombre tempNombre;

    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (suma[j]<suma[j+1])
            {
                temp=suma[j];
                suma[j]=suma[j+1];
                suma[j+1]=temp;

                tempNombre=nombreenergia[j];
                nombreenergia[j]=nombreenergia[j+1];
                nombreenergia[j+1]=tempNombre;
            }
        }
    }
}
void mesmax(data datos[],int cantidadenergias,nombre nombreenergia[])
{
    int i, j;
    double maxEmision;
    int maxMes;
    printf("EN 2021\n");
    for (i=0;i<cantidadenergias;i++)
	{
        maxEmision=datos[0].energia2[i];
        maxMes = 0;

        for(j=0;j<12;j++)
		{
            if (datos[j].energia2[i] > maxEmision)
			{
                maxEmision = datos[j].energia2[i];
                maxMes = j;
            }
        }

        printf("%s", nombreenergia[i].nombre);
        printf("\nMes con mayor emision: %s\n", obtmes(maxMes+1));
        printf("Emision: %.3f\n", maxEmision);
    }
    printf("EN 2022\n");
    for (i=0;i<cantidadenergias;i++)
	{
        maxEmision=datos[12].energia2[i];
        maxMes = 0;

        for(j=12;j<24;j++)
		{
            if (datos[j].energia2[i] > maxEmision)
			{
                maxEmision = datos[j].energia2[i];
                maxMes = j;
            }
        }
        printf("%s", nombreenergia[i].nombre);
        printf("\nMes con mayor emision: %s\n", obtmes(maxMes-11));
        printf("Emision: %.3f\n", maxEmision);
    }
}
const char* obtmes(int mes)
{
    switch (mes)
	{
        case 1: return "Enero";
        case 2: return "Febrero";
        case 3: return "Marzo";
        case 4: return "Abril";
        case 5: return "Mayo";
        case 6: return "Junio";
        case 7: return "Julio";
        case 8: return "Agosto";
        case 9: return "Septiembre";
        case 10: return "Octubre";
        case 11: return "Noviembre";
        case 12: return "Diciembre";
        default: return "Mes inválido";
    }
}
void diferencias(data datos[],int cantidadenergias,nombre nombreenergia[])
{
	int i,j;
	double diferencia;
	printf("La produccion de CO2 de:\n");
	printf("EN 2021\n");
	for(i=0;i<cantidadenergias;i++)
	{
		if (datos[0].energia2[i]>datos[11].energia2[i])
		{
			diferencia=datos[0].energia2[i]-datos[11].energia2[i];
			printf("%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
		}
		else
		{
			diferencia=datos[11].energia2[i]-datos[0].energia2[i];
			printf("%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
		}
	}
	printf("\nEN 2022\n");
	for(i=0;i<cantidadenergias;i++)
	{
		if (datos[12].energia2[i]>datos[23].energia2[i])
		{
			diferencia=datos[12].energia2[i]-datos[23].energia2[i];
			printf("%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
		}
		else
		{
			diferencia=datos[23].energia2[i]-datos[12].energia2[i];
			printf("%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
		}
	}
}
