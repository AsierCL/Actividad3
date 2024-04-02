/* 
 * File:   main.c
 * Author: alberto
 *
 * Created on 9 de marzo de 2010, 10:46
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



unsigned long fibonacciRecursivo(unsigned char n){

    if (n>1)
        return fibonacciRecursivo(n-1)+fibonacciRecursivo(n-2);
    else
        return (unsigned long)1;
}
/*
 * 
 */
int main(int argc, char** argv) {

clock_t inicio=-1, fin=-1;
unsigned long f; //El mayor rango de representación en enteros positivos
unsigned char n; //El menor rango de representación en enteros positivos

FILE *fp;

fp=fopen("tiemposFibonacciRecursivo.txt", "w"); //Fichero para los datos de salida

for(n=0; n<45; n++){ //Los 45 primeros términos de la sucesión
    inicio=clock(); //TOMAMOS LA PRIMERA REFERENCIA
/* AQUÍ IRÍA EL CONJUNTO DE INSTRUCCIONES QUE QUEREMOS MEDIR */
    
    f=fibonacciRecursivo(n);

    fin=clock(); //TOMAMOS LA SEGUNDA REFERENCIA
//IMPRIMIMOS EL RESULTADO
    printf("n:%u\tf(n):%u\tini.:%u\tfin:%d\ttiempo:%.4lf\n", n, f, fin, inicio, (fin-inicio)/(double)CLOCKS_PER_SEC);
    fprintf(fp, "%u\t%.4lf\n", n, (fin-inicio)/(double)CLOCKS_PER_SEC); //Salida de los datos n, t(n) a fichero
}
fclose(fp);
return (EXIT_SUCCESS);
}

