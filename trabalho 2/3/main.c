#include "tad.h"

void dec2bin(int n, char *t);
int main(void)
{
    char bin[10];
    int n;
    printf("Digite o valor\n");
    scanf("%d", &n);
    dec2bin(n, bin);
    printf("%d(dec) -> %s(binario)\n", n, bin);
    return 0;
}
void dec2bin(int n, char *t)
{
    Pilha p = cria_pilha();
    do
    {
        push(p, n % 2);
        n /= 2;
    } while (n);

    while (!pilha_vazia(p))
        *t++ = '0' + pop(p);
    *t = '\0';
}