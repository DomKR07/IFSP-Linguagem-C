#include <stdio.h>

int main() {

    int var1, var2;

    printf("Digite o valor para a vari�vel 1: ");
    scanf("%d", &var1);

    printf("Digite o valor para a vari�vel 2: ");
    scanf("%d", &var2);

    int *ptr1 = &var1;
    int *ptr2 = &var2;

    if (ptr1 > ptr2) {
        printf("\nMaior endere�o: %p\n", ptr1);
        printf("Conte�do da vari�vel apontada: %d\n", *ptr1);
    } else if (ptr2 > ptr1) {
        printf("\nMaior endere�o: %p\n", ptr2);
        printf("Conte�do da vari�vel apontada: %d\n", *ptr2);
    } else {
        printf("\nOs endere�os s�o iguais.\n");
    }

    return 0;
}
