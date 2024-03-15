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

    // Abra o arquivo bin�rio para leitura
    arquivo = fopen("funcionarios.bin", "rb");

    // Verifique se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Procure o terceiro funcion�rio no arquivo
    fseek(arquivo, sizeof(struct funcionario) * 2, SEEK_SET);

    // Leia o terceiro funcion�rio do arquivo
    fread(&funcionario, sizeof(struct funcionario), 1, arquivo);

    // Feche o arquivo
    fclose(arquivo);

    // Imprima os dados do terceiro funcion�rio
    printf("Terceiro Funcion�rio:\n");
    printf("ID: %d\n", funcionario.ID);
    printf("Nome: %s\n", funcionario.nome);
    printf("Idade: %d\n", funcionario.idade);
    printf("Sal�rio: %.2f\n", funcionario.salario);

    return 0;
}

