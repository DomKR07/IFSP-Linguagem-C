#include <stdio.h>

int main() {

    int var1, var2;

    printf("Digite o valor para a variável 1: ");
    scanf("%d", &var1);

    printf("Digite o valor para a variável 2: ");
    scanf("%d", &var2);

    int *ptr1 = &var1;
    int *ptr2 = &var2;

    if (ptr1 > ptr2) {
        printf("\nMaior endereço: %p\n", ptr1);
        printf("Conteúdo da variável apontada: %d\n", *ptr1);
    } else if (ptr2 > ptr1) {
        printf("\nMaior endereço: %p\n", ptr2);
        printf("Conteúdo da variável apontada: %d\n", *ptr2);
    } else {
        printf("\nOs endereços são iguais.\n");
    }

    return 0;
}
