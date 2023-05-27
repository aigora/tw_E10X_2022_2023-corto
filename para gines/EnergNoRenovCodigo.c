#include <stdio.h>

void comparar_emisiones_sin_con() {
    int anos[] = {2020, 2021, 2022, 2023};
    float sin_emisiones[] = {59.536, 63.46, 66.065, 67.986};
    float con_emisiones[] = {40.464, 36.54, 33.935, 32.014};
    int i;

    printf("Diferencia de emisiones CO2 eq. sin y con emisiones:\n");
    for (i = 0; i < sizeof(anos) / sizeof(anos[0]); i++) {
        float diferencia = sin_emisiones[i] - con_emisiones[i];
        printf("Año %d: %.3f\n", anos[i], diferencia);
    }

    printf("\nConclusiones:\n");
    for (i = 0; i < sizeof(anos) / sizeof(anos[0]); i++) {
        float diferencia = sin_emisiones[i] - con_emisiones[i];
        printf("Año %d: ", anos[i]);
        switch (i) {
            case 0:
                if (diferencia > 0)
                    printf("Las emisiones sin CO2 eq. son mayores que con emisiones.\n");
                else if (diferencia < 0)
                    printf("Las emisiones sin CO2 eq. son menores que con emisiones.\n");
                else
                    printf("No hay diferencia en las emisiones sin y con CO2 eq.\n");
                break;
            default:
                if (diferencia < 0)
                    printf("Las emisiones han bajado drásticamente después del COVID-19.\n");
                else
                    printf("Las emisiones no han bajado drásticamente después del COVID-19.\n");
                break;
        }
    }
}

int main() {
    comparar_emisiones_sin_con();
    return 0;
}

