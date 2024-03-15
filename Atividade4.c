
#include <stdio.h>
#include <stdlib.h>

int main() {
    int v1[5], v2[5];
    int i, j;
    int comum = 0;

    printf("Digite os valores do vetor 1\n");
    for (i = 0; i < 5; i++) {
        printf("Informe o valor do elemento %d: ", i + 1);
        scanf("%d", &v1[i]);
    }

    printf("\nDigite os valores do vetor 2\n");
    for (j = 0; j < 5; j++) {
        printf("Informe o valor do elemento %d: ", j + 1);
        scanf("%d", &v2[j]);
    }

    printf("\nVetor 1: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", v1[i]);
    }

    printf("\nVetor 2: ");
    for (j = 0; j < 5; j++) {
        printf("%d ", v2[j]);
    }

    printf("\n\nValores comuns nos vetores: ");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (v1[i] == v2[j]) {
                printf("(%d, %d) ", i + 1, j + 1);
                comum = 1;
            }
        }
    }

    if (comum == 0) {
        printf("Nenhum valor comum encontrado.");
    }

    printf("\n");
    system("pause");
}
