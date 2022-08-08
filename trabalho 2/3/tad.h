#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha *Pilha;
Pilha cria_pilha();
int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);
int push(Pilha p, int elem);
int pop(Pilha p);
void convertDecBin(Pilha p, int dec);
void imprime(Pilha p);
