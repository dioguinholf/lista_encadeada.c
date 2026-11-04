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

// 6. Inserir um elemento na lista, dada a sua posição
int inserir(tlista *L, int pos, telem valor) {
    tlista p, novo;
    int n;

    /* Inserção em lista vazia */
    if (*L == NULL) {
        if (pos != 1) return 0; /* erro: posição inválida */
        novo = (tlista) malloc(sizeof(tno));
        if (novo == NULL) return 0; /* erro: memória insuficiente */
        novo->dado = valor;
        novo->prox = NULL;
        *L = novo;
        return 1;
    }

    /* Inserção na primeira posição em lista não vazia */
    if (pos == 1) {
        novo = (tlista) malloc(sizeof(tno));
        if (novo == NULL) return 0; /* erro: memória insuficiente */
        novo->dado = valor;
        novo->prox = *L;
        *L = novo;
        return 1;
    }

/* Inserção após a primeira posição em lista não vazia */
    p = *L;
    n = 1;
    while ((n < pos - 1) && (p != NULL)) {
        p = p->prox;
        n++;
    }

    if (p == NULL) return 0; /* erro: posição inválida */
    novo = (tlista) malloc(sizeof(tno));
    if (novo == NULL) return 0; /* erro: memória insuficiente */
    novo->dado = valor;
    novo->prox = p->prox;
    p->prox = novo;
    return 1;
}

// 7. Remover um elemento de uma determinada posição
int remover(tlista *L, int pos, telem *elem) {
    tlista a = NULL, p;
    int n;

    if (vazia(*L)) return 0; /* erro: lista vazia */

    p = *L;
    n = 1;

    // Navega até a posição desejada guardando o nó anterior (a)
    while ((n < pos) && (p != NULL)) {
        a = p;
        p = p->prox;
        n++;
    }

    if (p == NULL) return 0; /* erro: posição inválida */

    *elem = p->dado;

    if (pos == 1) {
        *L = p->prox;
    } else {
        a->prox = p->prox;
    }

    free(p);
    return 1;
}

// Exibe todos os elementos da lista
void exibirLista(tlista L) {
    if (vazia(L)) {
        printf("\nLista Vazia!\n");
        return;
    }

    tlista p = L;
    printf("\nConteúdo da Lista: [ ");
    while (p != NULL) {
        printf("%d ", p->dado);
        p = p->prox;
    }
    printf("]\n");
}

// Esvazia completamente a lista encadeada
void esvaziar(tlista *L) {
    tlista p = *L;
    tlista temp;

    while (p != NULL) {
        temp = p->prox;
        free(p);
        p = temp;
    }

    *L = NULL;
    printf("\nLista esvaziada com sucesso!\n");
}

int main() {
    tlista L;
    criar(&L); // a) crie uma lista L

    int opcao = 0;
    int pos, ok;
    telem valor;