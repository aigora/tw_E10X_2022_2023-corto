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
	double energia3[17];
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
void calcularPorcentaje(data datos[], int cantidadenergias,double suma2[],nombre nombreenergia[],float total);
void calcularPorcentaje2(data datos[], int cantidadenergias,double suma2[],nombre nombreenergia[],float total);
void analizarVariacion(float precios[], int numAnos);
void calcularPromedio(float precios[], int numAnos);
void calcularPorcentaje3(data datos[], int cantidadenergias,double suma2[],nombre nombreenergia[],float total);
void calcularPorcentaje4(data datos[], int cantidadenergias,double suma2[],nombre nombreenergia[],float total);
int main()
{
	int eleccion;

	FILE *SALIDA;
	SALIDA=fopen("C:/Users/Mar/Documents/GitHub/tw_E10X_2022_2023-corto/SALIDA.txt","w");
	if (SALIDA==NULL)
    {

        printf("Error al abrir el archivo");
        return -1;
    }
	printf("Bienvenido al panel principal");
	while (eleccion!=5)
	{
	printf("\n\nQue desesa hacer\n");
	printf("1-Emisiones CO2\n");
	printf("2-Estructura de la potencia instalada con y sin CO2\n");
//	printf("3-Generacion de todos tipos de energias\n");
	printf("3-Generacion de energias renovables\n");
	printf("4-Energias producidas\n");
	printf("5-Salir");
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
                fprintf(SALIDA,"Emisiones de CO2 periodo transicion COVID-19\n");
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
                        int vista;
                        printf("Opciones\n1-Maximos y minimos alcanzados\n2-Comparacion Covid-19");
                        scanf("\t%i",&vista);
                        fclose(g);
                        switch (vista)
                        {
                            case 1:
                            {
                                fprintf(SALIDA,"Máximo y mínimo de cada mes:\n");
                                minimo(datos,cantidadenergias,nombreenergia);
                                int algo;
                                printf("\nPara ver conclusion pulse 1\n");
                                scanf("\t%i\n",&algo);
                                switch(algo)
                                case 1:
                                {
                                    float diferenciatotal=datos[0].emision[7]-datos[15].emision[7];
                                    float porcen=(datos[0].emision[7]/datos[15].emision[7])*100;
                                    fprintf(SALIDA,"Conclusion: La comparacion de emision a principios de año comparado\ncon la llegada del estado de alarma la emision\nha bajado un total de  %.3f un %.3f%%:",diferenciatotal,porcen);
                                    printf("\t\tLa comparacion de emision a principios de año comparado\ncon la llegada del estado de alarma la emision\nha bajado un total de  %.3fun %.3f%%:",diferenciatotal,porcen);
                                    break;
                                }
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
                        printf("Opciones a realizar\n1-Clasificacion produccion de CO2\n2-Maximo y minimo emision alcanzado por mes\n3-Progreso respecto CO2\n");
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
                                }
                                break;
                            }
                            case 2:
                            {
                                mesmax(datos, cantidadenergias, nombreenergia);
                                minimo(datos, cantidadenergias, nombreenergia);
                                break;
                            }
                            case 3:
                            {
                                diferencias(datos,cantidadenergias,nombreenergia);
                                break;
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
    }
    }
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
		fprintf(SALIDA,"Estructura de la potencia instalada con y sin CO2\n");
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
                        fprintf(SALIDA,"Clasificación de la produccion de CO2\n");
                        for (i = 0; i < cantidadenergias; i++)
                        {
                            j=0;
                            suma[i] += datos[j].energia2[i];
                        }
                        rankingEstructuras(suma, cantidadenergias, nombreenergia);
                        printf("Ranking de emisiones de mayor a menor 2019:\n");
                        fprintf(SALIDA,"Ranking de emisiones de mayor a menor 2019:\n");
                        for (i = 0; i < cantidadenergias; i++)
                        {
                            fprintf(SALIDA,"%s:%.3f", nombreenergia[i].nombre, suma[i]);
                            printf("%s:%.3f", nombreenergia[i].nombre, suma[i]);
                        }
                        Estructura=fopen("C:/Users/Mar/Desktop/Antonio/Codeblocks/Trabajo/Estructura.csv","r");
                        if (Estructura==NULL)
                            {
                                printf("Error al abrir el archivo");
                                return -1;
                            }
                        contador=0;
                        fprintf(SALIDA,"El archivo se ha abierto correctamente\n");
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
                        fprintf(SALIDA,"\n\nRanking de emisiones de mayor a menor 2020:\n");
                        for (i = 0; i < cantidadenergias; i++)
                        {
                            fprintf(SALIDA,"%s:%.3f", nombreenergia[i].nombre, suma2[i]);
                            printf("%s:%.3f", nombreenergia[i].nombre, suma2[i]);
                        }
                        Estructura=fopen("C:/Users/Mar/Desktop/Antonio/Codeblocks/Trabajo/Estructura.csv","r");
                        if (Estructura==NULL)
                            {
                                printf("Error al abrir el archivo");
                                return -1;
                            }
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
                        fprintf(SALIDA,"\n\nRanking de emisiones de mayor a menor 2021:\n");
                        printf("\n\nRanking de emisiones de mayor a menor 2021:\n");
                        for (i = 0; i < cantidadenergias; i++)
                        {
                            fprintf(SALIDA,"%s:%.3f", nombreenergia[i].nombre, suma3[i]);
                            printf("%s:%.3f", nombreenergia[i].nombre, suma3[i]);
                        }
                        Estructura=fopen("C:/Users/Mar/Desktop/Antonio/Codeblocks/Trabajo/Estructura.csv","r");
                        if (Estructura==NULL)
                        {
                            printf("Error al abrir el archivo");
                            return -1;
                        }
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
                        fprintf(SALIDA,"\n\nRanking de emisiones de mayor a menor 2022:\n");
                        printf("\n\nRanking de emisiones de mayor a menor 2022:\n");
                        for (i = 0; i < cantidadenergias; i++)
                        {
                            fprintf(SALIDA,"%s:%.3f", nombreenergia[i].nombre, suma4[i]);
                            printf("%s:%.3f", nombreenergia[i].nombre, suma4[i]);
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

	}
}

case 3:
{
                            //int cual;
                            //printf("\t3 .1-Generacion 2019-2020");
                            //printf("\t3 .1-Generacion 2019-2020");//Qué se supone que hace esto?
                            printf("Ha elegido ver la energia renovable producida cada año.\n");
                            fprintf(SALIDA,"Ha elegido ver la energia renovable producida cada año.\n");

    int i,j;
    nombre nombreenergia[17];
    data datos[24];
    int cantidadEnergias = 17;
	FILE *pf;
    dia fecha= {{1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12},
    {2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2022,2022,2022,2022,
    2022,2022,2022,2022,2022,2022,2022,2022}};
	pf=fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");

    if (pf == NULL)
    {
        printf("Error al abrir el fichero.\n");
        return -1;
    }

    else
    {
        printf("Fichero abierto correctamente.\n");

        data datos[24];
        int cantidadEnergias=17;
        int i=0;
        int j=0;
        char x;
        int contador=0;

        while(fscanf(pf, "%c" , &x) != EOF)
        {
            if(x == '\n')
            {
                contador++;
            }
            if(contador==5)
            {
                break;
            }
        }

        for (i=0; i<cantidadEnergias; i++)
        {
            fscanf(pf, "%[^,]s", nombreenergia[i].nombre);

            //GUARGAMOS LOS DATOS DE CADA ENERGIA 24 EN TOTAL(12 POR CADA AñO).
            for (j=0; j<24; j++)
            {
                fscanf(pf, ",%lf", &datos[j].energia3[i]);

		    }

        }
	}


	fclose(pf);

				int panel;
				int cantidadenergia=17;
				double suma[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				double suma2[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				printf("Opciones a realizar\n1-Energia renovable generada en 2021.\t2-Energia renovable generada en 2022.\t3-Energia renovable generada en un mes a elegir.\n");
						scanf("%i",&panel);
						switch (panel)
									{
										case 1:
												 for (i = 0; i < cantidadEnergias; i++)
													        {
													            for (j = 0; j < 12; j++)
													            {
													                suma[i] += datos[j].energia3[i];
													            }
													        }
															double sum;
													        sum = suma[0]+suma[8]+suma[9]+suma[10]+suma[11]+suma[12]+suma[15];
												            printf("Energia renovable generada en el 2021: %.2f GWh.\n", sum);
												            fprintf(SALIDA,"Energia renovable generada en el 2021: %.2f GWh.\n", sum);
												        break;

                                        case 2:

												for (i = 0; i < cantidadEnergias; i++)
													        {
													            for (j =12; j < 24; j++)
													            {
													                suma2[i] += datos[j].energia3[i];
													            }
													        }
															double sum2;
													        sum2=suma2[0]+suma2[8]+suma2[9]+suma2[10]+suma2[11]+suma2[12]+suma2[15];
												            printf("Energia renovable generada en el 2022: %.2f GWh.\n", sum2);
												            fprintf(SALIDA,"Energia renovable generada en el 2022: %.2f GWh.\n", sum2);
                                                              break;
                                        case 3:

												printf("Que mes desea consultar?\n2021:\t           2022:\n1-Enero\t           13-Enero\n2-Febrero\t   14-Febrero\n3-Marzo\t           15-Marzo\n4-Abril\t           16-Abril\n5-Mayo\t           17-Mayo\n6-Junio\t           18-Junio\n7-Julio\t           19-Julio\n8-Agosto\t   20-Agosto\n9-Septiembre\t   21-Septiembre\n10-Octubre\t   22-Octubre\n11-Noviembre\t   23-Noviembre\n12-Diciembre\t   24-Diciembre\n");
												int m;
												scanf("%d", &m);
												for (i = 0; i < cantidadEnergias; i++)
													        {
													                suma[i] += datos[m-1].energia3[i];

													        }
															double sum3;
													        sum3 = suma[0]+suma[8]+suma[9]+suma[10]+suma[11]+suma[12]+suma[15];
												            printf("Energia renovable generada en el mes elegido: %.2f GWh.\n", sum3);
												            fprintf(SALIDA,"Energia renovable generada en el mes elegido: %.2f GWh.\n", sum3);
												        break;
                        }
	}
case 4:
{
    int ree;
    printf("1-Produccion de energias 2019/2020\n");
    printf("2-Produccion de energias 2021/2022\n");
    printf("3-Variacion del precio del mercado\n");
    scanf("%i",ree);
    switch(ree)
    {
        case 1:
        {
            nombre nombreenergia[18];
            FILE *o;

            dia fecha={{1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12},
            {2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022}};
            o=fopen("C:/Users/Mar/Downloads/Estructura_Generacion_Tecnologias_2019-2020.csv","r");
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
            fclose(o);
            int panel;
            int cantidadenergia=17;
            double suma[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            double suma2[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            printf("Opciones a realizar\n1-Clasificacion produccion de Energia\n2-Energia representado en porcentaje\n");
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
                        printf("%s:%.3f GWh", nombreenergia[i].nombre, suma[i]);
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
                            for (j=0; j<24; j++)
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
                        fclose(o);
                    }
                break;
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
                        }
                        fclose(o);
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
                                    suma2[i] += datos[j].energia3[i];
                                }
                            }
                        }
                    }
                }
                calcularPorcentaje(datos,cantidadenergias,suma2,nombreenergia,260828.837);
                calcularPorcentaje2(datos,cantidadenergias,suma2,nombreenergia,251398.750);
                fclose(o);
                break;
            }
        }
    }
        case 2:
        {
            nombre nombreenergia[18];
            FILE *l;

            dia fecha={{1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12},
            {2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022,2022}};
            l=fopen("C:/Users/Mar/Downloads/Estructura_Generacion_Tecnologias_2021-2022.csv","r");
            if (l==NULL)
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
            while(fscanf(l,"%c",&x)!=EOF)
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
                fscanf(l, "%[^,]s", nombreenergia[i].nombre);
                for (j=0; j<24; j++)
                {
                    fscanf(l, ",%lf", &datos[j].energia3[i]);
                }
            }
            fclose(l);
            int panel;
            int cantidadenergia=17;
            double suma[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            double suma2[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            printf("Opciones a realizar\n1-Clasificacion produccion de Energia\n2-Energia representado en porcentaje\n");
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
                    printf("Ranking de emisiones de mayor a menor 2021:\n");
                    for (i = 0; i < cantidadenergias; i++)
                    {
                        printf("%s:%.3f GWh", nombreenergia[i].nombre, suma[i]);
                    }
                    l=fopen("C:/Users/jiaha/Downloads/Estructura_Generacion_Tecnologias_2021-2022.csv","r");
                    if (l==NULL)
                    {
                        printf("Error al abrir el archivo");
                        return -1;
                    }
                    else
                    {
                        contador=0;
                        printf("\nEl archivo se ha abierto correctamente\n");
                        while(fscanf(l,"%c",&x)!=EOF)
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
                            fscanf(l, "%[^,]s", nombreenergia[i].nombre);
                            for (j=0; j<24; j++)
                            {
                                fscanf(l, ",%lf", &datos[j].energia3[i]);
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
                        printf("\n\nRanking de emisiones de mayor a menor 2022:\n");
                        for (i = 0; i < cantidadenergias; i++)
                        {
                            printf("%s:%.3fGWh", nombreenergia[i].nombre, suma2[i]);
                        }
                        fclose(l);
                    }
                break;
                }
                case 2:
                {
                    l=fopen("C:/Users/jiaha/Downloads/Estructura_Generacion_Tecnologias_2021-2022.csv","r");
                    if (l==NULL)
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
                        while(fscanf(l,"%c",&x)!=EOF)
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
                            fscanf(l, "%[^,]s", nombreenergia[i].nombre);
                            for (j=0; j<24; j++)
                            {
                                fscanf(l, ",%lf", &datos[j].energia3[i]);
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
                        }
                        fclose(l);
                        l=fopen("C:/Users/jiaha/Downloads/Estructura_Generacion_Tecnologias_2021-2022.csv","r");
                        if (l==NULL)
                        {
                            printf("Error al abrir el archivo");
                            return -1;
                        }
                        else
                        {
                            contador=0;
                            printf("\nEl archivo se ha abierto correctamente\n");
                            while(fscanf(l,"%c",&x)!=EOF)
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
                                fscanf(l, "%[^,]s", nombreenergia[i].nombre);
                                for (j=0; j<24; j++) // 24 datos en cada energia
                                {
                                    fscanf(l, ",%lf", &datos[j].energia3[i]);
                                }
                            }
                            for (i = 0; i < cantidadenergias; i++)//apartir de aqui el 2022 empieza a fallar
                            {
                                for (j =12; j < 24; j++) //2 errores, el primero sé solucionarlo pero el segundo es una fumada: mañana en llamada te cuento.
                                {
                                    suma2[i] += datos[j].energia3[i];
                                }
                            }
                        }
                    }
                }
                calcularPorcentaje3(datos,cantidadenergias,suma2,nombreenergia,260011.185);
                calcularPorcentaje4(datos,cantidadenergias,suma2,nombreenergia,276412.681);
                fclose(l);
                break;
            }
        }
    }

        }
    }
}
	}
		fclose(SALIDA);

	}


	void minimo(data datos[], int cantidadenergias, nombre nombreenergia[])
	{
	    FILE *SALIDA;
	    SALIDA=fopen("C:/Users/Mar/Documents/GitHub/tw_E10X_2022_2023-corto/SALIDA.txt","a");
	    if (SALIDA==NULL)
        {
            printf("Error al abrir el archivo");
            return -1;
        }
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

	        fprintf(SALIDA,"\t\tMes con menor emisión: %s\n", obtmesano(min + 1));
	        fprintf(SALIDA,"\t\tEmision del mes: %.3f\n", min_emision);

	        double max_emision = datos[0].emision[i];
	        int max = 0;

	        for (j=1;j<24;j++) {
	            if (datos[j].emision[i] > max_emision) {
	                max_emision = datos[j].emision[i];
	                max = j;
	            }
	        }

	        fprintf(SALIDA,"\t\tMes con mayor emisión: %s\n", obtmesano(max + 1));
	        fprintf(SALIDA,"\t\tEmision del mes: %.3f\n", max_emision);

	        printf("\t\tMes con mayor emisión: %s\n", obtmesano(max + 1));
	        printf("\t\tEmision del mes: %.3f\n", max_emision);

	        double diferencia = max_emision - min_emision;
	        printf("\t\tDiferencia: %.3f\n", diferencia);

	        fprintf(SALIDA,"\t\tDiferencia: %.3f\n", diferencia);

	    }
	    fclose(SALIDA);
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
	    FILE *SALIDA;
        SALIDA=fopen("C:/Users/Mar/Documents/GitHub/tw_E10X_2022_2023-corto/SALIDA.txt","a");
        if (SALIDA==NULL)
        {
            printf("Error al abrir el archivo");
            return -1;
        }
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
    fprintf(SALIDA,"\tPromedio de emision antes del COVID-19: %.3f\n", promedioAntes);
    fprintf(SALIDA,"\tPromedio de emision después del COVID-19: %.3f\n", promedioDespues);




    printf("\tPromedio de emision antes del COVID-19: %.3f\n", promedioAntes);
    printf("\tPromedio de emision después del COVID-19: %.3f\n", promedioDespues);

    double porcentajeDisminucion = (promedioAntes - promedioDespues) / promedioAntes * 100;

    fprintf(SALIDA,"\tPorcentaje de disminución de CO2: %.2f%%\n", porcentajeDisminucion);

    printf("\tPorcentaje de disminución de CO2: %.2f%%\n", porcentajeDisminucion);
    fclose(SALIDA);
}
void mesmax(data datos[],int cantidadenergias,nombre nombreenergia[])
{
    FILE *SALIDA;
    SALIDA=fopen("C:/Users/Mar/Documents/GitHub/tw_E10X_2022_2023-corto/SALIDA.txt","a");

    int i, j;
    double maxEmision;
    int maxMes;
    printf("\t\t\tEN 2021\n");
    fprintf(SALIDA,"\t\t\tEN 2021\n");
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
        fprintf(SALIDA,"%s\n", nombreenergia[i].nombre);
        printf("%s\n", nombreenergia[i].nombre);
        fprintf(SALIDA,"\t\tMes con mayor emision: %s\n", obtmes(maxMes+1));
        printf("\t\tMes con mayor emision: %s\n", obtmes(maxMes+1));
        fprintf(SALIDA,"\t\tEmision: %.3f\n", maxEmision);
        printf("\t\tEmision: %.3f\n", maxEmision);
    }
    printf("\n\t\t\tEN 2022\n");
    fprintf(SALIDA,"\n\t\t\tEN 2022\n");
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
        fprintf(SALIDA,"%s\n", nombreenergia[i].nombre);
        printf("\t\tMes con mayor emision: %s\n", obtmes(maxMes-11));
        fprintf(SALIDA,"\t\tMes con mayor emision: %s\n", obtmes(maxMes-11));
        printf("\t\tEmision: %.3f\n", maxEmision);
        fprintf(SALIDA,"\t\tEmision: %.3f\n", maxEmision);
    }
    fclose(SALIDA);
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
    FILE *SALIDA;
    SALIDA=fopen("C:/Users/Mar/Documents/GitHub/tw_E10X_2022_2023-corto/SALIDA.txt","a");
	int i,j;
	double diferencia;
	fprintf(SALIDA,"\tLa produccion de CO2 de:\n");
	fprintf(SALIDA,"\n\n\t\tEN 2021\n");
	printf("\tLa produccion de CO2 de:\n");
	printf("\n\n\t\tEN 2021\n");
	for(i=0;i<cantidadenergias;i++)
	{
		if (datos[0].energia2[i]>datos[11].energia2[i])
		{
			diferencia=datos[0].energia2[i]-datos[11].energia2[i];
			fprintf(SALIDA,"%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
			printf("%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
		}
		else
		{
			diferencia=datos[11].energia2[i]-datos[0].energia2[i];
			printf("%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
			fprintf(SALIDA,"%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
		}
	}
	printf("\n\n\t\tEN 2022\n");
	fprintf(SALIDA,"\n\n\t\tEN 2022\n");
    for(i=0;i<cantidadenergias;i++)
	{
		if (datos[12].energia2[i]>datos[23].energia2[i])
		{
			diferencia=datos[12].energia2[i]-datos[23].energia2[i];
			fprintf(SALIDA,"%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
			printf("%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
		}
		else
		{
			diferencia=datos[23].energia2[i]-datos[12].energia2[i];
			fprintf(SALIDA,"%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
			printf("%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
		}
	}
	fclose(SALIDA);
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
    FILE *SALIDA;
    char texto;

    SALIDA=fopen("C:/Users/Mar/Documents/GitHub/tw_E10X_2022_2023-corto/SALIDA.txt","a");
    if (SALIDA==NULL)
    {
        printf("Error al abrir el archivo");
        return -1;
    }

	int i,j;
	double diferencia;
	printf("La produccion de CO2 de:\n");
	printf("2020 con respecto a 2019\n\n");

	fprintf(SALIDA,"La produccion de CO2 de:\n");
	fprintf(SALIDA,"2020 con respecto a 2019\n\n");

	for(i=0;i<cantidadenergias;i++)
	{
		if (datos[0].energia2[i]>datos[1].energia2[i])
		{
			diferencia=datos[0].energia2[i]-datos[1].energia2[i];
			fprintf(SALIDA,"%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
			printf("%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
		}
		else
		{
			diferencia=datos[1].energia2[i]-datos[0].energia2[i];
			fprintf(SALIDA,"%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
			printf("%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
		}
	}
	printf("\n\n2021 con respecto a 2020\n\n");
	fprintf(SALIDA,"\n\n2021 con respecto a 2020\n\n");
	for(i=0;i<cantidadenergias;i++)
	{
		if (datos[1].energia2[i]>datos[2].energia2[i])
		{
			diferencia=datos[1].energia2[i]-datos[2].energia2[i];
			fprintf(SALIDA,"%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
			printf("%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
		}
		else
		{
			diferencia=datos[2].energia2[i]-datos[1].energia2[i];
			fprintf(SALIDA,"%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
			printf("%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
		}
	}
	fprintf(SALIDA,"\n\n2022 con respecto a 2021\n\n");
	printf("\n\n2022 con respecto a 2021\n\n");
	for(i=0;i<cantidadenergias;i++)
	{
		if (datos[2].energia2[i]>datos[3].energia2[i])
		{
			diferencia=datos[2].energia2[i]-datos[3].energia2[i];
			fprintf(SALIDA,"%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
			printf("%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
		}
		else
		{
			diferencia=datos[3].energia2[i]-datos[2].energia2[i];
			fprintf(SALIDA,"%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
			printf("%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
		}
	}
	fprintf(SALIDA, "\n\n2022 con respecto a 2019\n\n");
	printf("\n\n2022 con respecto a 2019\n\n");
	for(i=0;i<cantidadenergias;i++)
	{
		if (datos[0].energia2[i]>datos[3].energia2[i])
		{
			diferencia=datos[0].energia2[i]-datos[3].energia2[i];
			fprintf(SALIDA,"%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
			printf("%s ha disminuido %.3f",nombreenergia[i].nombre,diferencia);
		}
		else
		{
			diferencia=datos[3].energia2[i]-datos[0].energia2[i];
			fprintf(SALIDA,"%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
			printf("%s ha aumentado %.3f",nombreenergia[i].nombre,diferencia);
		}
	}
	fclose(SALIDA);
}

/// AQUI ENERGIAS
void calcularPorcentaje(data datos[], int cantidadenergias,double suma2[],nombre nombreenergia[],float total)
{
    double porcentajes[17];
    int i,j;
    for ( i = 0; i < 16; i++)
    {
        double porcentaje = (datos[0].energia3[i] + datos[1].energia3[i] + datos[2].energia3[i] + datos[3].energia3[i] + datos[4].energia3[i] +
                            datos[5].energia3[i] + datos[6].energia3[i] + datos[7].energia3[i] + datos[8].energia3[i] + datos[9].energia3[i] +
                            datos[10].energia3[i] + datos[11].energia3[i]) / total * 100.0;

        porcentajes[i] = porcentaje;
    }

    printf("\n\tPorcentaje de cada energia en el total de 2019:\n");
    for ( i = 0; i < 15; i++)
    {
        printf("%s: %.2f%%\n", nombreenergia[i].nombre, porcentajes[i]);
    }
}
void calcularPorcentaje2(data datos[], int cantidadenergias,double suma2[],nombre nombreenergia[],float total)
{
    double porcentajes[17];

    int i,j;

    for ( i = 0; i < 16 ;i++)
    {
        double porcentaje = (datos[12].energia3[i] + datos[13].energia3[i] + datos[14].energia3[i] + datos[15].energia3[i] + datos[16].energia3[i] +
                            datos[17].energia3[i] + datos[18].energia3[i] + datos[19].energia3[i] + datos[20].energia3[i] + datos[21].energia3[i] +
                            datos[22].energia3[i] + datos[23].energia3[i]) / total * 100.0;

        porcentajes[i] = porcentaje;
    }

    printf("\n\tPorcentaje de cada energia en el total de 2020:\n");
    for (i = 0; i < 15; i++)
    {
        printf("%s: %.2f%%\n", nombreenergia[i].nombre, porcentajes[i]);
    }
}
void calcularPorcentaje3(data datos[], int cantidadenergias,double suma2[],nombre nombreenergia[],float total)
{
    double porcentajes[17];

    int i,j;

    for ( i = 0; i < 16 ;i++)
    {
        double porcentaje = (datos[12].energia3[i] + datos[13].energia3[i] + datos[14].energia3[i] + datos[15].energia3[i] + datos[16].energia3[i] +
                            datos[17].energia3[i] + datos[18].energia3[i] + datos[19].energia3[i] + datos[20].energia3[i] + datos[21].energia3[i] +
                            datos[22].energia3[i] + datos[23].energia3[i]) / total * 100.0;

        porcentajes[i] = porcentaje;
    }

    printf("\n\tPorcentaje de cada energia en el total de 2021:\n");
    for (i = 0; i < 15; i++)
    {
        printf("%s: %.2f%%\n", nombreenergia[i].nombre, porcentajes[i]);
    }
}
void calcularPorcentaje4(data datos[], int cantidadenergias,double suma2[],nombre nombreenergia[],float total)
{
    double porcentajes[17];

    int i,j;

    for ( i = 0; i < 16 ;i++)
    {
        double porcentaje = (datos[12].energia3[i] + datos[13].energia3[i] + datos[14].energia3[i] + datos[15].energia3[i] + datos[16].energia3[i] +
                            datos[17].energia3[i] + datos[18].energia3[i] + datos[19].energia3[i] + datos[20].energia3[i] + datos[21].energia3[i] +
                            datos[22].energia3[i] + datos[23].energia3[i]) / total * 100.0;

        porcentajes[i] = porcentaje;
    }

    printf("\n\tPorcentaje de cada energia en el total de 2022:\n");
    for (i = 0; i < 15; i++)
    {
        printf("%s: %.2f%%\n", nombreenergia[i].nombre, porcentajes[i]);
    }
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
