#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./vectordinamico.h"
#include "./algoritmos.h"




////////////////////////////////
/////////     MAIN     /////////
////////////////////////////////

int main(int argc, char** argv){
    srand(time(NULL));
    vectorD vector = NULL;
    unsigned long int i, j, n;
    char opcion, opcion2;
    clock_t inicio, fin;
    double tempo_transcurrido;

    // Abrimos o arquivo en modo anexión
    FILE *archivo;
    archivo = fopen("salida.txt","a");
    if (archivo==NULL){
        perror("Error al abrir el archivo");
        exit(1);
    }

    printf("\n-------------------------------------------------------\n");
    printf("\nIntroduce el algoritmo de ordenación a utilizar\n");
    printf("\na) Quicksort");
    printf("\nb) Bubble sort");
    printf("\nc) Selection sort");
    printf("\n-------------------------------------------------------\n");
    printf("\nOpcion: ");
    scanf(" %c", &opcion); //cuidado con el espacio
    
        printf("\n-------------------------------------------------------\n");
    printf("\nComo queres escoller os vectores:\n");
    printf("\na) Un solo vector");
    printf("\nb) Varios vectores, escollendo as lonxitudes");
    printf("\nc) Varios vectores con salto");
    printf("\n-------------------------------------------------------\n");
    printf("\nOpcion: ");
    scanf(" %c", &opcion2); //cuidado con el espacio

    switch (opcion2) {
        case 'a': ///////////////////////////////////////////////////////////////////////////
            unsigned long int long_vectores[1];
            printf("\n\n-------------------------------------------------------\n");
            printf("\nIntroduce el tamaño del vector a ordenar\n");
            printf("\n-------------------------------------------------------\n");
            /// Escaneamos o vector de lonxitudes
            for(j = 0; j<n; j++){
                printf("Vector %lu: ",j+1);
                scanf(" %lu", &long_vectores[j]);
            }
            switch (opcion){
                case 'a':
                    system("clear");
                    printf("Quicksort\n");
                    fprintf(archivo,"\n\nQuicksort\n");
                break;
                case 'b':
                    system("clear");
                    printf("Bubble sort\n\n");
                    fprintf(archivo,"\n\nBubble sort\n");
                break;
                case 'c':
                    system("clear");
                    printf("Selection sort\n\n");
                    fprintf(archivo,"\n\nSelection sort\n");
                break;
            default:
                break;
            }

            /// Repetimos os algoritmos n veces
            for(j = 0; j<n; j++){

                // Creamos un vector aleatiro
                CreaVector(&vector, long_vectores[j]);
                for (i = 0; i<long_vectores[j]; i++){
                    AsignaVector(&vector, i, (TELEMENTO)(rand()));
                }

                switch (opcion){
                    case 'a':
                        if (EsNulo(vector)){
                            exit(1);
                        }
                        inicio = clock();
                        quicksort(&vector, 0, long_vectores[j]);
                        fin = clock();
                        tempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
                        printf("O tempo necesario para ordenar o vector %lu foi: %f segundos\n", j+1, tempo_transcurrido);
                        fprintf(archivo,"\n%lu %f",long_vectores[j],tempo_transcurrido);

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
                        fprintf(archivo,"\n%lu %f",long_vectores[j],tempo_transcurrido);
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
                        fprintf(archivo,"\n%lu %f",long_vectores[j],tempo_transcurrido);
                        break;

                    default:
                        printf("La opción es incorrecta");
                        break;
                }
                liberar(&vector);
            }

        break;    ///////////////////////////////////////////////////////////////////////////
        case 'b': ///////////////////////////////////////////////////////////////////////////
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

            switch (opcion){
                case 'a':
                    system("clear");
                    printf("Quicksort\n");
                    fprintf(archivo,"\n\nQuicksort\n");
                break;
                case 'b':
                    system("clear");
                    printf("Bubble sort\n\n");
                    fprintf(archivo,"\n\nBubble sort\n");
                break;
                case 'c':
                    system("clear");
                    printf("Selection sort\n\n");
                    fprintf(archivo,"\n\nSelection sort\n");
                break;
            default:
                break;
            }

            /// Repetimos os algoritmos n veces
            for(j = 0; j<n; j++){

                // Creamos un vector aleatiro
                CreaVector(&vector, long_vectores[j]);
                for (i = 0; i<long_vectores[j]; i++){
                    AsignaVector(&vector, i, (TELEMENTO)(rand()));
                }

                switch (opcion){
                    case 'a':
                        if (EsNulo(vector)){
                            exit(1);
                        }
                        inicio = clock();
                        quicksort(&vector, 0, long_vectores[j]);
                        fin = clock();
                        tempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
                        printf("O tempo necesario para ordenar o vector %lu foi: %f segundos\n", j+1, tempo_transcurrido);
                        fprintf(archivo,"\n%lu %f",long_vectores[j],tempo_transcurrido);

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
                        fprintf(archivo,"\n%lu %f",long_vectores[j],tempo_transcurrido);
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
                        fprintf(archivo,"\n%lu %f",long_vectores[j],tempo_transcurrido);
                        break;

                    default:
                        printf("La opción es incorrecta");
                        break;
                }
                liberar(&vector);
            }
        break; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 'c': ///////////////////////////////////////////////////////////////////////////
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

            switch (opcion){
                case 'a':
                    system("clear");
                    printf("Quicksort\n");
                    fprintf(archivo,"\n\nQuicksort\n");
                break;
                case 'b':
                    system("clear");
                    printf("Bubble sort\n\n");
                    fprintf(archivo,"\n\nBubble sort\n");
                break;
                case 'c':
                    system("clear");
                    printf("Selection sort\n\n");
                    fprintf(archivo,"\n\nSelection sort\n");
                break;
            default:
                break;
            }

            /// Repetimos os algoritmos n veces
            for(j = 0; j<n; j++){

                // Creamos un vector aleatiro
                CreaVector(&vector, long_vectores[j]);
                for (i = 0; i<long_vectores[j]; i++){
                    AsignaVector(&vector, i, (TELEMENTO)(rand()));
                }

                switch (opcion){
                    case 'a':
                        if (EsNulo(vector)){
                            exit(1);
                        }
                        inicio = clock();
                        quicksort(&vector, 0, long_vectores[j]);
                        fin = clock();
                        tempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
                        printf("O tempo necesario para ordenar o vector %lu foi: %f segundos\n", j+1, tempo_transcurrido);
                        fprintf(archivo,"\n%lu %f",long_vectores[j],tempo_transcurrido);

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
                        fprintf(archivo,"\n%lu %f",long_vectores[j],tempo_transcurrido);
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
                        fprintf(archivo,"\n%lu %f",long_vectores[j],tempo_transcurrido);
                        break;

                    default:
                        printf("La opción es incorrecta");
                        break;
                }
                liberar(&vector);
            }
        break; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            default:
                printf("La opción es incorrecta");
                break;
    }
    fclose(archivo);
    return(EXIT_SUCCESS);
}


