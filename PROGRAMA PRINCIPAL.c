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
	double energia2[9];
}data;
typedef struct resultadosguardados
{
	nombre energia;
	dia fecha;
	double resultados;
}resultadosguardados;
void minimo(data datos[], int cantidadenergias, nombre nombreenergia[]);
void promedioYporcentaje(data datos[], int cantidadenergias);
const char* obtmesano(int mes);
void ranking(double suma[], int n, nombre nombreenergia[]);
void mesmax(data datos[], int cantidadenergias, nombre nombreenergia[]);
void diferencias(data datos[],int cantidadenergias,nombre nombreenergia[]);
const char* obtmes(int mes);
void rankingEstructuras(double suma[], int n, nombre nombreenergia[]);
void diferenciasEstructuras(data datos[],int cantidadenergias,nombre nombreenergia[]);
int main()
{
	int eleccion;
	printf("Bienvenido al panel principal\n");
	while (eleccion!=4)
	{
	printf("\n\nQue desesa hacer\n");
	printf("1-Emisiones CO2\n");
	printf("2-Estructura de la potencia instalada con y sin CO2\n");
	scanf("\t%i",&eleccion);
	switch (eleccion)
	{
		case 1:
			{
				int COVID;
				printf("1-Emisiones periodo transicion COVID-19\n");
				printf("2-Emisiones estabilidad COVID\n");
				scanf("\t%i",&COVID);
				switch (COVID)
				{
					case 1:
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
					        }//escaneo
					        int vista;
					        printf("Opciones\n1-maximo minimo mes\n2-Comparacion Covid-19");
					        scanf("\t%i",&vista);
							        switch (vista)
							        {
									        case 1:
									        {
									       			minimo(datos,cantidadenergias,nombreenergia);
									       			int algo;
									       			printf("\nPara ver conclusion pulse 1\n");
									       			scanf("\t%i",&algo);
									       			switch(algo)
									       			case 1:
									       				{
									       					float diferenciatotal=datos[0].emision[7]-datos[15].emision[7];
									       					printf("\t\tLa comparacion de emision a principios de año comparado\ncon la llegada del estado de alarma la emision\nha bajado un total de  %.3f:",diferenciatotal);
									       			break;
														}
											break;
									        }
											case 2:
											{
												promedioYporcentaje(datos,cantidadenergias);
												break;
											}
											default:
                                            {
                                                printf("Opción no valida, volviendo al menu principal");
                                            }

							        fclose(g);
							    	}
						}
						}
						case 2:
						{
							nombre nombreenergia[9];
							FILE *pf;

							dia fecha={{1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12},
							{2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022}};
							pf=fopen("C:/Users/jiaha/OneDrive/Escritorio/TRABAJO INFO/asd2.csv","r");
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
						            for (j=0; j<24; j++)
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
												                printf("%s:%.3f", nombreenergia[i].nombre, suma[i]);
												            }

												            pf=fopen("C:/Users/jiaha/OneDrive/Escritorio/TRABAJO INFO/asd2.csv","r");
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

						                                            fscanf(pf, "%[^,]s", nombreenergia[i].nombre);
						                                                for (j=0; j<24; j++)
						                                                {
						                                                    fscanf(pf, ",%lf", &datos[j].energia2[i]);
						                                                }
						                                        }


												        for (i = 0; i < cantidadenergias; i++)
													        {
													            for (j =12; j < 24; j++)
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
													mesmax(datos, cantidadenergias, nombreenergia);

						        			break;
												}
											case 3:
												{
													diferencias(datos,cantidadenergias,nombreenergia);
											break;
												}
											}
											default:
                                            {
                                                printf("Opción no valida, volviendo al menu principal");
                                            }
											fclose(pf);
											}
											}
											}
    default:
        {
            printf("Opción no valida, volviendo al menu principal");
        }


	}//switch de covid
                                            case 2:
                                                {
                                                    nombre nombreenergia[19];
	FILE *Estructura;
	Estructura=fopen("C:/Users/Mar/Desktop/Antonio/Codeblocks/Trabajo/Estructura.csv","r");
	if (Estructura==NULL)
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
		int cantidadenergias=19;
		while(fscanf(Estructura,"%c",&x)!=EOF)
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
            fscanf(Estructura, "%[^,]s", nombreenergia[i].nombre);
            for (j=0; j<4; j++)
            {
                fscanf(Estructura, ",%lf", &datos[j].energia2[i]);
		    }
        }
        fclose(Estructura);

        			int panel;
					double suma[19] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
					double suma2[19] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
					double suma3[19] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
					double suma4[19] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
					printf("Opciones a realizar\n1-Clasificacion produccion de CO2\n2-Progreso respecto CO2\n");
					scanf("%i",&panel);
					switch (panel)
					{
					case 1:
							{

								 for (i = 0; i < cantidadenergias; i++)
							        {
							            j=0;
                                        suma[i] += datos[j].energia2[i];

							        }
							        rankingEstructuras(suma, cantidadenergias, nombreenergia);
						            printf("Ranking de emisiones de mayor a menor 2019:\n");

						            for (i = 0; i < cantidadenergias; i++)
						            {
						                printf("%s:%.3f", nombreenergia[i].nombre, suma[i]);
						            }

						            Estructura=fopen("C:/Users/Mar/Desktop/Antonio/Codeblocks/Trabajo/Estructura.csv","r");
                                    if (Estructura==NULL)
                                    {
                                        printf("Error al abrir el archivo");
                                        return -1;
                                    }
                                    else
                                    {
                                        contador=0;
                                        printf("El archivo se ha abierto correctamente\n");
                                        while(fscanf(Estructura,"%c",&x)!=EOF)
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
                                            fscanf(Estructura, "%[^,]s", nombreenergia[i].nombre);
                                                for (j=0; j<4; j++)
                                                {
                                                    fscanf(Estructura, ",%lf", &datos[j].energia2[i]);
                                                }
                                        }
                                        fclose(Estructura);


						        for (i = 0; i < cantidadenergias; i++)
							        {
							            j=1;
                                        suma2[i] += datos[j].energia2[i];

							        }


							        rankingEstructuras(suma2, cantidadenergias, nombreenergia);
						            printf("\n\nRanking de emisiones de mayor a menor 2020:\n");
						            for (i = 0; i < cantidadenergias; i++)
						            {
						                printf("%s:%.3f", nombreenergia[i].nombre, suma2[i]);
						            }
						            Estructura=fopen("C:/Users/Mar/Desktop/Antonio/Codeblocks/Trabajo/Estructura.csv","r");
                                    if (Estructura==NULL)
                                    {
                                        printf("Error al abrir el archivo");
                                        return -1;
                                    }
                                    else
                                    {
                                        contador=0;
                                        printf("El archivo se ha abierto correctamente\n");
                                        while(fscanf(Estructura,"%c",&x)!=EOF)
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
                                            fscanf(Estructura, "%[^,]s", nombreenergia[i].nombre);
                                                for (j=0; j<4; j++)
                                                {
                                                    fscanf(Estructura, ",%lf", &datos[j].energia2[i]);
                                                }
                                        }
                                        fclose(Estructura);


						        for (i = 0; i < cantidadenergias; i++)
							        {
							            j=2;
                                        suma3[i] += datos[j].energia2[i];

							        }


							        rankingEstructuras(suma3, cantidadenergias, nombreenergia);
						            printf("\n\nRanking de emisiones de mayor a menor 2021:\n");
						            for (i = 0; i < cantidadenergias; i++)
						            {
						                printf("%s:%.3f", nombreenergia[i].nombre, suma3[i]);
						            }


						            Estructura=fopen("C:/Users/Mar/Desktop/Antonio/Codeblocks/Trabajo/Estructura.csv","r");
                                    if (Estructura==NULL)
                                    {
                                        printf("Error al abrir el archivo");
                                        return -1;
                                    }
                                    else
                                    {
                                        contador=0;
                                        printf("El archivo se ha abierto correctamente\n");
                                        while(fscanf(Estructura,"%c",&x)!=EOF)
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
                                            fscanf(Estructura, "%[^,]s", nombreenergia[i].nombre);
                                                for (j=0; j<4; j++)
                                                {
                                                    fscanf(Estructura, ",%lf", &datos[j].energia2[i]);
                                                }
                                        }
                                        fclose(Estructura);


						        for (i = 0; i < cantidadenergias; i++)
							        {
							            j=3;
                                        suma4[i] += datos[j].energia2[i];

							        }


							        rankingEstructuras(suma4, cantidadenergias, nombreenergia);
						            printf("\n\nRanking de emisiones de mayor a menor 2022:\n");
						            for (i = 0; i < cantidadenergias; i++)
						            {
						                printf("%s:%.3f", nombreenergia[i].nombre, suma4[i]);
						            }
                                }
                                    }
					break;
						}

					case 2:
						{
							diferenciasEstructuras(datos,cantidadenergias,nombreenergia);
					break;
						}
                    default:
                    {
                        printf("Opción no valida, volviendo al menu principal");
                    }
					}
	fclose(Estructura);
	return 0;
	}
}
                                                }
	}
	}
	}
}
	void minimo(data datos[], int cantidadenergias, nombre nombreenergia[])
	{
	    int i, j, min;
	    for (i=0; i<cantidadenergias; i++) {
	        printf("\n%s\n", nombreenergia[i].nombre);
	        double min_emision = datos[0].emision[i];
	        min = 0;

	        for (j=1;j<24;j++) {
	            if (datos[j].emision[i] < min_emision) {
	                min_emision = datos[j].emision[i];
	                min = j;
	            }
	        }

	        printf("\t\tMes con menor emisión: %s\n", obtmesano(min + 1));
	        printf("\t\tEmision del mes: %.3f\n", min_emision);

	        double max_emision = datos[0].emision[i];
	        int max = 0;

	        for (j=1;j<24;j++) {
	            if (datos[j].emision[i] > max_emision) {
	                max_emision = datos[j].emision[i];
	                max = j;
	            }
	        }

	        printf("\t\tMes con mayor emisión: %s\n", obtmesano(max + 1));
	        printf("\t\tEmision del mes: %.3f\n", max_emision);

	        double diferencia = max_emision - min_emision;
	        printf("\t\tDiferencia: %.3f\n", diferencia);
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
	void promedioYporcentaje(data datos[], int cantidadenergias)
	{
		int i,j;
	    double promedioAntes = 0.0;
	    double promedioDespues = 0.0;
	    int contadorAntes = 0;
	    int contadorDespues = 0;

	    for (i = 0; i < 12; i++)
		{
	        for ( j = 0; j < cantidadenergias; j++)
			{
	            promedioAntes += datos[i].emision[j];
	        }
	        contadorAntes++;
	    }

	    for (i = 12; i < 24; i++)
		{
	        for ( j = 0; j < cantidadenergias; j++)
			{
	            promedioDespues += datos[i].emision[j];
	        }
	        contadorDespues++;
	    }

    promedioAntes /= (contadorAntes * cantidadenergias);
    promedioDespues /= (contadorDespues * cantidadenergias);

    printf("\tPromedio de emision antes del COVID-19: %.3f\n", promedioAntes);
    printf("\tPromedio de emision después del COVID-19: %.3f\n", promedioDespues);

    double porcentajeDisminucion = (promedioAntes - promedioDespues) / promedioAntes * 100;
    printf("\tPorcentaje de disminución de CO2: %.2f%%\n", porcentajeDisminucion);
}
void mesmax(data datos[],int cantidadenergias,nombre nombreenergia[])
{
    int i, j;
    double maxEmision;
    int maxMes;
    printf("\t\t\tEN 2021\n");
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

        printf("%s\n", nombreenergia[i].nombre);
        printf("\t\tMes con mayor emision: %s\n", obtmes(maxMes+1));
        printf("\t\tEmision: %.3f\n", maxEmision);
    }
    printf("\n\t\t\tEN 2022\n");
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
        printf("%s\n", nombreenergia[i].nombre);
        printf("\t\tMes con mayor emision: %s\n", obtmes(maxMes-11));
        printf("\t\tEmision: %.3f\n", maxEmision);
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
	printf("\tLa produccion de CO2 de:\n");
	printf("\n\n\t\tEN 2021\n");
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
	printf("\n\n\t\tEN 2022\n");
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

void rankingEstructuras(double suma[], int n, nombre nombreenergia[])
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

void diferenciasEstructuras(data datos[],int cantidadenergias,nombre nombreenergia[])
{
	int i,j;
	double diferencia;
	printf("La produccion de CO2 de:\n");
	printf("2020 con respecto a 2019\n\n");
	for(i=0;i<cantidadenergias;i++)
	{
		if (datos[0].energia2[i]>datos[1].energia2[i])
		{
			diferencia=datos[0].energia2[i]-datos[1].energia2[i];
			printf("%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
		}
		else
		{
			diferencia=datos[1].energia2[i]-datos[0].energia2[i];
			printf("%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
		}
	}
	printf("\n\n2021 con respecto a 2020\n\n");
	for(i=0;i<cantidadenergias;i++)
	{
		if (datos[1].energia2[i]>datos[2].energia2[i])
		{
			diferencia=datos[1].energia2[i]-datos[2].energia2[i];
			printf("%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
		}
		else
		{
			diferencia=datos[2].energia2[i]-datos[1].energia2[i];
			printf("%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
		}
	}
	printf("\n\n2022 con respecto a 2021\n\n");
	for(i=0;i<cantidadenergias;i++)
	{
		if (datos[2].energia2[i]>datos[3].energia2[i])
		{
			diferencia=datos[2].energia2[i]-datos[3].energia2[i];
			printf("%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
		}
		else
		{
			diferencia=datos[3].energia2[i]-datos[2].energia2[i];
			printf("%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
		}
	}

	printf("\n\n2022 con respecto a 2019\n\n");
	for(i=0;i<cantidadenergias;i++)
	{
		if (datos[0].energia2[i]>datos[3].energia2[i])
		{
			diferencia=datos[0].energia2[i]-datos[3].energia2[i];
			printf("%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
		}
		else
		{
			diferencia=datos[3].energia2[i]-datos[0].energia2[i];
			printf("%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
		}
	}
}
