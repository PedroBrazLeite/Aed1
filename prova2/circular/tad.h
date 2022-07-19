#include <stdio.h>
#include <stdlib.h>

typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_final(Lista *lst, int elem);
int remov_inicio(Lista *lst);
int insere_inicio(Lista *lst, int elem);
int remove_final(Lista *lst);
int remove_lista(Lista *lst, int elem);
int insere_lista(Lista *lst, int elem);