#include <stdio.h>

// primera variante

void coso(int r[], int a[]) {
    int j = 0;
    for (int i = 0; i < 10; i++) {
        if (r[i] % 2 == 0) {
            a[j++] = r[i];
        }
    }
}

int main() {
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int y[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    coso(x, y);
    for (int i = 0; i < 10; i++) {
        printf(" %d ", y[i]);
    }
    printf("\n");
    return 0;
}

