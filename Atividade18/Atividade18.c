#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

int main() {
    // Configurar a localização para a língua portuguesa
    setlocale(LC_ALL, "Portuguese");

    // Abrir arquivo "arq1.txt" para escrita
    FILE *arq1 = fopen("arq1.txt", "w");

    if (arq1 == NULL) {
        printf("Erro ao abrir o arquivo arq1.txt\n");
        return 1;
    }

    // Receber o texto do usuário
    char texto[1000];
    printf("Digite um pequeno texto: ");
    fgets(texto, sizeof(texto), stdin);

    // Salvar o texto no arquivo arq1.txt
    fprintf(arq1, "%s", texto);

    // Fechar o arquivo arq1.txt
    fclose(arq1);

    // Abrir arquivo "arq2.txt" para escrita
    FILE *arq2 = fopen("arq2.txt", "w");

    if (arq2 == NULL) {
        printf("Erro ao abrir o arquivo arq2.txt\n");
        return 1;
    }

    // Converter o texto para maiúsculas e salvar no arquivo arq2.txt
    for (int i = 0; texto[i] != '\0'; i++) {
        texto[i] = toupper(texto[i]);
    }

    fprintf(arq2, "%s", texto);

    // Fechar o arquivo arq2.txt
    fclose(arq2);

    // Imprimir os dois arquivos em tela
    printf("Conteúdo do arquivo arq1.txt:\n");
    arq1 = fopen("arq1.txt", "r");
    if (arq1 != NULL) {
        char c;
        while ((c = fgetc(arq1)) != EOF) {
            putchar(c);
        }
        fclose(arq1);
    } else {
        printf("Erro ao abrir o arquivo arq1.txt\n");
    }

    printf("\nConteúdo do arquivo arq2.txt:\n");
    arq2 = fopen("arq2.txt", "r");
    if (arq2 != NULL) {
        char c;
        while ((c = fgetc(arq2)) != EOF) {
            putchar(c);
        }
        fclose(arq2);
    } else {
        printf("Erro ao abrir o arquivo arq2.txt\n");
    }

    return 0;
}
