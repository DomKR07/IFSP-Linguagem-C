#include <stdio.h>
#include <stdlib.h>
#include "filaD.h"

struct fila{
    struct elemento *inicio;
    struct elemento *fim;
};
struct elemento{
    ALUNO dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Fila *cria_fila(){
    Fila *fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->fim = NULL;
        fi->inicio = NULL;
    }
    return fi;
};

int tamanho_fila(Fila *fi){
    if(fi == NULL){
        return 0;
    }
    int acum = 0;
    Elem *no = fi->inicio;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}

int fila_cheia(Fila *fi){
    return 0;
}

int fila_vazia(Fila *fi){
    if(fi == NULL){
        return 1;
    }
    if(fi->inicio == NULL){
        return 1;
    }
    return 0;
}

int insere_fila(Fila *fi, ALUNO al){
    if(fi == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no-> prox = NULL;
    if(fi->fim == NULL){//fila vazia
            fi->inicio = no;
    }else{//insere no final da fila
        fi->fim->prox = no;
    }
    fi->fim = no;//no passa a ser novo final da fila
    return 1;
}

void destroi_fila(Fila *fi){
    if(fi != NULL){
        Elem *no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
};
