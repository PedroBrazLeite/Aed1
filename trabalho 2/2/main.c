#include "tad.h"

int main()
{
    int op, check, *aux;
    char palin[10];
    Pilha p;

    do
    {
        system("CLS || clear");
        do
        {
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar pilha\n");
            printf(" 2. Verificar pilha vazia\n");
            printf(" 4. Inserir elemento\n");
            printf(" 5. Excluir elemento\n");
            printf(" 6. Palindromo\n");
            printf(" 7. Imprimir lista\n");
            printf(" 8. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if ((op < 1) || (op > 8))
            {

                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while ((op < 1) || (op > 8));

        switch (op)
        {
        case 1:
            p = cria_pilha();
            getch();
            break;

        case 2:
            check = pilha_vazia(p);
            printf("%d", check);
            getch();
            break;
        case 4:
            printf("digite o valor:");
            scanf("%d", &check);
            push(&p, check);
            getch();
            break;

        case 5:
            pop(&p, aux);
            getch();
            break;

        case 6:
            printf("Digite sua palavara\n");
            scanf("%s", palin);
            check = palindromo(palin);
            printf("%d", check);
            getch();
            break;

        case 7:
            imprimir(p);

            getch();
            break;

        default:
            printf("\n\n Pressione qualquer tecla para FINALIZAR...");
            getch();
        }
    } while (op != 8);

    return 0;
}