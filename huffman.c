#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include <bits/stdc++.h>

struct tree
{
	char info;
	struct tree *esq,*dir;	
};

struct fila
{
	struct tree *info;
	struct fila *prox;
	int freq;
};

struct descritor
{
	struct fila *ini;
	struct fila *fim;
};

typedef struct descritor desc;
typedef struct tree Tree;
typedef struct fila Fila;

void InitF(desc *f)
{
	(f) -> ini = (f) -> fim = NULL;
}

void CriaNo(Tree **t,char info)
{
	*t = (Tree *)malloc(sizeof(Tree));
	(*t) -> info = info;
	(*t) -> esq = NULL;
	(*t) -> dir = NULL;
}

void criaF(Fila **f,Tree *t,int freq)
{
	Fila *novo = (Fila *)malloc(sizeof(Fila));
	novo -> info = t;
	novo -> freq = freq;
	novo -> prox = NULL;
}

void InsereF(desc *d,Tree *t,int f)
{
	Fila *novo;
	criaF(&novo,t,f);
	Fila *aux = d -> fim, *ant = NULL;
	if(aux == NULL)
	{
		d -> ini = d -> fim = novo;
	}
	else
	{
		while(aux != NULL && f < aux -> freq)
		{
			ant = aux;
			aux = aux -> prox;
		}
		if(ant == NULL)
		{
			novo -> prox = aux;
			d -> fim = novo;
		}
		else if(aux == NULL)
		{
			ant -> prox = novo;
			d -> ini = novo;
		}
		else
		{
			novo -> prox = ant -> prox;
			ant -> prox = novo;
		}
	}
}

char VazioD(desc d)
{
	return d.ini == NULL;
}

void retiraF(Tree **t,int *freq,desc *d)
{
	Fila *aux = d -> fim,*ant = NULL;
	*t = d -> ini -> info;
	*freq = d -> ini -> freq;
	while(aux -> prox != NULL)
	{
		ant = aux;
		aux = aux -> prox;
	}
	free(aux);
	d -> ini = ant;
}

char faltaUm(desc d)
{
	return d.ini -> prox == NULL;  
}

void juntaTree(Tree **raiz,Tree *t1,Tree *t2)
{
	*raiz = (Tree *)malloc(sizeof(Tree));
	(*raiz) -> info = '-';
	(*raiz) -> esq = t1;
	(*raiz) -> dir = t2;
}

char vaziaTree(Tree *t)
{
	return t == NULL;
}

void CriaHuffman(Tree **raiz,char str[30])
{
	
	desc d;
	InitF(&d);
	Tree *t;
	Tree *auxt1,*auxt2;
	
	int i,j,freq,auxf1,auxf2;
	
	for(i = 0;i < strlen(str);i++)
	{
		freq = 1;
		if(str[i] != '-')
		{
			for(j = i + 1;j < strlen(str);j++)
			{
				if(str[i] == str[j])
				{
					strcpy(str,"-");
					freq++;
				}
			}	
			//aqui adicionar arvore na fila
			CriaNo(&t,str[i]);
			InsereF(&d,t,freq);
		}
	}
	if(!VazioD(d))
	{
		while(!faltaUm(d))
		{
			retiraF(&auxt1,&auxf1,&d);
			retiraF(&auxt2,&auxf2,&d);
			freq = auxf1+auxf2;
			juntaTree(&t,auxt1,auxt2);
			InsereF(&d,t,freq);
		}
		retiraF(&*raiz,&freq,&d);
	}
}

void ExibeHoffman(Tree *t,char str[])
{
	int i;
	Tree *aux = t;
	if(!vaziaTree(t))
	{
		for(i = 0;i < strlen(str);i++)
		{
			if(t -> dir != t -> esq)
			{
				if(str[i] == '1')
					aux = aux -> dir;
				else
					aux = aux -> esq;
			}
			else
			{
				printf("%c ",aux -> info);
				aux = t;
			}
		}
	}
	printf("%c\n");
}

int main()
{
	Tree *raiz;
	CriaHuffman(&raiz,"111223445");
	ExibeHoffman(raiz,"111101100010");
}
