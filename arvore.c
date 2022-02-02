//
// Created by rhuan on 01/02/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

typedef struct arvore{
    int info;
    struct arvore *esq;
    struct arvore *dir;
}Arvore;

Arvore* criaArvore() {
    return NULL;
}

int arvoreVazia(Arvore* t) {
    /* Retorna 1 se a árvore for vazia e 0 caso contrário */
    return t == NULL;
}

void insere(Arvore **a, int x){
    if ((*a)== NULL){
        *a = (Arvore*)malloc(sizeof(Arvore));
        (*a)->info= x;
        (*a)->esq= NULL;
        (*a)->dir= NULL;
    }
    else
    if(x< (*a)->info)
        insere(&((*a)->esq),x);
    else
        insere(&((*a)->dir),x);
}

Arvore* busca(Arvore **a, int x){
    if ((*a) == NULL)
        return NULL;
    else
    if (x==(*a)->info)
        return (*a);
    else
    if (x< (*a)->info)
        return (busca(&((*a)->esq),x));
    else
        return (busca(&((*a)->dir),x));
}

Arvore* maior(Arvore **a){
    Arvore *t;
    t = *a;
    if (t->dir == NULL){
        *a = (*a)->esq;
        return (t);
    } else
        return (maior(&((*a)->dir)));
}

int removei(Arvore **a, int x){
    Arvore *p;
    if (*a==NULL){
        return 1; //elemento não encontrado
    }
    if ((x==(*a)->info)==1) //elemento encontrado na raiz
    {
        p=*a;
        if ((*a)->esq == NULL) //raiz não tem filho esquerdo
            *a = (*a)->dir;
        else
        if ((*a)->dir== NULL) //raiz não tem filho direito
            *a=(*a)->esq;
        else{ //raiz tem ambos os filhos
            p=maior(&((*a)->esq));
            (*a)->info = p->info;
        }
        free(p);
    }
    else{
        if ((x <(*a)->info)==1)
            removei(&((*a)->esq),x); //procura na subarvore da esquerda
        else
            removei(&((*a)->dir),x); //procura na subarvore da direita
    }
}

void emOrdem(Arvore *t){
    if (!arvoreVazia(t)){
        emOrdem(t->esq);
        printf(" %d, ",t->info); //visita raiz
        emOrdem(t->dir);
    }
}

void preOrdem(Arvore *t){
    if (!arvoreVazia(t)){
        printf(" %d, ",t->info); //visita raiz
        preOrdem(t->esq); //visita subarvore da esquerda
        preOrdem(t->dir); //visita subarvore da direita
    }
}

void posOrdem(Arvore *t){
    if (!arvoreVazia(t)){
        posOrdem(t->esq);
        posOrdem(t->dir);
        printf(" %d, ",t->info); //visita raiz
    }
}

int altura(Arvore *a){
    int hdir, hesq;
    if (arvoreVazia(a))
        return -1;
    hesq = altura(a->esq);
    hdir = altura(a->dir);
    return 1 + (hesq > hdir ? hesq:hdir);
}

int contaFolhas (Arvore *a){
    int conta;
    if (arvoreVazia(a)){
        return -1;
    }
    conta = contaFolhas(a->esq);
    conta = contaFolhas(a->dir);
    return conta + 1;
}

//1
int contaNosT(Arvore *a) {
    if (arvoreVazia(a)){
        return 0;
    }
    if( a->esq==NULL && a->dir==NULL){
        return contaNosT(a->esq) + contaNosT(a->dir);
    }
    return contaNosT(a->esq) + contaNosT(a->dir) + 1;
}

//2
int somaNos(Arvore *a) {
    int soma=0;
    if (arvoreVazia(a))
        return 0;

    return soma = a->info + somaNos(a->esq) + somaNos(a->dir);
}

//3
int menorValor(Arvore *a) {
    if(arvoreVazia(a))
        return 0;

    if(a->esq == NULL)
        return a->info;
    return menorValor(a->esq);
}

//4
int imprimirNivel(Arvore *a, int nivelEscolhido, int nivelInicial) {
    if(arvoreVazia(a))
        return -1;

    if(nivelEscolhido == nivelInicial){
        printf("%d ", a->info);
        return 1;
    }

    nivelInicial++;

    if(a->esq != NULL)
        imprimirNivel(a->esq, nivelEscolhido, nivelInicial);
    if(a->dir != NULL)
        imprimirNivel(a->dir, nivelEscolhido, nivelInicial);
}

//5
int dobraArvore(Arvore *a, int x) {
    //chave par
    if(x % 2 == 0){
        insere(&a, x+1);
        insere(&a, x);
    }

    //chave impar
    if(x % 2 == 1){
        insere(&a, x-1);
        insere(&a, x);
    }
}

int lista(Arvore *a, int vet[]) {

}
