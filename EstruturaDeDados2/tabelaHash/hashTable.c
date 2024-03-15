// hashTable.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h"

struct hash {
    int qtd;
    int TABLE_SIZE;
    struct aluno **itens;
};

int chaveDivisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int valorString(char *str) {
    int i, valor = 7;
    int tam = strlen(str);
    for (i = 0; i < tam; i++) {
        valor = 31 * valor + (int)str[i];
    }
    return valor;
}

void redimensionaTabela(Hash *ha, int novoTamanho) {
    if (ha == NULL || novoTamanho <= ha->TABLE_SIZE)
        return;

    int i;
    Hash *novaTabela = criaHash(novoTamanho);

    for (i = 0; i < ha->TABLE_SIZE; i++) {
        if (ha->itens[i] != NULL) {
            if (!insereHash_semColisao(novaTabela, *(ha->itens[i])))
                printf("Erro ao redimensionar a tabela.\n");
            free(ha->itens[i]);
        }
    }

    free(ha->itens);
    ha->itens = novaTabela->itens;
    ha->TABLE_SIZE = novoTamanho;
    free(novaTabela);
}

int insereHash_semColisao(Hash *ha, struct aluno al) {
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE) {
        return 0;
    }

    int chave = al.matricula;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);

    struct aluno *novo = (struct aluno*)malloc(sizeof(struct aluno));
    if (novo == NULL) {
        return 0;
    }

    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int buscaHash_semColisao(Hash *ha, int mat, struct aluno *al) {
    if (ha == NULL) {
        return 0;
    }

    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if (ha->itens[pos] == NULL) {
        return 0;
    }

    *al = *(ha->itens[pos]);
    return 1;
}

int sondagemLinear(int pos, int i, int TABLE_SIZE) {
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_enderecoAberto(Hash *ha, struct aluno al) {
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE) {
        return 0;
    }

    int chave = al.matricula;
    int i, pos, newPos;
    pos = chaveDivisao(chave, ha->TABLE_SIZE);

    for (i = 0; i < ha->TABLE_SIZE; i++) {
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if (ha->itens[newPos] == NULL) {
            struct aluno *novo = (struct aluno*)malloc(sizeof(struct aluno));
            if (novo == NULL) {
                return 0;
            }

            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }

    return 0;
}

int buscaHash_enderecoAberto(Hash *ha, int mat, struct aluno *al) {
    if (ha == NULL) {
        return 0;
    }

    int i, pos, newPos;
    pos = chaveDivisao(mat, ha->TABLE_SIZE);
    for (i = 0; i < ha->TABLE_SIZE; i++) {
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);

        if (ha->itens[newPos] == NULL) {
            return 0;
        }

        if (ha->itens[newPos]->matricula == mat) {
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }

    return 0;
}

Hash *criaHash(int TABLE_SIZE) {
    Hash *ha = (Hash*) malloc(sizeof (Hash));
    if (ha != NULL) {
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**) malloc(TABLE_SIZE * sizeof(struct aluno*));

        if (ha->itens == NULL) {
            free (ha);
            return NULL;
        }
            ha->qtd = 0;
                for (i = 0; i < ha->TABLE_SIZE; i++) {
                    ha->itens[i] = NULL;
                }
        }
        return ha;
    }
void liberaHash (Hash *ha) {
    if (ha != NULL) {
        int i;
        for (i = 0; i < ha->TABLE_SIZE; i++) {
            if(ha->itens[i] != NULL) {
                free (ha->itens[i]);
            }
        }
        free (ha->itens);
        free (ha);
    }
}
