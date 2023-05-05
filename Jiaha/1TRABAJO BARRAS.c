#include <stdio.h>
#include <math.h>
#include <stdio.h>

int main() {
    int i;
    int unidades = 0;
    float x;

    printf("Ingrese un número: ");
    scanf("%f", &x);

    int entero = round(x);
    if (entero > 0 && entero % 100 == 0)//Nos aseguramos de que sea positivo y que sea divisible al salto que queramos
	{
        unidades = entero / 100;
    }
    for (i = 0; i < unidades; i++) {
        printf("X");
    }
    printf("\n");

    return 0;
}

