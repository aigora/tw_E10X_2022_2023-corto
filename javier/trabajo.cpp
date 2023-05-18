#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
// Leo la frase con palabras y números reales entrecomillados separados por comas
    char frase[1000];
    fgets(frase, sizeof(frase), stdin);
// Procesar la frase y guardar los números en un vector
    double numeros[25];
    int num_numeros = 0;
//Separo con un puntero la frase en partes separadas por comas.
    char* parte = strtok(frase, ",");

    while (parte != NULL && num_numeros < 25) {
    	
// Verifico si la cada parte está entrecomillada
        if (parte[0] == '"' && parte[strlen(parte) - 1] == '"') {
        	
// Le quito las comillas al número
            char num_str[100];
            strncpy(num_str, parte + 1, strlen(parte) - 2);
            num_str[strlen(parte) - 2] = '\0';
            
// Convierto el número a double y lo guardo en un vector
            numeros[num_numeros] = atof(num_str);
            num_numeros++;
        }
        parte = strtok(NULL, ",");
    }

    // Calculo la suma de los números del vector.
    double suma = 0.0;
    for (int i = 0; i < num_numeros; i++) {
        suma += numeros[i];
    }

    // Mostrar la suma en pantalla
    printf("Suma de los números: %f\n", suma);

    return 0;
}

