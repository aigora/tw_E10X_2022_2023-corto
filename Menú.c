#include <stdio.h>
#include <stdlib.h>

int main()
{
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
