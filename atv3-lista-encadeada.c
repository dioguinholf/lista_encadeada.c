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