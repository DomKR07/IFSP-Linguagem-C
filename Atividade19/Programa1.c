#include <stdio.h>
#include <stdlib.h>

struct funcionario {
    int ID;
    char nome[30];
    int idade;
    float salario;
};

int main() {
    FILE *arquivo;
    struct funcionario funcionarios[5];

    // Preencha o vetor de funcionários com informações
    for (int i = 0; i < 5; i++) {
        printf("Funcionário %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &funcionarios[i].ID);
        printf("Nome: ");
        scanf("%s", funcionarios[i].nome);
        printf("Idade: ");
        scanf("%d", &funcionarios[i].idade);
        printf("Salário: ");
        scanf("%f", &funcionarios[i].salario);
    }

    // Abra o arquivo binário para escrita
    arquivo = fopen("funcionarios.bin", "wb");

    // Verifique se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Escreva o vetor de funcionários no arquivo
    fwrite(funcionarios, sizeof(struct funcionario), 5, arquivo);

    // Feche o arquivo
    fclose(arquivo);

    printf("Dados dos funcionários foram salvos no arquivo 'funcionarios.bin'\n");

    return 0;
}

