/******************************************************************
arvorebinaria.h
Cabecalhos das funcoes implementadas no modulo arvorebinaria.c,
que servem para realizar diversas operacoes da arvore.
******************************************************************/

typedef struct produto Produto;

Produto* init();

Produto* busca (Produto* r, int m);

Produto* insere (Produto* a, int m, int t, float p);

Produto* retira (Produto* r, int m);

Produto* libera (Produto* a);

void imprime (Produto* a);

