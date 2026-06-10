#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int chave;
    int altura;
    struct No *esq;
    struct No *dir;
} No;

// Funções auxiliares
int altura(No *n)
{
    if (n == NULL)
        return 0;
    return n->altura;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int fb(No *n)
{
    if (n == NULL)
        return 0;
    return altura(n->esq) - altura(n->dir);
}

No *minimo(No *n)
{
    while (n->esq != NULL)
        n = n->esq;
    return n;
}

// Manipulação da árvore

No *criar_no(int chave)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->chave = chave;
    novo->altura = 1;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *rotacao_dir(No *n)
{
    No *t1 = n->esq;
    No *t2 = t1->dir;
    t1->dir = n;
    n->esq = t2;

    n->altura = 1 + max(altura(n->esq), altura(n->dir));
    t1->altura = 1 + max(altura(t1->esq), altura(t1->dir));
    return t1;
}

No *rotacao_esq(No *n)
{
    No *t1 = n->dir;
    No *t2 = t1->esq;
    t1->esq = n;
    n->dir = t2;

    n->altura = 1 + max(altura(n->esq), altura(n->dir));
    t1->altura = 1 + max(altura(t1->esq), altura(t1->dir));
    return t1;
}

No *inserir(No *n, int chave)
{
    if (n == NULL)
        return criar_no(chave);
    if (chave < n->chave)
    {
        n->esq = inserir(n->esq, chave);
    }
    else if (chave > n->chave)
    {
        n->dir = inserir(n->dir, chave);
    }
    else
        return n;

    n->altura = 1 + max(altura(n->esq), altura(n->dir));

    return balancear(n, chave);
}

No *balancear(No *n, int chave)
{
    int fator = fb(n);

    if (fator > 1 && chave<n->esq> chave)
    {
        return rotacao_dir(n);
    }

    if (fator < -1 && chave > n->dir->chave)
    {
        return rotacao_esq(n);
    }

    if (fator > 1 && chave > n->esq->chave)
    {
        n->esq = rotacao_esq(n->esq);
        return rotacao_dir(n);
    }

    if (fator < -1 && chave < n->dir->chave)
    {
        n->dir = rotacao_dir(n->dir);
        return rotacao_esq(n);
    }

    return n;
}

int main()
{
}