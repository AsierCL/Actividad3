#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "./vectordinamico.h"
#include "./algoritmos.h"




////////////////////////////////
/////////     MAIN     /////////
////////////////////////////////

int main(int argc, char** argv){
    srand(time(NULL));
    vectorD vector = NULL;
    unsigned long int longitud, i, j, n;
    TELEMENTO valor;
    char opcion;
    clock_t inicio, fin;
    double tempo_transcurrido;


    printf("\n-------------------------------------------------------\n");
    printf("\nIntroduce el algoritmo de ordenación a utilizar\n");
    printf("\na) Quicksort");
    printf("\nb) Bubble sort");
    printf("\nc) Selection sort");
    printf("\n-------------------------------------------------------\n");
    printf("\nOpcion: ");
    scanf(" %c", &opcion); //cuidado con el espacio
    
    printf("\n\n-------------------------------------------------------\n");
    printf("\nIntroduce el numero de vectores que se crearán\n");
    printf("\n-------------------------------------------------------\n");
    printf("\nTamaño: ");
    scanf(" %lu", &n); //cuidado con el espacio

    /// Creamos o vector de lonxitudes
    unsigned long int long_vectores[n];
    
    printf("\n\n-------------------------------------------------------\n");
    printf("\nIntroduce el tamaño del vector a ordenar\n");
    printf("\n-------------------------------------------------------\n");
    /// Escaneamos o vector de lonxitudes
    for(j = 0; j<n; j++){
        printf("Vector %lu: ",j+1);
        scanf(" %lu", &long_vectores[j]);
    }


    /// Repetimos os algoritmos n veces
    for(j = 0; j<n; j++){

        // Creamos un vector aleatiro
        CreaVector(&vector, long_vectores[j]);
        srand(time(NULL));
        for (i = 0; i<long_vectores[j]; i++){
            AsignaVector(&vector, i, (TELEMENTO)(rand()));
        }

        switch (opcion) {
            case 'a':
                if (EsNulo(vector)){
                    exit(1);
                }
                inicio = clock();
                quicksort(&vector, 0, long_vectores[j]);
                fin = clock();
                tempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
                printf("O tempo necesario para ordenar o vector %lu foi: %f segundos\n", j+1, tempo_transcurrido);

                //imprimir(vector);
                break;

            case 'b':
                if (EsNulo(vector)){
                    exit(1);
                }

                inicio = clock();
                bubblesort(&vector, long_vectores[j]);
                fin = clock();
                tempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
                printf("O tempo necesario para ordenar o vector %lu foi: %f segundos\n", j+1, tempo_transcurrido);
                break;

            case 'c':
                if (EsNulo(vector)){
                    exit(1);
                }

                inicio = clock();
                selectionsort(&vector, long_vectores[j]);
                fin = clock();
                tempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
                printf("O tempo necesario para ordenar o vector %lu foi: %f segundos\n", j+1, tempo_transcurrido);
                break;

            case 's':
                printf("Saliendo del programa...\n");
                liberar(&vector);
                break;

            default:
                printf("La opción es incorrecta");
                break;
        }
        liberar(&vector);
    }

    return(EXIT_SUCCESS);
}