#include <stdio.h>
#include <stdlib.h>

void imprimirLista(int * lista, int largo, char* textoAMostrar){
    printf("Los números %s son: ",textoAMostrar);  
    for (int i = 0; i < largo; i++) {
        printf(" %d ", *(lista + i));
    }
    printf("\n");
}

int filter(int numeros[], int** lista, int (*unCriterio)(int)) {
    int cantidadDeElementosFiltrados = 0;
    for (int i = 0; i < 10; i++) {
        if (unCriterio (numeros[i])) {
            cantidadDeElementosFiltrados = cantidadDeElementosFiltrados + 1;
            if (cantidadDeElementosFiltrados == 1) {
              * lista = (int*)malloc(sizeof(int));
            }
            else{
              * lista = (int *)realloc(*lista, sizeof(int)*cantidadDeElementosFiltrados);
            }
            * (*lista + cantidadDeElementosFiltrados -1)  = numeros[i];
        }
    }
    return cantidadDeElementosFiltrados;
}