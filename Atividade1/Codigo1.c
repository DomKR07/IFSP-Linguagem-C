
#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b;

    printf("informe dois numeros: \n"); scanf("%d %d", &a, &b);
    if (a==b) {
        printf("Os numeros sao iguais \n\n\n");
    }else{
        printf("os numeros sao diferentes \n\n\n");
    }
    system("pause");
    return 0;
}
