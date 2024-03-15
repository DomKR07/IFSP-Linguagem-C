#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listCont.h" // Inclui o arquivo de cabeçalho com as definições da lista

int main() {
    Lista* lista = criaLista(); // Cria uma lista vazia
    carregaLista(lista); // Carrega os dados do arquivo binário

    int opcao;

    do {
        system("cls"); // Limpa a tela

        // Menu de opções
        printf("\n\n***********************************************\n");
        printf("                   Menu:\n");
        printf("***********************************************\n");
        printf("1. Inserir novo cliente\n");
        printf("2. Exibir lista de clientes\n");
        printf("3. Buscar por codigo\n");
        printf("4. Buscar por nome\n");
        printf("5. Editar cliente\n");
        printf("6. Remover cliente\n");
        printf("7. Salvar e sair\n");
        printf("***********************************************\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                // Adição de um novo cliente
                Cliente novoCliente;
                // Preenche os dados do novo cliente
                printf("\nDigite o codigo do cliente: ");
                scanf("%d", &novoCliente.codigo);

                getchar();

                printf("Digite o nome do cliente: ");
                fgets(novoCliente.nome,50, stdin);
                novoCliente.nome[strcspn(novoCliente.nome, "\n")] = '\0'; // Remove o \n, se presente

                printf("Digite a empresa do cliente: ");
                fgets(novoCliente.empresa,50, stdin);
                novoCliente.empresa[strcspn(novoCliente.empresa, "\n")] = '\0';

                printf("Digite o departamento do cliente: ");
                fgets(novoCliente.departamento,50, stdin);
                novoCliente.departamento[strcspn(novoCliente.departamento, "\n")] = '\0';

                printf("Digite o telefone do cliente: ");
                fgets(novoCliente.telefone,50, stdin);
                novoCliente.telefone[strcspn(novoCliente.telefone, "\n")] = '\0';

                printf("Digite o celular do cliente: ");
                fgets(novoCliente.celular,50, stdin);
                novoCliente.celular[strcspn(novoCliente.celular, "\n")] = '\0';

                printf("Digite o email do cliente: ");
                fgets(novoCliente.email,50, stdin);
                novoCliente.email[strcspn(novoCliente.email, "\n")] = '\0';

                insereOrdenado(lista, novoCliente); // Insere o novo cliente na lista

                system("pause"); // Pausa a execução para que o usuário possa ver a mensagem

                break;
            }

            case 2:
                exibeLista(lista); // Exibe a lista de clientes

                system("pause"); // Pausa a execução para que o usuário possa ver a mensagem

                break;

            case 3: {
                int codigo;
                printf("\nDigite o codigo do cliente: ");
                scanf("%d", &codigo); //Coleta do codigo para busca
                buscaPorCodigo(lista, codigo); // Busca e exibe o cliente pelo codigo

                system("pause"); // Pausa a execução para que o usuário possa ver a mensagem

                break;
            }

            case 4: {
                getchar(); // Limpa o buffer do teclado
                char nome[50];
                printf("\nDigite o nome do cliente: ");
                fgets(nome, sizeof(nome), stdin); //Coleta o nome a ser buscado mesmo se houver uso de espaços
                nome[strcspn(nome, "\n")] = '\0'; // Remove o \n, se presente
                buscaPorNome(lista, nome);

                system("pause"); // Pausa a execução para que o usuário possa ver a mensagem

                break;
            }

            case 5: {
                int codigo;
                printf("\nDigite o codigo do cliente a ser editado: ");
                scanf("%d", &codigo); //Coleta o codigo do cliente a ser editado
                editaCliente(lista, codigo); // Edita os dados do cliente

                system("pause"); // Pausa a execução para que o usuário possa ver a mensagem

                break;

            }
            case 6: {
                int codigo;
                printf("\nDigite o codigo do cliente a ser removido: ");
                scanf("%d", &codigo); //Coleta o codigo do cliente a ser removido
                removeCliente(lista, codigo); // Remove o cliente da lista

                system("pause"); // Pausa a execução para que o usuário possa ver a mensagem

                break;
            }
            case 7:
                salvaLista(lista); // Salva a lista em um arquivo
                liberaLista(lista); // Libera a memoria alocada para a lista
                printf("\nEncerrando o programa.\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}
