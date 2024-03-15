#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"

struct Calculadora {
    float resultado;
};

Calculadora* criarCalculadora() {
    Calculadora *calc = (Calculadora*)malloc(sizeof(Calculadora));
    if (calc != NULL) {
        calc->resultado = 0.0;
    }
    return calc;
}

void destruirCalculadora(Calculadora *calc) {
    free(calc);
}

void soma(Calculadora *calc, float valor) {
    calc->resultado += valor;
}

void subtracao(Calculadora *calc, float valor) {
    calc->resultado -= valor;
}

void multiplicacao(Calculadora *calc, float valor) {
    calc->resultado *= valor;
}

void divisao(Calculadora *calc, float valor) {
    if (valor != 0.0) {
        calc->resultado /= valor;
    } else {
        printf("Erro: Divisão por zero.\n");
    }
}

float obterResultado(Calculadora *calc) {
    return calc->resultado;
}

