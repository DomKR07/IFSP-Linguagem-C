#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetDesordenado[10] = {120, 150, 110, 130, 100, 160, 140, 190, 180, 170};

    printf("Vetor desordenado: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", vetDesordenado[i]);
        }

    printf("\n\n");

    printf("Ordenando por bubbleSortOscilante - CocktailSort: ");

    Ordena_bubbleSortOscil(&vetDesordenado);

    printf("\n\n");

    printf("Vetor ja ordenado: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", vetDesordenado[i]);
        }
        return 0;
}

void Ordena_bubbleSortOscil(int vetDesordenado[]){
    int i, continua, aux, fim = 10;
    do{
        continua = 0;
        for(i = 0; i <= fim - 1; i++){
            if(vetDesordenado[i] < vetDesordenado[i-1]){
                aux = vetDesordenado[i];
                vetDesordenado[i] = vetDesordenado[i-1];
                vetDesordenado[i-1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
}
