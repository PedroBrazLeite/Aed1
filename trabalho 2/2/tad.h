#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct no *Pilha;
Pilha cria_pilha();
int pilha_vazia(Pilha p);
int push(Pilha *p, int elem);
int pop(Pilha *p, int *elem);
int le_topo(Pilha *p, int *elem);
int palindromo(char *vet);
void imprimir(Pilha p);