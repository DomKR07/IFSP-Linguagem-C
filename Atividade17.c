#include <stdio.h>

int main() {
    float vetorFloat[10];
    double vetorDouble[10];

    for (int i = 0; i < 10; i++) {
        vetorFloat[i] = (float)i;
        vetorDouble[i] = (double)i;
    }

    printf("Endereços do vetor de float:\n");
    for (int i = 0; i < 10; i++) {
        printf("Posição %d: %p\n", i, &vetorFloat[i]);
    }

    printf("\nEndereços do vetor de double:\n");
    for (int i = 0; i < 10; i++) {
        printf("Posição %d: %p\n", i, &vetorDouble[i]);
    }

    return 0;
}
