#include <stdlib.h>
#include "listas.h"

int even(int nro) {
  return nro % 2 == 0;
}

int odd(int nro) {
  return nro % 2 == 1;
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* resultados;
    int largoResultado;
    largoResultado = filter(numeros, &resultados, &even);
    imprimirLista(resultados,largoResultado, "pares");
    free(resultados);
    largoResultado = filter(numeros, &resultados, &odd);
    imprimirLista(resultados,largoResultado,"impares");
    free(resultados);
    return 0;
}