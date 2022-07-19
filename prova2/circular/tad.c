#include "tad.h"

struct no
{
    int info;
    struct no *prox;
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

int insere_final(Lista *lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem;

    if (lista_vazia(*lst) == 1)
    {
        N->prox = N;
        *lst = N;
    }
    else
    {
        N->prox = (*lst)->prox;
        *lst = N;
    }
    return 1;
}

int remov_inicio(Lista *lst)
{
    if (lista_vazia(*lst) == 1)
    {
        return 0;
    }
    Lista aux = (*lst)->prox;
    if (*lst == (*lst)->prox)
        *lst = NULL;
    else
        (*lst)->prox = aux->prox;
    free(aux);
    return 1;
}

int insere_inicio(Lista *lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem;
    if (lista_vazia(*lst) == 1)
    {
        N->prox = N;
        *lst = N;
    }
    else
    {
        Lista aux = *lst;
        while (aux->prox != (*lst))
        {
            aux = aux->prox;
        }
        aux->prox = N;
        N->prox = *lst;
    }
    return 1;
}

int remove_final(Lista *lst)
{
    if (lista_vazia(*lst))
    {
        return 0;
    }
    if ((*lst) == (*lst)->prox)
    {
        free(*lst);
        *lst == NULL;
        return 1;
    }
    Lista ant, no = *lst;
    while (no->prox != *lst)
    {
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;
    free(no);
}

int remove_lista(Lista *lst, int elem)
{
    if (lista_vazia(*lst))
    {
        return 0;
    }

    Lista no = *lst;
    if (no->info == elem)
    {
        remov_inicio(*lst);
    }
    Lista ant = no;
    no = no->prox;
    while (no != (*lst) && no->info != elem)
    {
        ant = no;
        no = no->prox;
    }
    if (no == *lst)
        return 0;
    ant->prox = no->prox;
    free(no);
    return 1;
}

int insere_lista(Lista *lst, int elem)
{
    if (lista_vazia(*lst))
    {
        return 0;
    }
    Lista no = (Lista)malloc(sizeof(struct no));
    if (no == NULL)
        return 0;
    no->info = elem;
    if ((*lst) == NULL)
    {
        *lst = no;
        no->prox = no;
        return 1;
    }
    else
    {
        if ((*lst)->info > elem)
        {
            Lista atual = *lst;
            while (atual->prox != (*lst))
            {
                atual = atual->prox;
                no->prox = *lst;
                atual->prox = no;
                *lst = no;
                return 1;
            }
            Lista ant = *lst, atual = (*lst)->prox;
            while (atual != (*lst) && atual->info < elem)
            {
                ant = atual;
                atual = atual->prox;
            }
            ant->prox = no;
            no->prox = atual;
        }
    }
    return 1;
}