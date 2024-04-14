#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <stdio.h>
#include <stdlib.h>
#include "./vectordinamico.h"


void bubblesort(vectorD *v, unsigned long int TAM);
void quicksort(vectorD *pvector, unsigned long beg, unsigned long end);
void selectionsort(vectorD *v, unsigned long int TAM);
#endif