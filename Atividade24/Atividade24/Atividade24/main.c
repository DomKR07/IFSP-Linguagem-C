#include <stdio.h>
#include <stdlib.h>
#include "PTcart.h"

int main() {
    float d = 0, retornax, retornaY;  // Correção: a variável retornaX foi corrigida para retornax
    PTcart *p = NULL, *q = NULL;

    p = criaPTcart(10, 21);
    q = criaPTcart(7, 25);
    d = distanciaPTcart(p, q);

    printf("Distancia entre os pontos cartesianos: %f\n", d);
    atribuiPTcart(q, 15, -2);
    d = distanciaPTcart(p, q);

    printf("Nova distancia entre os pontos cartesianos: %f\n", d);
    acessaPTcart(p, &retornax, &retornaY);
    printf("Valores armazenados em p: X = %.2f e Y = %.2f\n", retornax, retornaY);
    acessaPTcart(q, &retornax, &retornaY);
    printf("Valores armazenados em q: X = %.2f e Y = %.2f\n", retornax, retornaY);  // Correção: retornaX foi corrigida para retornax
    liberaPTcart(p);
    liberaPTcart(q);
    system("PAUSE");
    return 0;
}
