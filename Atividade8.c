#include <stdio.h>

int main() {
    char nome[40];
    int idade;
    float salario;

    printf("Digite o nome do trabalhador: ");
    fgets(nome, sizeof(nome), stdin);
    printf("Digite a idade do trabalhador: ");
    scanf("%d", &idade);
    printf("Digite o salario do trabalhador: ");
    scanf("%f", &salario);

    printf("\n\nDados do trabalhador:\n");
    printf("Nome: %s", nome);
    printf("Idade: %d anos\n", idade);
    printf("Salario: R$ %.2f\n", salario);

    return 0;
}
