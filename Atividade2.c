
#include <stdio.h>
#include <stdlib.h>

int main() {

    char n;

    printf("Digite um numero: \n");
    scanf("%c", &n);
    switch (n) {
        case '1':
            printf("A");
        break;
        case '2':
            printf("B");
        break;
        case '3':
            printf("C");
        break;
        case '4':
            printf("D");
        break;
        default:
            printf("0");
        break;
        }
    printf("\n\n\n"); system("pause");
    return 0;
}
