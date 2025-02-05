#ifndef CIDADE_H
#define CIDADE_H

typedef struct sMun{
    char nome[100];
    float area;
    int populacao;
}Municipio;

typedef struct sno{
    Municipio cidade;
    struct sno *esq;
    struct sno *dir;
    int altura; 
}No;


#endif