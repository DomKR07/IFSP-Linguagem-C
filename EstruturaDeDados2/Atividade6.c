#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetDesordenado[10] = {120, 150, 110, 130, 100, 160, 140, 190, 180, 170};

    printf("Vetor desordenado: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", vetDesordenado[i]);
        }

    printf("\n\n");

    printf("Ordenando por insertionSort: ");

    Ordena_insertionSort(&vetDesordenado);

    printf("\n\n");

    printf("Vetor ja ordenado: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", vetDesordenado[i]);
        }
        return 0;
}

void Ordena_insertionSort(int vetDesordenado[]){
    int i, j, aux;
    for(i = 1; i < 10; i++){
        aux = vetDesordenado[i];
        for(j = i; (j > 0) && (aux < vetDesordenado[j-1]); j--){
        vetDesordenado[j] = vetDesordenado[j-1];
        }
        vetDesordenado[j] = aux;
    }
}

