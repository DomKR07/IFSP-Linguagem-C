#include <stdio.h>

int main() {
    float vetorFloat[10];
    double vetorDouble[10];

    for (int i = 0; i < 10; i++) {
        vetorFloat[i] = (float)i;
        vetorDouble[i] = (double)i;
    }

    printf("Endere�os do vetor de float:\n");
    for (int i = 0; i < 10; i++) {
        printf("Posi��o %d: %p\n", i, &vetorFloat[i]);
    }

    printf("\nEndere�os do vetor de double:\n");
    for (int i = 0; i < 10; i++) {
        printf("Posi��o %d: %p\n", i, &vetorDouble[i]);
    }

    return 0;
}
