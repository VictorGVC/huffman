struct tree
{
	int info;
	struct tree *esq,*dir;	
};

struct fila
{
	struct tree *info;
	struct lista *prox;
	int freq;
}

struct descritor
{
	struct fila *ini;
	struct fila *fim;
}

typedef struct descritor desc;
typedef struct tree Tree;
typedef struct fila Fila;

void InitF(Fila **f)
{
	*f = NULL;
}

void CriaNo(Tree **t,int info)
{
	(*t) -> info = info;
	(*t) -> esq = NULL;
	(*t) -> dir = NULL;
}

void InsereF(desc *d,Tree *t,int f)
{
	if(*d.ini == NULL)
	{
		*d.ini = *d.fim = t;
	}
	else if()
	{
		
	}
}

void CriaHuffman(char str[])
{
	
}

int main()
{
	
}
