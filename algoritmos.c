#include <stdio.h>
#include <stdlib.h>
#include "./P1_v3/vectordinamico.h"


#define TAM 100
void Burb1(vectorD *v)
{
int e,i,aux;
for (e=0;e<(TAM-1);e++)
for (i=0;i<(TAM-e-1);i++){
    if (v[i]>v[i+1])
        {
        aux=v[i];
        v[i]=v[i+1];
        v[i+1]=aux;
        }
    }
}