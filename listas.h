#ifndef LISTAS_H_
#define LISTAS_H_

void imprimirLista(int * lista, int largo, char* textoAMostrar);
int filter(int numeros[], int** lista, int (*unCriterio)(int));

#endif /* LISTAS_H_ */