#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n; // Dimensões das matrizes
    int **matriz1, **matriz2, **resultado;

    printf("Digite o número de linhas (M): ");
    scanf("%d", &m);
    printf("Digite o número de colunas (N): ");
    scanf("%d", &n);

    matriz1 = (int **)calloc(m, sizeof(int *));
    for (int i = 0; i < m; i++) {
        matriz1[i] = (int *)calloc(n, sizeof(int));
    }

    matriz2 = (int **)calloc(m, sizeof(int *));
    for (int i = 0; i < m; i++) {
        matriz2[i] = (int *)calloc(n, sizeof(int));
    }

    resultado = (int **)calloc(m, sizeof(int *));
    for (int i = 0; i < m; i++) {
        resultado[i] = (int *)calloc(n, sizeof(int));
    }

    printf("Digite os valores da matriz 1 (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Digite os valores da matriz 2 (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    printf("A matriz resultado é:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(matriz1[i]);
        free(matriz2[i]);
        free(resultado[i]);
    }
    free(matriz1);
    free(matriz2);
    free(resultado);

    return 0;
}
