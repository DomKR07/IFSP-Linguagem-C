#include <stdio.h>
#include <ctype.h>
#include <string.h>

void inversor(char *str) {
    while (*str) {
        if (islower(*str)) {
            *str = toupper(*str);
        } else if (isupper(*str)) {
            *str = tolower(*str);
        }
        str++;
    }
}

void strupr(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

void strlwr(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int main() {
    char string[30];

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);
    input[strcspn(string, "\n")] = '\0';

    inversor(string);
    printf("Invertendo a caixa dos caracteres: %s\n", string);

    char copia[100];
    strcpy(copia, string);
    strupr(copia);
    printf("Tornando todos os caracteres maiúsculos: %s\n", copia);

    strcpy(copia, string);
    strlwr(copia);
    printf("Tornando todos os caracteres minúsculos: %s\n", copia);

    return 0;
}
