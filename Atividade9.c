#include <stdio.h>
#include <string.h>

int main() {
    char nome[20];
    char sobrenome1[20];
    char sobrenome2[20];

    printf("Digite o primeiro nome: ");
    scanf("%s", nome);

    printf("Digite o primeiro sobrenome: ");
    scanf("%s", sobrenome1);

    printf("Digite o segundo sobrenome: ");
    scanf("%s", sobrenome2);

    printf("Nome completo: %s %s %s\n", nome, sobrenome1, sobrenome2);

    return 0;
}
