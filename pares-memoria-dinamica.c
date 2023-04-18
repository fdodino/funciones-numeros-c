#include <stdio.h>
#include <stdlib.h>

int filtrarPares(int numeros[], int** pares) {
    int canitdadDePares = 0;
    for (int i = 0; i < 10; i++) {
        if (numeros[i] % 2 == 0) {
            canitdadDePares = canitdadDePares + 1;
            if (canitdadDePares == 1) {
              * pares = (int*)malloc(sizeof(int));
            }
            else{
              * pares = (int *)realloc(*pares, sizeof(int)*canitdadDePares);
            }
            * (*pares + canitdadDePares -1)  = numeros[i];
        }
    }
    return canitdadDePares;
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* pares;
    int largoPares;
    largoPares = filtrarPares(numeros, &pares);
    printf("Los números pares son: ");  
    for (int i = 0; i < largoPares; i++) {
        printf(" %d ", *(pares + i));
    }
    printf("\n");
    free(pares);
    return 0;
}
