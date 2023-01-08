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

Produto* init()
{
	return NULL;
}

Produto* busca (Produto* r, int m)
{
	if (r == NULL) 
		return NULL;
	else if (r->info > m) 
		return busca (r->esq, m);
	else if (r->info < m) 
		return busca (r->dir, m);
	else 
		return r;
}

Produto* insere (Produto* a, int m, int t, float p)
{
	if (a==NULL)
	{
		a = (Produto*)malloc(sizeof(Produto));
		a->info = m;
		a->esq = a->dir = NULL;
	}
	else if (m < a->info)
		a->esq = insere(a->esq,m);
	else /* m < a->info */
		a->dir = insere(a->dir,m);
	return a;
}

Produto* retira (Produto* r, int m)
{
	if (r == NULL)
		return NULL;
	else if (r->info > m)
		r->esq = retira(r->esq, m);
	else if (r->info < m)
		r->dir = retira(r->dir, m);
	else 
	{/* achou o elemento */
		if (r->esq == NULL && r->dir == NULL) 
		{ /* elemento sem filhos */
			free (r);
			r = NULL;
		}
		else if (r->esq == NULL)
		{/* só tem filho à direita */
			Produto* t = r;
			r = r->dir;
			free (t);
		}
		else if (r->dir == NULL) 
		{/* só tem filho à esquerda */
			Produto* t = r;
			r = r->esq;
			free (t);
		}
		else 
		{/* tem os dois filhos */
			Produto* pai = r;
			Produto* f = r->esq;
			while (f->dir != NULL) 
			{
				pai = f;
				f = f->dir;
			}
			r->info = f->info;
			/* troca as informações */
			f->info = m;
			r->esq = retira(r->esq,m);
		}
	}
	return r;
}

void imprime (Produto* a)
{
	if (a != NULL)
	{
		imprime(a->esq);
		printf("%d\n",a->info);
		imprime(a->dir);
	}
}
