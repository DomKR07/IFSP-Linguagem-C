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
    struct funcionario funcionario;

    // Abra o arquivo binário para leitura
    arquivo = fopen("funcionarios.bin", "rb");

    // Verifique se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Procure o terceiro funcionário no arquivo
    fseek(arquivo, sizeof(struct funcionario) * 2, SEEK_SET);

    // Leia o terceiro funcionário do arquivo
    fread(&funcionario, sizeof(struct funcionario), 1, arquivo);

    // Feche o arquivo
    fclose(arquivo);

    // Imprima os dados do terceiro funcionário
    printf("Terceiro Funcionário:\n");
    printf("ID: %d\n", funcionario.ID);
    printf("Nome: %s\n", funcionario.nome);
    printf("Idade: %d\n", funcionario.idade);
    printf("Salário: %.2f\n", funcionario.salario);

    return 0;
}

