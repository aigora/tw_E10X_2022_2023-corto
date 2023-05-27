// Escribe un programa que copie el contenido de un fichero en otro cambiando los espacios en blanco por un guión bajo _. //
// Emplea el fichero lorem_ipsum.txt como ejemplo. //

#include<stdio.h>

int main()
{
    int par=0;
    int primeravez=0;
    FILE *pescritura;
    FILE *plectura;
    plectura = fopen("C:/Users/Mar/Downloads/Evolucion_Potencia.csv", "r");
    if (plectura == NULL)
    {
        printf("Error al abrir el fichero de lectura.\n");
        }
    pescritura = fopen("C:/Users/Mar/Downloads/Evolucion_Potencia2.csv", "w");
    if (pescritura == NULL)
    {
        printf("Error al abrir el fichero de escritura.\n");
    }
    char letra;
    while (fscanf (plectura, "%c", &letra) != EOF)
    {
        if (letra == '"')
        {
            par++;
            primeravez++;
        }
        else if (letra==','&&par%2!=0)
        {
            fprintf(pescritura, "%c",'.');
        }
        else
        {
            fprintf (pescritura, "%c", letra);
        }
    }
    fclose (plectura);
    fclose (pescritura);
    return 0;
}
