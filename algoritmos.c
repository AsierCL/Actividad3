#include <stdio.h>
#include <stdlib.h>
#include "./vectordinamico.h"

void swap (vectorD *v, unsigned long m, unsigned long n){
    TELEMENTO aux, aux2;
    aux = Componentei(*v,m);
    aux2 = Componentei(*v,n);
    AsignaVector(v,m,aux2);
    AsignaVector(v,n,aux);
}

void bubblesort(vectorD *v, unsigned long int TAM){
    unsigned long int e, i;
    TELEMENTO aux;
    for (e = 0; e < (TAM - 1); e++){
        for (i = 0; i < (TAM - e - 1); i++){
            if (Componentei(*v, i) > Componentei(*v, i + 1)){
                aux = Componentei(*v, i);
                AsignaVector(v, i, Componentei(*v, i + 1));
                AsignaVector(v, i + 1, aux);
            }
        }
    }
}


void quicksort(vectorD *v, unsigned long beg, unsigned long end){
    if (end > beg + 1){
        TELEMENTO piv = Componentei(*v, beg);
        unsigned long l = beg + 1, r = end;
        while (l < r){
            if (Componentei(*v, l) <= piv){
                l++;
            }else{
                r--;
                swap(v, l, r);
            }
        }
        l--;
        swap(v, l, beg);
        quicksort(v, beg, l);
        quicksort(v, r, end);
    }
}


void selectionsort(vectorD *v, unsigned long int TAM){
    unsigned long int e, i, PosMenor;
    int val1, val2;
    for (e = 0; e < (TAM - 1); e++){
        PosMenor = e;
        for (i = e + 1; i < TAM; i++){
            if (Componentei(*v, i) < Componentei(*v, PosMenor)){
                PosMenor = i;
            }
        }
        swap(v, e, PosMenor);
    }
}