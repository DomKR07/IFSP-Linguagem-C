#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char consoante;
    int vogal = 0;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vogal++;
        }
    }

    printf("Digite uma consoante para substituir as vogais: ");
    scanf(" %c", &consoante);

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            str[i] = consoante;
        }
    }

    printf("Nova string com as vogais substituidas: %s", str);

    printf("Total de vogais na string original: %d\n", vogal);

    return 0;
}
