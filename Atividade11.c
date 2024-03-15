#include <stdio.h>

int main() {

    char str[10];

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }

    printf("String em maiúsculas: %s", str);

    return 0;
}

