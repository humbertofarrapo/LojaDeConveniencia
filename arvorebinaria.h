
typedef struct Produto* ArvBin;

void

ArvBin* criaArvBin();

void liberaArvBin(ArvBin *raiz);

int insereArvBin(ArvBin* raiz, int valor);

int removeArvBin(ArvBin *raiz, int valor);

int estaVaziaArvBin(ArvBin *raiz);

int consultaArvBin(ArvBin *raiz, int valor);

void emOrdemArvBin(ArvBin *raiz);

/*	
falta as funções de:
		funcão de alteração 
		função de venda
		função de relatorio por tipo
		função de relatorio de vendas
/*
