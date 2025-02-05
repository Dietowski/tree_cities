#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidade.h"

No  *criarNo(char name[], float area, int pop){
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL){
        printf("Erro na memoria\n");
        return NULL;
    }
    strcpy(novo_no->cidade.nome, name);
    novo_no->cidade.area = area;
    novo_no->cidade.populacao = pop;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    novo_no->altura = 1;
    return novo_no;
}
int max(int a, int b){
    return (a > b) ? a : b;
}

int altura(No *raiz){
    if (raiz == NULL){
        return 0;
    }
    return raiz->altura;
}

No  *inserir(No *raiz, char nome[], float area, int pop){
    if (raiz == NULL){
        return criarNo(nome, area, pop);
    }
    if (pop < raiz->cidade.populacao){
        raiz->esq = inserir(raiz->esq, nome, area, pop);
    } else if (pop > raiz->cidade.populacao){
        raiz->dir = inserir(raiz->dir, nome, area, pop);
    }
    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));
    return raiz;
}

void EmOrdem(No* raiz){
    if (raiz != NULL){
        EmOrdem(raiz->esq);
        printf("Nome: %s Area: %.2f km Populacao: %d\n", raiz->cidade.nome, raiz->cidade.area, raiz->cidade.populacao);
        EmOrdem(raiz->dir);
    }
}

void listar(No* raiz){
    printf("Impressao das cidades por populacao (Ordem Crescente):\n");
    EmOrdem(raiz);
}

int main(){
    No* raiz = NULL;

    raiz = inserir(raiz, "Patos de Minas",3.190,159600);
    raiz = inserir(raiz, "Rio Paranaiba",1.352,14532);
    raiz = inserir(raiz, "Carmo do Paranaiba",1.307,35334);

    listar(raiz);

    return 0;
}
