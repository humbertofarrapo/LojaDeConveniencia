#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"

struct Produto
{
    	int matricula;
	int tipo;
	float preco;
   	struct Produto *esq;
    	struct Produto *dir;
};

ArvBin* criaArvBin()
{
	ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    	if(raiz != NULL)
        	*raiz = NULL;
    	return raiz;
}

void liberaProduto(struct Produto* no)
{
    	if(no == NULL)
        	return;
    	liberaProduto(no->esq);
    	liberaProduto(no->dir);
    	free(no);
    	no = NULL;
}

void liberaArvBin(ArvBin* raiz)
{
    	if(raiz == NULL)
        	return;
    	liberaProduto(*raiz);//libera cada nó
    	free(raiz);//libera a raiz
}

int insereArvBin(ArvBin* raiz, int matricula, int tipo)
{
    	if(raiz == NULL)
        	return 0;
    	struct Produto* novo;
    	novo = (struct Produto*) malloc(sizeof(struct Produto));
    	if(novo == NULL)
        	return 0;
    	novo->info = matricula;
    	novo->dir = NULL;
    	novo->esq = NULL;
    	if(*raiz == NULL)
        	*raiz = novo;
	else
    	{
		struct Produto* atual = *raiz;
        	struct Produto* ant = NULL;
        	while(atual != NULL)
        	{
			ant = atual;
            		if(matricula == atual->info)
            		{
                		free(novo);
                		return 0;//elemento já existe
            		}
            		if(matricula > atual->info)
                		atual = atual->dir;
            		else
                		atual = atual->esq;
        	}
        	if(matricula > ant->info)
            		ant->dir = novo;
        	else
			ant->esq = novo;
    	}
	return 1;
}

int removeArvBin(ArvBin *raiz, int matricula)
{
	if(raiz == NULL)
        	return 0;
   	struct Produto* ant = NULL;
    	struct Produto* atual = *raiz;
    	while(atual != NULL)
	{
        	if(matricula == atual->info)
        	{
            		if(atual == *raiz)
                		*raiz = remove_atual(atual);
            	else
            	{
                	if(ant->dir == atual)
                    		ant->dir = remove_atual(atual);
                	else
                    		ant->esq = remove_atual(atual);
            	}
            	return 1;
        }
        ant = atual;
	if(matricula > atual->info)
		atual = atual->dir;
        else
            	atual = atual->esq;
    }
    return 0;
}

int estaVaziaArvBin(ArvBin *raiz)
{
    	if(raiz == NULL)
        	return 1;
    	if(*raiz == NULL)
        	return 1;
	return 0;
}

int consultaArvBin(ArvBin *raiz, int valor)
{
    	if(raiz == NULL)
        	return 0;
    	struct Produto* atual = *raiz;
	while(atual != NULL)
    	{
        	if(valor == atual->info)
        	{
            		return 1;
        	}
	if(valor > atual->info)
        	atual = atual->dir;
	else
		atual = atual->esq;
    }
    return 0;
}

void emOrdemArvBin(ArvBin *raiz)
{
	if(raiz == NULL)
        	return;
    	if(*raiz != NULL)
    	{
        	emOrdemArvBin(&((*raiz)->esq));
        	printf("%d\n",(*raiz)->info);
        	emOrdemArvBin(&((*raiz)->dir));
    	}
}
