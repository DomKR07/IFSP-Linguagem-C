// main.c
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

int main() {
    int opcao;
    int tamanho;
    int continuar;

    printf("Digite o tamanho da tabela hash: ");
    scanf("%d", &tamanho);

    Hash *tabela = criaHash(tamanho);

    do {
        printf("\n\n***************************************\n");
        printf("                Menu:\n");
        printf("***************************************\n");
        printf("1. Inserir aluno (sem tratamento de colisao)\n");
        printf("2. Buscar aluno (sem tratamento de colisao)\n");
        printf("3. Inserir aluno (com tratamento de colisao)\n");
        printf("4. Buscar aluno (com tratamento de colisao)\n");
        printf("5. Redimensionar tabela\n");
        printf("6. Encerrar programa\n");
        printf("***************************************\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                struct aluno novoAluno;
                printf("\nDigite a matricula do aluno: ");
                scanf("%d", &novoAluno.matricula);
                printf("Digite o nome do aluno: ");
                scanf("%s", novoAluno.nome);
                if (insereHash_semColisao(tabela, novoAluno))
                    printf("\nAluno inserido com sucesso!\n");
                else
                    printf("\nErro ao inserir aluno.\n");
                break;
            }
            case 2: {
                int matriculaBusca;
                printf("\nDigite a matricula do aluno a ser buscado: ");
                scanf("%d", &matriculaBusca);

                struct aluno alunoBusca;
                if (buscaHash_semColisao(tabela, matriculaBusca, &alunoBusca)) {
                    printf("\nAluno encontrado:\n");
                    printf("Matricula: %d\n", alunoBusca.matricula);
                    printf("Nome: %s\n", alunoBusca.nome);
                } else {
                    printf("\nAluno nao encontrado.\n");
                }
                break;
            }
            case 3: {
                struct aluno novoAluno;
                printf("\nDigite a matricula do aluno: ");
                scanf("%d", &novoAluno.matricula);
                printf("Digite o nome do aluno: ");
                scanf("%s", novoAluno.nome);
                if (insereHash_enderecoAberto(tabela, novoAluno))
                    printf("\nAluno inserido com sucesso!\n");
                else
                    printf("\nErro ao inserir aluno.\n");
                break;
            }
            case 4: {
                int matriculaBusca;
                printf("\nDigite a matricula do aluno a ser buscado: ");
                scanf("%d", &matriculaBusca);
                struct aluno alunoBusca;
                if (buscaHash_enderecoAberto(tabela, matriculaBusca, &alunoBusca)) {
                    printf("\nAluno encontrado:\n");
                    printf("Matricula: %d\n", alunoBusca.matricula);
                    printf("Nome: %s\n", alunoBusca.nome);
                } else {
                    printf("\nAluno nao encontrado.\n");
                }
                break;
            }
            case 5: {
                int novoTamanho;
                printf("\nDigite o novo tamanho da tabela hash: ");
                scanf("%d", &novoTamanho);
                redimensionaTabela(tabela, novoTamanho);
                printf("\nTabela redimensionada com sucesso!\n");
                break;
            }
            case 6:
                continuar = 0;
                printf("\nEncerrando o programa.\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

        printf("\nDeseja realizar outra operacao? (1 - Sim / 0 - Nao): ");
        scanf("%d", &continuar);

    } while (continuar);

    liberaHash(tabela);

    return 0;
}
