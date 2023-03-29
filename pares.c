#include <stdio.h>

void filtrarPares(int numeros[], int pares[]) {
    int j = 0;
    for (int i = 0; i < 10; i++) {
        if (numeros[i] % 2 == 0) {
            pares[j] = numeros[i];
            j++;
        }
    }
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int pares[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    filtrarPares(numeros, pares);
    printf("Los números pares son: ");  
    for (int i = 0; i < 10; i++) {
        printf(" %d ", pares[i]);
    }
    printf("\n");
    return 0;
}

