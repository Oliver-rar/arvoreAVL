#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int chave;
    int altura;
    struct No *esq;
    struct No *dir;
} No;

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
}

int main()
{
}