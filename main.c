#include <stdio.h>
#include "arvore.h"

int main() {
    Arvore *a = criaArvore();

    insere(&a, 50);
    insere(&a, 35);
    insere(&a, 83);
    insere(&a, 18);
    insere(&a, 38);
    insere(&a, 60);
    insere(&a, 95);
    insere(&a, 15);
    insere(&a, 17);
    insere(&a, 40);
    insere(&a, 55);
    insere(&a, 52);

    int nivel = 3;
    printf("Numero de nos na arvore: %d\n", contaNosNT(a));
    printf("Soma dos valores dos nos: %d\n", somaNos(a));
    printf("Menor valor registrado: %d\n", menorValor(a));
    printf("Valores no nivel %d: \n", nivel);
    imprimirNivel(a, nivel, 0);
    printf("\n");
    emOrdem(a);
    dobraArvore(a);
    printf("\n");
    emOrdem(a);
    return 0;
}
