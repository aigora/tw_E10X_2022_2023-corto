#include <stdio.h>
#include <stdlib.h>

//SIRVE PARA GUARDAR LOS DATOS FECHA CON MES Y AÑO.


typedef struct
{
    int mes[24];
    int year[24];
} dia;
//SIRVE PARA GUARDAR LOS NOMBRES DE LAS ENERGÍAS
typedef struct nombre
{
    char nombre[50];
} nombreEnergia;
//SIRVE PARA GUARDAR LOS DATOS NUMÉRICOS DE LAS ENERGÍAS
typedef struct
{
    double energia[17];
} data;

//ESTRUCTURA QUE ALMACENA LOS DATOS GUARDADOS
typedef struct resultadosguardados
{
    nombreEnergia energia;
    dia fecha;
    double resultados;
} resultadosguardados;



void leerDatos(nombreEnergia nombreEnergia[], data datos[], int cantidadEnergias);



//ESTRUCTURA PRINCIPAL DEL PROGRAMA
int main()
{
    int i,j;
    nombreEnergia nombre[17];
    data datos[24];
    int cantidadEnergias = 17;

    leerDatos(nombre, datos, cantidadEnergias);


//    Para acceder a los datos se utiliza lo siguiente.
/*
    for (i = 0; i < cantidadEnergias; i++)
    {
        printf("Nombre de energía: %s\n", nombre[i].nombre);
        printf("Datos:\n");
        for (j = 0; j < 24; j++)
        {
            printf("%.2lf ", datos[j].energia[i]);
        }
        printf("\n\n");
    }
*/



	int accion;
    printf("Presione 1 si desea ver la comparacion entre la energia prevista y la necesitada.\n");
    printf("Presione 2 si desea ver la clasificacion de las energias.\n");
    printf("Presione 3 si desea ver la energia renovable producida cada año.\n");
    printf("Presione 4 si desea ver la energia no renovable producida cada año.\n");

    scanf("%i",&accion);

    while(accion != 1 && accion != 2 && accion != 3 && accion != 4)
    {
        printf("Por favor, seleccione una opcion valida\n");
        scanf("%i",&accion);
    }


    switch(accion)
    {
    case 1:
        printf("Funciona el 1");
        //Código acción 1.
        break;
    case 2:
        printf("Funciona el 2");
        //Código acción 2.
        break;
    case 3:
        printf("Funciona el 3");
        //Código acción 3.
        break;
    case 4:
        printf("Funciona el 4");
        //Código acción 4.
        break;
    }
    return 0;
}



void leerDatos(nombreEnergia nombreEnergia[], data datos[], int cantidadEnergias)
{
    FILE *pf;
    dia fecha = {{1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12},
                 {2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2022,2022,2022,2022,
                  2022,2022,2022,2022,2022,2022,2022,2022}};

    //ABRIMOS EL FICHERO
    pf = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");

    if (pf == NULL)
    {
        printf("Error al abrir el fichero.\n");
        return;
    }
    else
    {
        printf("Fichero abierto correctamente.\n");
        int i = 0;
        int j = 0;
        char x;
        int contadorlineas = 0;

        //CONTAMOS LAS 5 PRIMERAS LÍNEAS PARA NO USARLAS PORQUE NO TIENEN INFORMACIÓN RELEVANTE.
        while (fscanf(pf, "%c", &x) != EOF)
        {
            if (x == '\n')
            {
                contadorlineas++;
            }
            if (contadorlineas == 5)
            {
                break;
            }
        }
        //GUARDAMOS UNO POR UNO LOS NOMBRES DE LAS ENERGÍAS.
        for (i = 0; i < cantidadEnergias; i++)
        {
            fscanf(pf, "%[^,]s", nombreEnergia[i].nombre);
            //printf("%s", nombreEnergia[i].nombre);
            //GUARDAMOS LOS DATOS DE CADA ENERGÍA 24 EN TOTAL(12 POR CADA AÑO).
            for (j = 0; j < 24; j++) // 24 datos en cada energía
            {
                fscanf(pf, ",%lf", &datos[j].energia[i]);
                //printf( ",%lf", datos[j].energia[i]);
            }
        }
    }
    fclose(pf);
}
