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
	double energia3[17];
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
void calcularPorcentaje(data datos[], int cantidadenergias,double suma2[],nombre nombreenergia[],float total);
void calcularPorcentaje2(data datos[], int cantidadenergias,double suma2[],nombre nombreenergia[],float total);
int main()
{
	nombre nombreenergia[18];
	FILE *o;

	dia fecha={{1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12},
	{2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022}};
	o=fopen("C:/Users/jiaha/Downloads/Estructura_Generacion_Tecnologias_2019-2020.csv","r");
	if (o==NULL)
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
		int cantidadenergias=17;
		while(fscanf(o,"%c",&x)!=EOF)
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
            fscanf(o, "%[^,]s", nombreenergia[i].nombre);
            for (j=0; j<24; j++) 
            {
                fscanf(o, ",%lf", &datos[j].energia3[i]);
		    }
        }
        int panel;
					int cantidadenergia=17;
					double suma[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
					double suma2[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
					printf("Opciones a realizar\n1-Clasificacion produccion de Energia\n2-Energia representado en porcentaje\n3-Progreso respecto CO2\n");
					scanf("%i",&panel);
					switch (panel)
					{
					case 1:
							{

								 for (i = 0; i < cantidadenergias; i++)
							        {
							            for (j = 0; j < 12; j++)
							            {
							                suma[i] += datos[j].energia3[i];
							            }
							        }
							        ranking(suma, cantidadenergias, nombreenergia);
						            printf("Ranking de emisiones de mayor a menor 2019:\n");

						            for (i = 0; i < cantidadenergias; i++)
						            {
						                printf("%s:%.3f GWh", nombreenergia[i].nombre, suma[i]);    // aqui el carbon me sale pegado a lo otro
                                                                                                // He puesto un comentario donde creo que está el "error"
						            }

						            o=fopen("C:/Users/jiaha/Downloads/Estructura_Generacion_Tecnologias_2019-2020.csv","r");
                                    if (o==NULL)
                                    {
                                        printf("Error al abrir el archivo");
                                        return -1;
                                    }
                                    else
                                    {
                                        contador=0;
                                        printf("\nEl archivo se ha abierto correctamente\n");
                                        while(fscanf(o,"%c",&x)!=EOF)
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
            
                                            fscanf(o, "%[^,]s", nombreenergia[i].nombre);
                                                for (j=0; j<24; j++) // 24 datos en cada energia
                                                {
                                                    fscanf(o, ",%lf", &datos[j].energia3[i]);
                                                }
                                        }


						        for (i = 0; i < cantidadenergias; i++)//apartir de aqui el 2022 empieza a fallar
							        {
							            for (j =12; j < 24; j++) //2 errores, el primero sé solucionarlo pero el segundo es una fumada: mañana en llamada te cuento.
							            {
							                suma2[i] += datos[j].energia3[i];
							            }
							        }


							        ranking(suma2, cantidadenergias, nombreenergia);
						            printf("\n\nRanking de emisiones de mayor a menor 2020:\n");
						            for (i = 0; i < cantidadenergias; i++)
						            {
						                printf("%s:%.3fGWh", nombreenergia[i].nombre, suma2[i]);
						            }
									break;
        							fclose(o);
									}
							}
					case 2:
							{
								o=fopen("C:/Users/jiaha/Downloads/Estructura_Generacion_Tecnologias_2019-2020.csv","r");
							if (o==NULL)
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
								while(fscanf(o,"%c",&x)!=EOF)
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
								for (i=0; i<16; i++)
						        {
						            fscanf(o, "%[^,]s", nombreenergia[i].nombre);
						            for (j=0; j<24; j++) 
						            {
						                fscanf(o, ",%lf", &datos[j].energia3[i]);
								    }
								double sum3[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
								double suma4[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
								
								 for (i = 0; i < 16; i++)
							        {
							            for (j = 0; j < 12; j++)
							            {
							                suma2[i] += datos[j].energia3[i];
							            }
							        }
						            o=fopen("C:/Users/jiaha/Downloads/Estructura_Generacion_Tecnologias_2019-2020.csv","r");
                                    if (o==NULL)
                                    {
                                        printf("Error al abrir el archivo");
                                        return -1;
                                    }
                                    else
                                    {
                                        contador=0;
                                        printf("\nEl archivo se ha abierto correctamente\n");
                                        while(fscanf(o,"%c",&x)!=EOF)
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
                                        for (i=0; i<16; i++)
                                        {
            
                                            fscanf(o, "%[^,]s", nombreenergia[i].nombre);
                                                for (j=0; j<24; j++) // 24 datos en cada energia
                                                {
                                                    fscanf(o, ",%lf", &datos[j].energia3[i]);
                                                }
                                        }


						        		for (i = 0; i < cantidadenergias; i++)//apartir de aqui el 2022 empieza a fallar
							        	{
							            for (j =12; j < 24; j++) //2 errores, el primero sé solucionarlo pero el segundo es una fumada: mañana en llamada te cuento.
							            {
							                suma4[i] += datos[j].energia3[i];
							            }
							        	}
									}
									}
									}
									calcularPorcentaje(datos,cantidadenergias,suma2,nombreenergia,260011.185);
									calcularPorcentaje2(datos,cantidadenergias,suma2,nombreenergia,276412.681);
									break;
        							fclose(o);
								}
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
void calcularPorcentaje(data datos[], int cantidadenergias,double suma2[],nombre nombreenergia[],float total)
{
    double porcentajes[17];

    

    for (int i = 0; i < 16; i++)
    {
        double porcentaje = (datos[0].energia3[i] + datos[1].energia3[i] + datos[2].energia3[i] + datos[3].energia3[i] + datos[4].energia3[i] +
                            datos[5].energia3[i] + datos[6].energia3[i] + datos[7].energia3[i] + datos[8].energia3[i] + datos[9].energia3[i] +
                            datos[10].energia3[i] + datos[11].energia3[i]) / total * 100.0;

        porcentajes[i] = porcentaje;
    }

    printf("\n\tPorcentaje de cada energía en el total de 2019:\n");
    for (int i = 0; i < 15; i++)
    {
        printf("%s: %.2f%%\n", nombreenergia[i].nombre, porcentajes[i]);
    }
}
void calcularPorcentaje2(data datos[], int cantidadenergias,double suma2[],nombre nombreenergia[],float total)
{
    double porcentajes[17];

    

    for (int i = 0; i < 16 ;i++)
    {
        double porcentaje = (datos[12].energia3[i] + datos[13].energia3[i] + datos[14].energia3[i] + datos[15].energia3[i] + datos[16].energia3[i] +
                            datos[17].energia3[i] + datos[18].energia3[i] + datos[19].energia3[i] + datos[20].energia3[i] + datos[21].energia3[i] +
                            datos[22].energia3[i] + datos[23].energia3[i]) / total * 100.0;

        porcentajes[i] = porcentaje;
    }

    printf("\n\tPorcentaje de cada energía en el total de 2020:\n");
    for (int i = 0; i < 15; i++)
    {
        printf("%s: %.2f%%\n", nombreenergia[i].nombre, porcentajes[i]);
    }
}
