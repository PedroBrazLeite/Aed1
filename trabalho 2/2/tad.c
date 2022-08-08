#include "tad.h"

struct no
{
    int info;
    struct no *prox;
};

Pilha cria_pilha()
{
    return NULL;
}

int pilha_vazia(Pilha p)
{
    if (p == NULL)
        return 1;
    else
        return 0;
}

int push(Pilha *p, int elem)
{
    Pilha N = (Pilha)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem;
    N->prox = *p;
    *p = N;
    return 1;
}

int pop(Pilha *p, int *elem)
{
    if (pilha_vazia(*p) == 1)
        return 0;
    Pilha aux = *p;
    *elem = aux->info;
    *p = aux->prox;
    free(aux);
    return 1;
}

int le_topo(Pilha *p, int *elem)
{
    if (pilha_vazia(*p) == 1)
        return 0;
    Pilha aux = *p;
    *elem = aux->info;
    return 1;
}

int palindromo(char *vet)
{
    int len, mid, elem;
    int i;
    Pilha p = cria_pilha();
    len = strlen(vet);
    mid = len / 2;
    for (int i = 0; i < mid; i++)
    {
        push(&p, vet[i]);
    }
    i = ((len % 2) != 0) ? i + 1 : i;
    while (vet[i] != '\0')
    {
        pop(&p, &elem);
        if (elem != vet[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void imprimir(Pilha p)
{

    Pilha percorre;

    percorre = p;

    if (p == NULL)
        printf("A Pilha se encontra vazia!\n"); // Pilha Vazia
    else
    {
        while (percorre != NULL)
        {

            printf("Elemento: %d \n", percorre->info);

            percorre = percorre->prox;
        }
    }
}