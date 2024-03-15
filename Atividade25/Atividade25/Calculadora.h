#ifndef CALCULADORA_H
#define CALCULADORA_H

typedef struct Calculadora Calculadora;

Calculadora* criarCalculadora();
void destruirCalculadora(Calculadora *calc);

void soma(Calculadora *calc, float valor);
void subtracao(Calculadora *calc, float valor);
void multiplicacao(Calculadora *calc, float valor);
void divisao(Calculadora *calc, float valor);

float obterResultado(Calculadora *calc);

#endif

