#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[30];
    int idade;
    float salario;
} FUNCIONARIO;

FUNCIONARIO coletarDados() {
    FUNCIONARIO func;

    printf("Digite o ID do funcionario: ");
    scanf("%d", &func.id);
    printf("Digite o nome do funcionario: ");
    scanf("%s", func.nome);
    printf("Digite a idade do funcionario: ");
    scanf("%d", &func.idade);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &func.salario);

    return func;
}

void imprimirDados(FUNCIONARIO f[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Dados da pessoa %d\n", i + 1);
        printf("ID......:%d\n", f[i].id);
        printf("Nome....:%s\n", f[i].nome);
        printf("Idade...:%d\n", f[i].idade);
        printf("Salario.:%.2f\n\n\n", f[i].salario);
    }
}

void rel_salario_corrigido(float *salario) {
    *salario *= 1.10; // Aumento de 10%
}

int main() {
    int n = 5;
    FUNCIONARIO f[n];

    for (int i = 0; i < n; i++) {
        printf("Digite os dados do funcionario %d:\n", i + 1);
        f[i] = coletarDados();
        printf("\n\n\n");
    }

    imprimirDados(f, n);

    for (int i = 0; i < n; i++) {
        rel_salario_corrigido(&f[i].salario);
    }

    printf("Após o reajuste:\n");
    imprimirDados(f, n);

    system("pause");
}
