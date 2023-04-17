# Ejemplo de filtrado de pares

## Primer solución - vectores

Para la primer solución vamos a platear el archivo [pares.c](pares.c). Aquí podemos ver un main donde generamos dos vectores: 

- **numeros[]** que modela la lista de números que deseamos filtrar.
- **pares[]** que modela la lista de los números resultantes del filtrado. Inicialmente arrancamos con todos los valores en cero. 

Luego delegamos el proceso de filtrado en la función `filtrarPares` que es de aridad 2 *(Conocemos por aridad al número de parámetros de entrada que acepta una función)*. 
```c
void filtrarPares(int numeros[], int pares[]) {
    int j = 0;
    for (int i = 0; i < 10; i++) {
        if (numeros[i] % 2 == 0) {
            pares[j] = numeros[i];
            j++;
        }
    }
}
```
Con las herramientas que disponemos hasta el momento, la fomra más simple de filtrar los pares es mediante un bucle `for`. Esto nos lleva a inicializar por fuera una variable `j` para mantener el índice de la posición del vector resultante. Dentro del bucle declaramos una variable `i` pero en este caso modelando al índice del vector de números que vamos a usar como colección de origen. 
Los valores iniciales de `i` y `j` toman inicialmente el valor 0, pero podría no serlo. Esta es una decisión de diseño. 
Dentro del bucle de repetición, cuando se cunple la función del condicional `if` asignamos el valor en la posición del vector de resultados.

¿Es una solución declarativa? Mmm... no parece serlo dado que tengo mucho control sobre el algoritmo. Este código se enfoca claramente en el **cómo** resuelvo el requerimiento y no en el **qué** estoy buscando. 

---

## Segunda solución - Memoria dinámica.
En el archivo [pares-memoria-dinamica.c](pares-memoria-dinamica.c) podemos ver una solución con algunas mejoras. En primer lugar en el main no vamos a definir la colección resultante como un array de longitud fija y los valores inicializados en cero, 
sino que vamos a utilizar [punteros y asignación dinámica de memoria](https://docs.utnso.com.ar/guias/programacion/punteros).

Un puntero es la dirección de algún dato en memoria. Un puntero **NO** es el dato en sí mismo, sino su posición en la memoria. También se lo conoce como referencia a memoria.
Por lo tanto definimos a `pares` como un puntero `int*`. El mismo lo pasamos por referencia a la función `filtrarPares` que en este caso va a devolver el largo de la colección de resultados obtenidos. 

```c
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
```
Pueden notar que como pasamos el puntero del vector resultante por referencia (es decir la dirección de la variable que tiene como valor el puntero), entocnes lo que vamos a manipular dentro de la funció nes un puntero a puntero. 

La variable que determinaba el índice del vector resultante, ahora lo llamamos `canitdadDePares`, un nombre que representa mucho mejor qué es lo que estamos modelando, es decir, un nombre mucho más [expresivo](https://wiki.uqbar.org/wiki/articles/expresividad.html).
Nuevamente contamos con el bucle for para recorrer el vector de origen, pero en este caso la aserción del `if` es más compleja: Tenemos que diferenciar si es la primera vez que vamos a agregar un número a la lista resultante o no. ¿Por qué? porque debemos 

- Solicitar memoria dinámica por primera vez (malloc).
- Agrandar el espacio YA solicitado (realloc).

Tanto `malloc` como `realloc` necesitan que les pasemos el tamaño a solicitar. Por dicho motivo en el `malloc` vamos a pedir un tamaño de un entero (`sizeof(int)`) y en el caso de `realloc` pedimos la cantidad de resultados que disponemos por un entero (`sizeof(int)*canitdadDePares`).
Luego asignamos el valor del número par en el contenido del puntero. Al finalizar el ciclo de recorrido, vamos a devolver el largo del vector resultante a fin de poder recorrerlo por fuera de la función. 

## ¿Y Si ahora quiero los impares?
Mmmm... lo que tenemos que hacer es crear una nueva función para los impares. La lógica a desarrollar es la misma, por lo tanto *copiamos y pegamos* la definición de nuestra función y hacemos un cambio mínimo

```c
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

int filtrarImares(int numeros[], int** pares) {
    int canitdadDeImpares = 0;
    for (int i = 0; i < 10; i++) {
        if (numeros[i] % 2 == 1) {
            canitdadDeImpares = canitdadDeImpares + 1;
            if (canitdadDeImpares == 1) {
              * pares = (int*)malloc(sizeof(int));
            }
            else{
              * pares = (int *)realloc(*pares, sizeof(int)*canitdadDeImpares);
            }
            * (*pares + canitdadDeImpares -1)  = numeros[i];
        }
    }
    return canitdadDeImpares;
}
```

La única diferencia en la función es el cambio de variables en términos de expresividad (`cantidadDePares` por `cantidadDeImpares`) y la función que evalúa el if al momento de decidir si se queda o no con el elemento (`numeros[i] % 2 == 0` por `numeros[i] % 2 == 1`)


