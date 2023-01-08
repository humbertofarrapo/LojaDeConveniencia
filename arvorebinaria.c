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
	else if (r->matricula > m) 
		return busca (r->esq, m);
	else if (r->matricula < m) 
		return busca (r->dir, m);
	else 
		return r;
}

Produto* insere (Produto* a, int m, int t, float p)
{
	if (a==NULL)
	{
		a = (Produto*)malloc(sizeof(Produto));
		a->matricula = m;
		a->esq = a->dir = NULL;
	}
	else if (m < a->matricula)
		a->esq = insere(a->esq,m, t, p);
	else
		a->dir = insere(a->dir,m, t, p);
	return a;
}

Produto* retira (Produto* r, int m)
{
	if (r == NULL)
		return NULL;
	else if (r->matricula > m)
		r->esq = retira(r->esq, m);
	else if (r->matricula < m)
		r->dir = retira(r->dir, m);
	else 
	{
		if (r->esq == NULL && r->dir == NULL) 
		{
			free (r);
			r = NULL;
		}
		else if (r->esq == NULL)
		{
			Produto* t = r;
			r = r->dir;
			free (t);
		}
		else if (r->dir == NULL) 
		{
			Produto* t = r;
			r = r->esq;
			free (t);
		}
		else 
		{
			Produto* pai = r;
			Produto* f = r->esq;
			while (f->dir != NULL) 
			{
				pai = f;
				f = f->dir;
			}
			r->matricula = f->matricula;
			f->matricula = m;
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
		printf("%d\n",a->tipo);
		imprime(a->dir);
	}
}
