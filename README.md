# Árvore de Busca Binária para Cidades

Este código implementa uma árvore binária de busca (ABB) para armazenar informações de cidades, como nome, área e população. A árvore é organizada com base na população das cidades, permitindo uma pesquisa e listagem das cidades por ordem crescente de população.

## Funcionalidades

1. **Criação de Nós:**
   - A função `criarNo()` cria um novo nó na árvore com informações de uma cidade: nome, área e população.

2. **Inserção na Árvore:**
   - A função `inserir()` insere um novo nó na árvore. A inserção é feita de forma que os nós com menor população ficam à esquerda e os nós com maior população à direita, mantendo a propriedade da árvore binária de busca.

3. **Altura da Árvore:**
   - A função `altura()` calcula a altura de um nó na árvore, o que é usado para balanceamento e para determinar a profundidade da árvore.

4. **Percurso em Ordem:**
   - A função `EmOrdem()` realiza um percurso in-order na árvore, ou seja, visita os nós da esquerda para a direita, e imprime as informações das cidades na ordem crescente de população.

5. **Listagem das Cidades:**
   - A função `listar()` exibe as cidades ordenadas pela população, de forma crescente, utilizando o percurso em ordem.

## Estrutura de Dados

A estrutura de dados usada é um nó (`No`) com a seguinte definição:

```c
typedef struct cidade {
    char nome[100];  // Nome da cidade
    float area;      // Área da cidade em km²
    int populacao;   // População da cidade
} Cidade;

typedef struct no {
    Cidade cidade;   // Informações da cidade
    struct no* esq;  // Ponteiro para o nó à esquerda
    struct no* dir;  // Ponteiro para o nó à direita
    int altura;      // Altura do nó (usada para balanceamento)
} No;
