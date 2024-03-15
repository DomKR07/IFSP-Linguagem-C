
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10;
    int vetDesordenado[10] = {120, 150, 110, 130, 100, 160, 140, 190, 180, 170};
    int vetOrdenado[10] = {100, 110, 120, 130, 140, 150, 160, 170, 180, 190};
    int elem1 = 100;
    int elem2 = 170;
    int elem3 = 130;


    printf("Vetor: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", vetDesordenado[i]);
        }

    printf("\n\n");

    printf("Elemento a ser procurado por busca linear: %d ", elem1);

    printf("\n\n");

    int buscaLinear(int *vetDesordenado,int n, int elem1){
        for(int i = 0; i < 10; i++){
            if (elem1 == vetDesordenado[i]){
                return i;
            }
        }
        return -1;
    }

    int posicao1 = buscaLinear(vetDesordenado, 10, elem1);
    printf("A posicao do elemento no vetor e: %d", posicao1);

    printf("\n\n");

     printf("Vetor Ordenado: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", vetOrdenado[i]);
        }

    printf("\n\n");

    printf("Elemento a ser procurado por busca linear: %d ", elem2);

    printf("\n\n");

    int buscaOrdenada(int *vetOrdenado,int n, int elem2){
        for(int i = 0; i < 10; i++){
            if (elem2 == vetOrdenado[i]){
                return i;
            }else{
                if(elem2 < vetOrdenado[i]){
                    return -1;
                }
            }
        }
        return -1;
    }

    int posicao2 = buscaOrdenada(vetOrdenado, 10, elem2);
    printf("A posicao do elemento no vetor e: %d", posicao2);

    printf("\n\n");

    printf("Elemento a ser procurado por busca linear: %d ", elem3);

    printf("\n\n");

    int buscaBinaria(int *vetOrdenado,int n, int elem3){
        int inicio, meio, fim;
        inicio = 0;
        fim = n -1;

        while (inicio<=fim){
            meio = (inicio + fim)/2;
            printf("inicio: %d    fim: %d \n\n", inicio, fim);

            if(elem3 < vetOrdenado[meio]){
                fim = meio - 1;
            }else{
               if(elem3 > vetOrdenado[meio]){
                inicio = meio + 1;
               }else{
                    return meio;
               }
            }
        }
        return -1;
    }

    int posicao3 = buscaBinaria(vetOrdenado, 10, elem3);
    printf("A posicao do elemento no vetor e: %d", posicao3);

    return 0;
}
