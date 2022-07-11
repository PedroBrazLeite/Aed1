#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tad.h"

int main()
{
    int op, elem, es;
    Lista lst[3];
    lst[0] = cria_lista();
    lst[1] = cria_lista();
    lst[2] = cria_lista();

    do
    {
        system("CLS || clear");
        do
        {
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Inserir na lista\n");
            printf(" 2. Menor elemento da lista\n");
            printf(" 3. Tamanho da lista\n");
            printf(" 4. Excluir elemento da lista\n");
            printf(" 5. Excluir elementos impares\n");
            printf(" 6. Concatena lista\n");
            printf(" 7. Imprimir lista\n");
            printf(" 9. Sair\n");

            printf(" Opcao: ");
            scanf("%d", &op);
            if ((op < 1) || (op > 9))
            {

                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while ((op < 1) || (op > 12));

        switch (op)
        {
        case 1:
            es = escolhe_lst();
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &elem);
            insere_elem(lst[es], elem);

            break;
        case 2:
            es = escolhe_lst();

            if (tamanho(lst[es]))
            {
                elem = menor(lst[es]);

                printf("Menor valor na lista: %d\n", elem);
            }
            else
                printf("Lista vazia!\n");

            break;
        case 3:
            es = escolhe_lst();
            elem = tamanho(lst[es]);

            printf("Tamanho da lista: %d\n", elem);

            break;
        case 4:
            es = escolhe_lst();
            printf("Digite o valor a ser removido: ");
            scanf("%d", &elem);
            remove_elem(lst[es], elem);
            break;
        case 5:
            es = escolhe_lst();
            remove_impar(lst[es]);
            imprime(lst[es]);
            break;
        case 6:
            printf("Escolha qual lista sera a base\n");
            es = escolhe_lst();
            lst[2] = concatena(lst[es], lst[!es]);
            printf("Resultado:\n");
            imprime(lst[2]);
            lst[2] = NULL;

            break;
        case 7:
            es = escolhe_lst();

            imprime(lst[es]);
            break;
        case 8:
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (op != 9);

    return 0;
}