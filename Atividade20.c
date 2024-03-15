#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // Número de elementos no vetor
    printf("Digite o número de elementos no vetor: ");
    scanf("%d", &n);

    int *vetor_malloc = (int *)malloc(n * sizeof(int));

    if (vetor_malloc == NULL) {
        printf("Erro ao alocar memória com malloc\n");
        return 1;
    }

    for (int i = 0, valor = 1; i < n; i++, valor += 2) {
        vetor_malloc[i] = valor;
    }

    printf("Vetor alocado com malloc:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor_malloc[i]);
    }
    printf("\n");

    int *vetor_calloc = (int *)calloc(n, sizeof(int));

    if (vetor_calloc == NULL) {
        printf("Erro ao alocar memória com calloc\n");
        return 1;
    }

    for (int i = 0, valor = 1; i < n; i++, valor += 2) {
        vetor_calloc[i] = valor;
    }

    printf("Vetor alocado com calloc:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor_calloc[i]);
    }
    printf("\n");

    int novo_tamanho = n * 2;
    int *vetor_realloc = (int *)realloc(vetor_malloc, novo_tamanho * sizeof(int));

    if (vetor_realloc == NULL) {
        printf("Erro ao realocar memória com realloc\n");
        return 1;
    }

    for (int i = n, valor = vetor_malloc[n - 1] + 2; i < novo_tamanho; i++, valor += 2) {
        vetor_realloc[i] = valor;
    }

    printf("Vetor realocado com realloc:\n");
    for (int i = 0; i < novo_tamanho; i++) {
        printf("%d ", vetor_realloc[i]);
    }
    printf("\n");

    free(vetor_malloc);
    free(vetor_calloc);
    free(vetor_realloc);

    return 0;
}
