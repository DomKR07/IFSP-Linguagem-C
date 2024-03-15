#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetDesordenado[10] = {120, 150, 110, 130, 100, 160, 140, 190, 180, 170};

    printf("Vetor desordenado: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", vetDesordenado[i]);
        }

    printf("\n\n");

    printf("Ordenando por selectionSort: ");

    Ordena_selectionSort(&vetDesordenado);

    printf("\n\n");

    printf("Vetor ja ordenado: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", vetDesordenado[i]);
        }
        return 0;
}

void Ordena_selectionSort(int vetDesordenado[]){
    int i, j, menor, troca;
    for(i = 0; i < 9; i++){
        menor = i;
        for(j = i + 1; j < 10; j++){
            if (vetDesordenado[j] < vetDesordenado[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = vetDesordenado[i];
            vetDesordenado[i] = vetDesordenado[menor];
            vetDesordenado[menor] = troca;
        }
    }
}

