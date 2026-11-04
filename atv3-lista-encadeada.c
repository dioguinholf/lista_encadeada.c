#include <stdio.h>
#include <stdlib.h>

// Definição dos tipos de dados
typedef int telem; /* tipo base da lista */

typedef struct no {
    telem dado;        /* campo da informação */
    struct no* prox;   /* campo do ponteiro para o próximo nó */
} tno;                 /* tipo do nó */

typedef tno* tlista;   /* tipo lista */

// 1. Criação da lista vazia
void criar(tlista *L) {
    *L = NULL;
}

//2. Verificação se a lista está vazia
int vazia(tlista L) {
    return (L == NULL);
}

// 3. Obter o tamanho da lista
int tamanho(tlista L) {
    tlista p = L;
    int n = 0;
    while (p != NULL) {
        p = p->prox;
        n++;
    }
    return n;
}

// 4. Obter o valor do elemento de uma posição dada
int elemento(tlista L, int pos, telem *elem) {
    tlista p = L;
    int n = 1;
    if (L == NULL) return 0; /* erro: lista vazia */

    while ((p != NULL) && (n < pos)) {
        p = p->prox;
        n++;
    }
    if (p == NULL) return 0; /* erro: posição inválida */

    *elem = p->dado;
    return 1;
}

// 5. Obter a posição de elemento cujo valor é dado
int posicao(tlista L, telem valor) {
    if (L != NULL) {
        tlista p = L;
        int n = 1;
        while (p != NULL) {
            if (p->dado == valor) return n;
            p = p->prox;
            n++;
        }
    }
    return 0;
}