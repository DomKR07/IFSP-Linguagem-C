#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"

int main(){
    Lista *li;//ponteiro para ponteiro
               //que está no arquivo
               //listaLigada.h
    li = criaLista();
    //código e erro;
    int x = 0;
    //para as buscas
    int matricula = 130, posicao =2;
    //para popular a lista e al para consulta
    ALUNO al1, al2, al3, al;

    al1.matricula = 110;
    al1.n1 = 5.6;
    al1.n2 = 6.3;
    al1.n3 = 7.9;
    al2.matricula = 130;
    al2.n1 = 9.2;
    al2.n2 = 3.5;
    al2.n3 = 8.1;
    al3.matricula = 120;
    al3.n1 = 6.6;
    al3.n2 = 2.1;
    al3.n3 = 9.2;

    x = tamLista(li);
    printf("\nO tamanho da lista e: %d", x);

    if(listaVazia(li)){
        printf("\nLista esta vazia!");
    }else{
        printf("\nLista nao esta vazia.");
    }

    x = insere_inicio_lista(li, al1);
    if(x){
        printf("\nInserido no inicio com sucesso!");
    }else{
        printf("\nNao foi possivel inserir no inicio.");
    }

    if(listaVazia(li)){
        printf("\nLista esta vazia!");
    }else{
        printf("\nLista nao esta vazia.");
    }

    x = insere_final_lista(li, al2);
    if(x){
        printf("\nInserido no final com sucesso!");
    }else{
        printf("\nNao foi possivel inserir no final.");
    }

    x = insere_lista_ordenada(li, al3);
    if(x){
        printf("\nInserido ordenadamente com sucesso!");
    }else{
        printf("\nNao foi possivel inserir ordenadamente.");
    }

    x = tamLista(li);
    printf("\n\nO tamanho da lista e: %d", x);

    x = consulta_lista_pos(li, posicao, &al);
    if(x){
        printf("\n\nConteudo na posicao %d:", posicao);
        printf("\n%d", al.matricula);
        printf("\n%.2f", al.n1);
        printf("\n%.2f", al.n2);
        printf("\n%.2f", al.n3);
    }else{
        printf("\nElemento %d nao encontrado.", posicao);
    }

    x = consulta_lista_mat(li, matricula, &al);
    if(x){
        printf("\n\nConteudo da matricula %d:", matricula);
        printf("\n%d", al.matricula);
        printf("\n%.2f", al.n1);
        printf("\n%.2f", al.n2);
        printf("\n%.2f", al.n3);
    }else{
        printf("\nMatricula %d nao encontrado.", matricula);
    }

    Lista *lista = criaLista();
    int opcao;
    ALUNO aluno;

    do {
    printf("\n\nMenu:\n");
    printf("1. Incluir um elemento de forma ordenada\n");
    printf("2. Buscar um elemento por conteudo (matricula)\n");
    printf("3. Excluir um elemento de forma ordenada\n");
    printf("4. Encerrar o programa\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            printf("\n");
            coletadados(&al);
            if (insere_lista_ordenada(li, al)) {
                printf("Aluno inserido com sucesso!\n");
            } else {
                printf("Erro ao inserir aluno.\n");
            }
            break;
        case 2:
            printf("\nDigite a matricula a ser buscada: ");
            scanf("%d", &matricula);
            if (consulta_lista_mat(li, matricula, &al)){
                imprimeAluno(al);
            } else {
                printf("\nMatricula nao encontrada.");
            }
            break;
        case 3:
            printf("\nDigite a matricula a ser removida: ");
            scanf("%d", &matricula);
            if (remove_lista(li, matricula)){
                printf("\nRemovido com sucesso!");
            } else {
                printf("\nMatricula nao encontrada ou lista vazia.");
            }
            break;
        case 4:
            printf("\nEncerrando o programa.\n");
            break;
        default:
            printf("\nOpcao invalida. Tente novamente.");
        }
    } while (opcao != 4);


    x = remove_inicio_lista(li);
    if(x){
        printf("\nRemovido do inicio com sucesso!");
    }else{
        printf("\nNao foi possivel remover do inicio");
    }

    x = remove_lista(li, matricula);
    if(x){
        printf("\nRemovido elemento com sucesso!");
    }else{
        printf("\nNao foi possivel remover elemento.");
    }

    x = remove_final_lista(li);
    if(x){
        printf("\nRemovido do final com sucesso!");
    }else{
        printf("\nNao foi possivel remover do final.");
    }

    apagaLista(li);
}
