#include "tad.h"

struct no
{
    int info;
    struct no *prox;
    struct no *ant;
};

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
        return 1;
    else
        return 0;
}

int insere_elemento(Lista *lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0;
    }
    N->info = elem;
    N->ant = NULL;
    N->prox = *lst;
    if (lista_vazia(*lst) == 0)
        (*lst)->ant = N;
    *lst = N;
    return 1;
}

int remove_elemento(Lista *lst, int elem)
{
    if (lista_vazia(*lst))
        return 0;
    Lista aux = *lst;
    while (aux->prox != NULL && aux->info != elem)
    {
        aux = aux->prox;
    }
    if (aux->info != elem)
    {
        return 0;
    }
    if (aux->prox != NULL)
        (aux)->prox->ant = aux->ant;
    if (aux->ant != NULL)
        (aux)->ant->prox = aux->prox;
    if (aux == *lst)
        *lst = aux->prox;
    free(aux);
    return 1;
}

int insere_ord(Lista *lst, int elem)
{
    if (lst == NULL)
        return 0;
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem;
    if (lista_vazia(lst))
    {
        N->prox = NULL;
        N->ant = NULL;
        *lst = N;
        return 1;
    }
    else
    {
        Lista ante, atual = *lst;
        while (atual != NULL && atual->info < elem)
        {
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *lst)
        {
            N->ant = NULL;
            (*lst)->ant = N;
            N->prox = (*lst);
            *lst = N;
        }
        else
        {
            N->prox = ante->prox;
            N->ant = ante;
            ante->prox = N;
            if (atual != NULL)
            {
                atual->ant = N;
            }
        }
    }
    return 1;
}

int remove_lista(Lista *lst, int elem)
{
    if (lst == NULL)
        return 0;
    Lista n = *lst;
    while (n != NULL && n->info != elem)
    {
        n = n->prox;
    }
    if (n == NULL)
        return 0;
    if (n->ant == NULL)
    {
        *lst = n->prox;
    }
    else
    {
        n->ant->prox = n->prox;
    }

    if (n->prox != NULL)
    {
        n->prox->ant = n->ant;
    }
    free(n);
    return 1;
}