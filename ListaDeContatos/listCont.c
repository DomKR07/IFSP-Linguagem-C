#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listCont.h"

// Definicao da estrutura Elem
struct elemento {
    Cliente dados;
    struct elemento* prox;
};

// Funcao para criar uma lista vazia
Lista* criaLista() {
    // Aloca dinamicamente espaço na memória para a lista
    Lista* li = (Lista*)malloc(sizeof(Lista));
    // Verifica se a alocação de memória foi bem-sucedida
    if (li != NULL) {
        // Inicializa a lista como vazia
        *li = NULL;
    }
    // Retorna o ponteiro para a lista recém-criada
    return li;
}

// Funcao para liberar a memoria alocada para a lista
void liberaLista(Lista* li) {
    // Verifica se a lista não é nula
    if (li != NULL) {
        Elem* no; // Declaração de um ponteiro para um elemento da lista
        while (*li != NULL) {
            no = *li; // Atribui o endereço do primeiro elemento à variável 'no'
            *li = (*li)->prox; // Atualiza o ponteiro para o início da lista
            free(no); // Libera a memória alocada para o elemento removido
        }
        free(li); // Libera a memória alocada para o ponteiro da lista
    }
    }

// Funcao para salvar a lista em um arquivo binario
void salvaLista(Lista* li) {
    // Verifica se a lista e o ponteiro para a lista são diferentes de NULL
    if (li != NULL && *li != NULL) {
        // Abre o arquivo "contatos.bin" para escrita binária
        FILE* arquivo = fopen("contatos.bin", "wb");
        // Verifica se o arquivo foi aberto com sucesso
        if (arquivo != NULL) {
            // Inicializa um ponteiro para percorrer a lista
            Elem* no = *li;
            // Percorre a lista e escreve os dados de cada nó no arquivo binário
            while (no != NULL) {
                fwrite(&(no->dados), sizeof(Cliente), 1, arquivo);
                no = no->prox;
            }
            // Fecha o arquivo após concluir a escrita
            fclose(arquivo);
        } else {
            // Exibe uma mensagem de erro se não foi possível abrir o arquivo
            printf("Erro ao abrir o arquivo para escrita.\n");
        }
    }
}

// Funcao para inserir um cliente na lista de forma ordenada pelo codigo
void insereOrdenado(Lista* li, Cliente c) {
    // Verifica se a lista é válida
    if (li == NULL) {
        return;
    }
    // Aloca memória para um novo nó
    Elem* no = (Elem*)malloc(sizeof(Elem));
    // Verifica se a alocação de memória foi bem-sucedida
    if (no == NULL) {
        return;
    }
    // Preenche o novo nó com os dados do cliente
    no->dados = c;
    no->prox = NULL;

    // Caso a lista esteja vazia ou o novo elemento deve ser inserido no início
    if (*li == NULL || c.codigo < (*li)->dados.codigo) {
        no->prox = *li;
        *li = no;
        return;
    }

    // Inicializa ponteiros para percorrer a lista
    Elem* ant = *li;
    Elem* atual = (*li)->prox;

    // Percorre a lista até encontrar a posição correta para inserção
    while (atual != NULL && c.codigo > atual->dados.codigo) {
        ant = atual;
        atual = atual->prox;
    }

    // Insere o novo nó na posição correta da lista
    ant->prox = no;
    no->prox = atual;
}

// Funcao para exibir a lista de clientes
void exibeLista(Lista* li) {
    // Verifica se a lista é nula ou vazia
    if (li == NULL || *li == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    // Inicializa um ponteiro para percorrer a lista
    Elem* no = *li;
    // Percorre a lista enquanto o ponteiro não for nulo
    while (no != NULL) {
        // Exibe os dados do nó atual
        printf("\nCodigo: %d", no->dados.codigo);
        printf("\nNome: %s", no->dados.nome);
        printf("\nEmpresa: %s", no->dados.empresa);
        printf("\nDepartamento: %s", no->dados.departamento);
        printf("\nTelefone: %s", no->dados.telefone);
        printf("\nCelular: %s", no->dados.celular);
        printf("\nE-mail: %s\n", no->dados.email);
        printf("-------------------------\n");
        // Move para o próximo nó na lista
        no = no->prox;
    }
}

// Funcao para buscar e exibir um cliente pelo codigo
void buscaPorCodigo(Lista* li, int codigo) {
    // Verifica se a lista ou o primeiro elemento da lista são nulos
    if (li == NULL || *li == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    // Inicializa um ponteiro no para apontar para o início da lista
    Elem* no = *li;
    // Percorre a lista enquanto o nó não for nulo e o código não for encontrado
    while (no != NULL && no->dados.codigo != codigo) {
        no = no->prox;
    }
    // Verifica se o nó não é nulo (código encontrado) e exibe os dados ou informa que não foi encontrado
    if (no != NULL) {
        // Exibe os dados do cliente encontrado
        printf("\nCodigo: %d", no->dados.codigo);
        printf("\nNome: %s", no->dados.nome);
        printf("\nEmpresa: %s", no->dados.empresa);
        printf("\nDepartamento: %s", no->dados.departamento);
        printf("\nTelefone: %s", no->dados.telefone);
        printf("\nCelular: %s", no->dados.celular);
        printf("\nE-mail: %s\n", no->dados.email);
    } else {
        // Informa que o cliente com o código especificado não foi encontrado
        printf("\nCliente com codigo %d nao encontrado.\n", codigo);
    }
}

// Funcao para buscar e exibir cliente(s) pelo nome
void buscaPorNome(Lista* li, const char* nome) {
    // Verifica se a lista é válida ou está vazia
    if (li == NULL || *li == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    // Inicializa um ponteiro para percorrer a lista
    Elem* no = *li;
    // Variável para indicar se o elemento foi encontrado
    int encontrou = 0;

    // Percorre a lista enquanto houver elementos
    while (no != NULL) {
        // Compara o nome do elemento atual com o nome desejado
        if (strcmp(no->dados.nome, nome) == 0) {
            // Se encontrou, exibe as informações do elemento
            printf("\nCodigo: %d", no->dados.codigo);
            printf("\nNome: %s", no->dados.nome);
            printf("\nEmpresa: %s", no->dados.empresa);
            printf("\nDepartamento: %s", no->dados.departamento);
            printf("\nTelefone: %s", no->dados.telefone);
            printf("\nCelular: %s", no->dados.celular);
            printf("\nE-mail: %s\n", no->dados.email);
            encontrou = 1; // Marca que o elemento foi encontrado
        }
        // Move para o próximo elemento na lista
        no = no->prox;
    }

    // Se o elemento não foi encontrado, exibe uma mensagem correspondente
    if (!encontrou) {
        printf("\nCliente com nome %s nao encontrado.\n", nome);
    }
}

// Funcao para editar os dados de um cliente
void editaCliente(Lista* li, int codigo) {
    // Verifica se a lista ou a lista vazia
    if (li == NULL || *li == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    // Inicializa um ponteiro para percorrer a lista
    Elem* no = *li;
    // Procura o cliente com o código fornecido na lista
    while (no != NULL && no->dados.codigo != codigo) {
        no = no->prox;
    }
    // Verifica se o cliente com o código fornecido foi encontrado
    if (no != NULL) {
        // Exibe os dados atuais do cliente
        printf("\nDados atuais do cliente:\n");
        printf("Codigo: %d\n", no->dados.codigo);
        printf("Nome: %s\n", no->dados.nome);
        printf("Empresa: %s\n", no->dados.empresa);
        printf("Departamento: %s\n", no->dados.departamento);
        printf("Telefone: %s\n", no->dados.telefone);
        printf("Celular: %s\n", no->dados.celular);
        printf("E-mail: %s\n", no->dados.email);

        // Solicita a edicao dos dados
        printf("\nDigite os novos dados do cliente:\n");

        // Obtém os novos dados do cliente
        printf("Novo codigo: ");
        scanf("%d", &(no->dados.codigo)); // Corrigido para pegar o endereço da variável
        printf("Novo nome: ");
        scanf("%s", no->dados.nome);
        printf("Nova empresa: ");
        scanf("%s", no->dados.empresa);
        printf("Novo departamento: ");
        scanf("%s", no->dados.departamento);
        printf("Novo telefone: ");
        scanf("%s", no->dados.telefone);
        printf("Novo celular: ");
        scanf("%s", no->dados.celular);
        printf("Novo email: ");
        scanf("%s", no->dados.email);

        // Mensagem indicando que a edição foi bem-sucedida
        printf("\nCliente editado com sucesso.\n");
    } else {
        // Mensagem indicando que o cliente não foi encontrado
        printf("\nCliente com codigo %d nao encontrado.\n", codigo);
    }
}

// Funcao para remover um cliente da lista pelo codigo
void removeCliente(Lista* li, int codigo) {
    // Verifica se a lista é nula ou vazia
    if (li == NULL || *li == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    // Inicializa ponteiros para percorrer a lista
    Elem* ant = NULL; // Ponteiro para o elemento anterior
    Elem* no = *li; // Ponteiro para o elemento atual
    // Procura o cliente com o código especificado na lista
    while (no != NULL && no->dados.codigo != codigo) {
        ant = no; // Atualiza o ponteiro anterior
        no = no->prox; // Move para o próximo elemento
    }
    // Verifica se o cliente foi encontrado
    if (no != NULL) {
        // Remove o cliente da lista
        if (ant == NULL) {
            *li = no->prox; // O cliente é o primeiro da lista
        } else {
            ant->prox = no->prox; // O cliente está no meio ou no final da lista
        }
        free(no); // Libera a memória do nó removido
        printf("\nCliente removido com sucesso.\n");
    } else {
        printf("\nCliente com codigo %d nao encontrado.\n", codigo);
    }
}

// Funcao para carregar a lista de um arquivo binario
void carregaLista(Lista* li) {
    // Abre o arquivo binário "contatos.bin" no modo de leitura binária
    FILE* arquivo = fopen("contatos.bin", "rb");
    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo != NULL) {
        // Declara uma variável do tipo Cliente para armazenar os dados lidos do arquivo
        Cliente c;
        // Loop para ler dados do arquivo enquanto a leitura for bem-sucedida
        while (fread(&c, sizeof(Cliente), 1, arquivo) == 1) {
            // Chama a função insereOrdenado para inserir o cliente na lista mantendo a ordem
            insereOrdenado(li, c);
        }
        // Fecha o arquivo após concluir a leitura
        fclose(arquivo);
    }
}
