// hashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

struct aluno {
    int matricula;
    char nome[31];
    float n1, n2, n3;
};

typedef struct hash Hash;

Hash *criaHash(int TABLE_SIZE);
void liberaHash(Hash *ha);
void redimensionaTabela(Hash *ha, int novoTamanho);
int insereHash_semColisao(Hash *ha, struct aluno al);
int buscaHash_semColisao(Hash *ha, int mat, struct aluno *al);
int insereHash_enderecoAberto(Hash *ha, struct aluno al);
int buscaHash_enderecoAberto(Hash *ha, int mat, struct aluno *al);

#endif
