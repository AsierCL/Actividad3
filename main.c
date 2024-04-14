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
    unsigned long int longitud, i;
    float j;
    TELEMENTO valor;
    char opcion;
    if (argc>1){
        longitud = argc - 1;
        CreaVector(&vector, longitud);
        
        for (i = 0; i<longitud; i++){
            valor = atof(argv[i + 1]);
            AsignaVector(&vector, i, valor);
        }
    }

    do{
        printf("\n-------------------------------------------------------\n");
        printf("\na) Crear vector v                 e) Imprimir vector\n");
        printf("\nb) Liberar vector v               f) Media geométrica\n");
        printf("\nc) Recuperar                      g) Media\n ");
        printf("\nd) Longitud del vector            s) Salir\n\n\n");
        printf("\nh) Quicksort                      i) Bubblesort\n");
        printf("\nj) Selecction sort                k) Crear vector aleatorio\n");
        printf("\n-------------------------------------------------------\n");
        printf("\nOpcion: ");
        scanf(" %c", &opcion); //cuidado con el espacio
        
        ///system("clear");
        
        switch (opcion) {
            case 'a': 
                printf("Creand vector...\n");
                printf("Cual es la longitud del vector? ");
                scanf(" %lu", &longitud);
                CreaVector(&vector, longitud);
                
                for (i = 0; i<longitud; i++){
                    printf("vector (%lu) ", i);
                    scanf(" %d", &valor);
                    AsignaVector(&vector, i, valor);
                }
                break;

            case 'b':
                printf("Liberando vector...\n");
                liberar(&vector);
                break;

            case 'c':
                printf("Recuperando posición...\n");
                if (EsNulo(vector)){
                    printf("Debes crear un vector antes\n");
                    break;
                }
                printf("Que posición quires recuperar? ");
                scanf("%lu", &i);
                TELEMENTO k;
                k = recuperar(vector, i);
                if (i < longitudVector(vector)){
                    printf("%d",k);
                    break;
                }
                printf("Esa posición de memoria no está disponible");
                break;

            case 'd':
                printf("Imprimiendo la longitud del vector...\n");
                if (EsNulo(vector)){
                    printf("Debes crear un vector antes\n");
                    break;
                }
                i = longitudVector(vector);
                printf("%lu",i);
                break;

            case 'e':
                printf("Imprimiendo el vector...\n");
                if (EsNulo(vector)){
                    printf("Debes crear un vector antes\n");
                    break;
                }
                imprimir(vector);
                break;

            case 'f':
                printf("Imprimiendo la media geométrica...\n");
                if (EsNulo(vector)){
                    printf("Debes crear un vector antes\n");
                    break;
                }
                j = mediaGeometrica(vector);
                printf("%f",j);
                break;

            case 'g':
                printf("Imprimiendo la media...\n");
                if (EsNulo(vector)){
                    printf("Debes crear un vector antes\n");
                    break;
                }
                j = media(vector);
                printf("%f",j);
                break;

///////////////////////////////////////////
            case 'h':
                printf("Quick sort\n");
                if (EsNulo(vector)){
                    printf("Debes crear un vector antes\n");
                    break;
                }
                break;

            case 'i':
                printf("Bubble sort\n");
                if (EsNulo(vector)){
                    printf("Debes crear un vector antes\n");
                    break;
                }
                bubblesort(&vector, longitud);
                imprimir(vector);
                break;

            case 'j':
                printf("Selection sort\n");
                if (EsNulo(vector)){
                    printf("Debes crear un vector antes\n");
                    break;
                }
                j = media(vector);
                printf("%f",j);
                break;

            case 'k': 
                printf("Creand vector...\n");
                printf("Cual es la longitud del vector? ");
                scanf(" %lu", &longitud);
                CreaVector(&vector, longitud);
                
                srand(time(NULL));
                for (i = 0; i<longitud; i++){
                    AsignaVector(&vector, i, (TELEMENTO)(rand()));
                }
                break;

            case 's':
                printf("Saliendo del programa...\n");
                liberar(&vector);
                break;

            default:
                printf("La opción es incorrecta");
                break;
        }
    } while (opcion != 's');
    return(EXIT_SUCCESS);
}