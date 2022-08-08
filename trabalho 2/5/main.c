#include "tad.h"

int main()
{
    int op, check, *aux;

    Fila f;

    do
    {
        system("CLS || clear");
        do
        {
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar fila\n");
            printf(" 2. Verificar fila vazia\n");
            printf(" 3. Verificar fila cheia\n");
            printf(" 4. Inserir elemento\n");
            printf(" 5. Excluir elemento\n");
            printf(" 6. Imprimir lista\n");
            printf(" 7. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if ((op < 1) || (op > 7))
            {

                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while ((op < 1) || (op > 7));

        switch (op)
        {
        case 1:
            f = cria_fila();
            getch();
            break;

        case 2:
            check = fila_vazia(f);
            printf("%d\n", check);
            getch();
            break;

        case 3:
            check = fila_cheia(f);
            printf("%d\n", check);
            getch();
            break;

        case 4:
            printf("Digite o valor a ser inserido:\n");
            scanf("%d", &check);
            insere_fim(f, check);
            getch();
            break;

        case 5:
            remove_ini(f, aux);
            getch();
            break;

        case 6:
            imprime_fila(f);
            getch();
            break;

        default:
            printf("\n\n Pressione qualquer tecla para FINALIZAR...");
            getch();
        }
    } while (op != 7);

    return 0;
}