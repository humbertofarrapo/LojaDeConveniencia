/******************************************************************
arvorebinaria.h
Cabecalhos das funcoes implementadas no modulo arvorebinaria.c,
que servem para realizar diversas operacoes da arvore.
******************************************************************/

typedef struct produto Produto;

Produto* init(); //Inicia a arvore;

Produto* busca (Produto* r, int m); //Realiza a operacao de busca em uma arvore;

Produto* insere (Produto* a, int m, int t, float p); //Realiza a operacao de insercao em uma arvore;

Produto* retira (Produto* r, int m); //Realiza a operacao de remocao em uma arvore;

Produto* libera (Produto* a); //Realiza a operacao de liberacao de uma arvore (no por no);

void imprime (Produto* a); //Realiza a operacao de impressao de uma arvore.
