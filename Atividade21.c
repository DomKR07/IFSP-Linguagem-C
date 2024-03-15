#include <stdio.h>
#include <stdlib.h>

int main() {
    int numAlunos;

    printf("Digite a quantidade de alunos na turma: ");
    scanf("%d", &numAlunos);

    float *notas = (float *)calloc(numAlunos, sizeof(float));

    if (notas == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("Digite as notas dos alunos:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    float soma = 0.0;
    for (int i = 0; i < numAlunos; i++) {
        soma += notas[i];
    }
    float media = soma / numAlunos;

    printf("\nNotas dos alunos:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Aluno %d: %.2f\n", i + 1, notas[i]);
    }

    printf("\nMédia da turma: %.2f\n", media);

    free(notas);

    return 0;
}
