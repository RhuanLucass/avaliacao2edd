//
// Created by rhuan on 01/02/2022.
//

#ifndef PROVA_2_ARVORE_H
#define PROVA_2_ARVORE_H

typedef struct arvore Arvore;
Arvore* criaArvore();
int arvoreVazia(Arvore* t);
void insere(Arvore **a, int x);
Arvore* busca(Arvore **a, int x);
Arvore* maior(Arvore **a);
int removei(Arvore **a, int x);
void emOrdem(Arvore *t);
void preOrdem(Arvore *t);
void posOrdem(Arvore *t);
int altura(Arvore *a);

int contaNosT(Arvore *a);
int contaFolhas (Arvore *a);
int somaNos(Arvore *a);
int menorValor(Arvore *a);
int imprimirNivel(Arvore *a, int nivelEscolhido, int nivelInicial);
int dobraArvore(Arvore *a, int x);
int lista(Arvore *a, int vet[]);

#endif //PROVA_2_ARVORE_H
