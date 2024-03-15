#include <stdio.h>
#include <stdlib.h>
#include "filaD.h"

int main(){
    int x;//para os codigos de erro
    ALUNO al, al1, al2, al3;
    al1.matricula = 100;
    al1.n1 = 8.3;
    al1.n2 = 8.4;
    al1.n3 = 8.5;

    al2.matricula = 110;
    al2.n1 = 7.3;
    al2.n2 = 7.4;
    al2.n3 = 7.5;

    al3.matricula = 120;
    al3.n1 = 6.3;
    al3.n2 = 6.4;
    al3.n3 = 6.5;

    Fila *fi;//ponteiro para o no descritor

    fi = cria_fila();

    x = tamanho_fila(fi);
    printf("\nO tamanho da fila e: %d", x);

    x = fila_cheia(fi);
    if(x){
        printf("\nA fila esta cheia!");
    }else{
        printf("\nA fila nao esta cheia.");
    }

    x = insere_fila(fi, al1);
    if(x){
        printf("\nElemento inserido com sucesso!");
    }else{
        printf("\nErro, elemento nao inserido.");
    }
    x = insere_fila(fi, al2);
    if(x){
        printf("\nElemento inserido com sucesso!");
    }else{
        printf("\nErro, elemento nao inserido.");
    }
    x = insere_fila(fi, al3);
    if(x){
        printf("\nElemento inserido com sucesso!");
    }else{
        printf("\nErro, elemento nao inserido.");
    }

    destroi_fila(fi);
}
