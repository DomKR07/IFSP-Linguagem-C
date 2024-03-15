#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario{
int id;
char nome[30];
int idade;
float salario;
};

int main(){
    int i, n = 5;
    struct funcionario f[n];

    for(i = 0; i < n; i++){
        printf("Digite o ID do funcionario %d: ", i + 1);
        scanf("%d", &f[i].id);
        printf("Digite o nome do funcionario %d: ", i + 1);
        scanf("%s", &f[i].nome);
        printf("Digite a idade do funcionario %d: ", i + 1);
        scanf("%d", &f[i].idade);
        printf("Digite o salario do funcionario %d: ", i + 1);
        scanf("%f", &f[i].salario);
        printf("\n\n\n");
    }
    for(i = 0; i < n; i++){
        printf("Dados da pessoa %d\n", i + 1);
        printf("ID......:%d\n", f[i].id);
        printf("Nome....:%s\n", f[i].nome);
        printf("Idade...:%d\n", f[i].idade);
        printf("Salario.:%.2f\n\n\n", f[i].salario);
    }

    system("pause");
}

