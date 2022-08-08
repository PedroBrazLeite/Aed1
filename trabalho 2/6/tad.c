#include "tad.h"

struct no
{
    int info;
    struct no *prox;
};

struct fila
{
    struct no *ini;
    struct no *fim;
};

Fila cria_fila()
{
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));
    if (f != NULL)
    {
        f->ini = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_vazia(Fila f)
{
    if (f->ini == NULL)
        return 1;
    else
        return 0;
}

int insere_fim(Fila f, int elem)
{
    struct no *N;
    N = (struct no *)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem;
    N->prox = NULL;
    if (fila_vazia(f) == 1)
        f->ini = N;
    else
        (f->fim)->prox = N;
    f->fim = N;
    return 1;
}

int remove_ini(Fila f)
{
    if (fila_vazia(f) == 1)
        return 0;
    struct no *aux = f->ini;
    if (f->ini == f->fim)
        f->fim = NULL;
    f->ini = aux->prox;
    free(aux);
    return 1;
}

void imprime_fila(Fila f)
{
    struct no *aux = f->ini;
    printf("Fila:{");
    for (aux; aux != NULL; aux = aux->prox)
    {
        printf((aux->prox != NULL) ? "%d" : "%d", aux->info);
    }
    printf("}\n");
}