#include <stdio.h>
#include <stdlib.h>

int main()
{
    int accion;
    printf("Presione 1 si desea ver la comparacion entre la energia prevista y la necesitada.\n");
    printf("Presione 2 si desea ver la clasificacion de las energias.\n");
    printf("Presione 3 si desea ver la energia renovable producida cada a�o.\n");
    printf("Presione 4 si desea ver la energia no renovable producida cada a�o.\n");

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
        //C�digo acci�n 1.
        break;
    case 2:
        printf("Funciona el 2");
        //C�digo acci�n 2.
        break;
    case 3:
        printf("Funciona el 3");
        //C�digo acci�n 3.
        break;
    case 4:
        printf("Funciona el 4");
        //C�digo acci�n 4.
        break;
    }
    return 0;
}
