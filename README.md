# Editor de Listas — Lista Encadeada em C

Atividade da **Aula 3 — Algoritmos e Estrutura de Dados (A Lista Encadeada)**, desenvolvida em linguagem C.

## Descrição

Programa de terminal que cria uma lista encadeada dinâmica de inteiros (`L`) e exibe um menu interativo, o **Editor de Listas**, para manipulá-la. A implementação segue a estrutura apresentada nos slides: nós alocados com `malloc`, ligados por ponteiros (`prox`) e terminados em `NULL`.

## Estrutura de dados

```c
typedef int telem;               /* tipo base da lista */

typedef struct no {
    telem dado;                  /* informação */
    struct no *prox;             /* ponteiro para o próximo nó */
} tno;

typedef tno *tlista;             /* tipo lista */
```

## Operações implementadas

| Função | Descrição |
|---|---|
| `criar(&L)` | Cria a lista vazia |
| `vazia(L)` | Verifica se a lista está vazia |
| `tamanho(L)` | Retorna a quantidade de elementos |
| `elemento(L, pos, &e)` | Obtém o valor de uma posição |
| `posicao(L, valor)` | Obtém a posição de um valor (0 se não encontrado) |
| `inserir(&L, pos, valor)` | Insere um elemento em uma posição |
| `remover(&L, pos, &e)` | Remove o elemento de uma posição |
| `esvaziar(&L)` | Remove todos os nós, liberando a memória |
| `exibir(L)` | Imprime a lista no formato `a -> b -> c -> NULL` |

## Menu

```
        EDITOR DE LISTAS

   1 - EXIBIR LISTA
   2 - INSERIR
   3 - REMOVER
   4 - EXIBIR ELEMENTO
   5 - EXIBIR POSICAO
   6 - ESVAZIAR
 ESC - SAIR (digite ESC, 0 ou S)

DIGITE SUA OPCAO:
```

## Como compilar e executar

Requer um compilador C (por exemplo, GCC).

```bash
gcc lista_encadeada.c -o lista_encadeada
./lista_encadeada
```

No Windows (MinGW):

```bash
gcc lista_encadeada.c -o lista_encadeada.exe
lista_encadeada.exe
```

## Exemplo de uso

```
DIGITE SUA OPCAO: 2
Posicao: 1
Valor: 10
Elemento 10 inserido na posicao 1.

DIGITE SUA OPCAO: 2
Posicao: 2
Valor: 20
Elemento 20 inserido na posicao 2.

DIGITE SUA OPCAO: 1
L = 10 -> 20 -> NULL   (tamanho: 2)
```

## Observações

- Posições começam em **1**, como nos slides.
- Foi usado `<stdlib.h>` no lugar de `<alloc.h>` (obsoleta em compiladores modernos).
- Posições inválidas, lista vazia e entradas não numéricas são tratadas com mensagens de erro.
- Para sair, o programa aceita `ESC`, `0` ou `S`, pois a tecla ESC pura depende do terminal.
- A memória da lista é liberada ao sair do programa.

## Autor

Diogo — Bacharelado em Sistemas de Informação, UFRPE