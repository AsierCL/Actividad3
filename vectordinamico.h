#ifndef VECTORDINAMICO_H
#define VECTORDINAMICO_H

typedef float TELEMENTO; /*Tipo de datos del vector*/
typedef void * vectorD; /*tipo opaco*/

/*Funciones exportadas*/
/*Función CreaVector: asigna memoria y devuelve la asignación al vector*/
void CreaVector(vectorD *v1,short tam1);
/*Función AsignaVector: Llena una posición del vector con un valor*/
void AsignaVector(vectorD *v1,short posicion,TELEMENTO valor);


#endif /*VECTORDINAMICO_H*/




TELEMENTO Componentei(vectorD v1,short posicion);
int EsNulo(vectorD v1);
void LiberaVector(vectorD *v1);
short tamano(vectorD v1);

//////////////////////////////////////
//////////////////////////////////////
void liberar(vectorD *vectorV1);
TELEMENTO recuperar(vectorD v1, short posicion);
short longitudVector(vectorD v1);