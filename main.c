#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "vectordinamico.h"

void imprimir(vectorD v1){
    TELEMENTO j;
    short longitud = longitudVector(v1);
    short i;
    for (i = 0; i<longitud; i++){
        j = recuperar(v1,i);
        printf("%f ",j);
    }
}

float mediaGeometrica(vectorD v1){
    TELEMENTO j,resultado;
    resultado = 1;
    short longitud = longitudVector(v1);
    short i;
    for (i = 0; i<longitud; i++){
        j = recuperar(v1,i);
        resultado *= j;
    }
    j = (pow(resultado, 1.0/longitudVector(v1)));
    return j;
}

float media(vectorD v1){
    TELEMENTO j,resultado;
    resultado = 0;
    short longitud = longitudVector(v1);
    short i;
    for (i = 0; i<longitud; i++){
        j = recuperar(v1,i);
        resultado += j;
    }
    j = (resultado/longitudVector(v1));
    return j;
}



////////////////////////////////
/////////     MAIN     /////////
////////////////////////////////

int main(int argc, char** argv){
    vectorD vector = NULL;
    short longitud, i;
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
        printf("\nd) Longitud del vector            s) Salir\n");
        printf("\n-------------------------------------------------------\n");
        printf("\nOpcion: ");
        scanf(" %c", &opcion); //cuidado con el espacio
        
        ///system("clear");
        
        switch (opcion) {
            case 'a': 
                printf("Creand vector...\n");
                printf("Cual es la longitud del vector? ");
                scanf(" %hd", &longitud);
                CreaVector(&vector, longitud);
                
                for (i = 0; i<longitud; i++){
                    printf("vector (%hd) ", i);
                    scanf(" %f", &valor);
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
                scanf("%hd", &i);
                TELEMENTO j;
                j = recuperar(vector, i);
                if (i < longitudVector(vector)){
                    printf("%f",j);
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
                printf("%hd",i);
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