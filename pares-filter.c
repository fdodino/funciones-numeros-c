#include <stdio.h>
#include <stdlib.h>

int even(int nro) {
  return nro % 2 == 0;
}

int odd(int nro) {
  return nro % 2 == 1;
}

int filter(int numeros[], int** lista, int (*unCriterio)(int)) {
    int cantidad = 0;
    for (int i = 0; i < 10; i++) {
        if (unCriterio (numeros[i])) {
            cantidad = cantidad + 1;
            if (cantidad == 1) {
              * lista = (int*)malloc(sizeof(int));
            }
            else{
              * lista = (int *)realloc(*lista, sizeof(int)*cantidad);
            }
            * (*lista + cantidad -1)  = numeros[i];
        }
    }
    return cantidad;
}

void imprimirResultados(int * lista, int largo){
    printf("Los números pares son: ");  
    for (int i = 0; i < largo; i++) {
        printf(" %d ", *(lista + i));
    }
    printf("\n");
}


int main() {
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* resultados;
    int largoResultado;
    largoResultado = filter(numeros, &resultados, &even);
    imprimirResultados(resultados,largoResultado);
    free(resultados);
    largoResultado = filter(numeros, &resultados, &odd);
    imprimirResultados(resultados,largoResultado);
    free(resultados);
    return 0;
}