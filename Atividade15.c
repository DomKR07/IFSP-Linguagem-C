#include <stdio.h>

void trocaValor(int *ptr1, int *ptr2, int *ptr3) {
    *ptr1 += 100;
    *ptr2 += 100;
    *ptr3 += 100;
}

int main() {

    int var1, var2, var3;
    int *ptr1, *ptr2, *ptr3;

    printf("Digite o valor para a vari�vel 1: ");
    scanf("%d", &var1);

    printf("Digite o valor para a vari�vel 2: ");
    scanf("%d", &var2);

    printf("Digite o valor para a vari�vel 3: ");
    scanf("%d", &var3);

    ptr1 = &var1;
    ptr2 = &var2;
    ptr3 = &var3;

    trocaValor(ptr1, ptr2, ptr3);

    printf("\nValor final da vari�vel 1: %d\n", var1);
    printf("Valor final da vari�vel 2: %d\n", var2);
    printf("Valor final da vari�vel 3: %d\n", var3);

    return 0;
}
