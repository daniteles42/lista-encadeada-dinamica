#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadeada.h"

int main()
{
    int ativo = 1;

    int opcao, matricula, pos, mat, x;

    //char c;

    //Implementacao com menu;

    while(ativo != 0){

        menu();

        struct aluno dados_aluno;

        scanf("%d", &opcao);

        Lista * li;

        switch(opcao){

            case 1:

                li = cria_lista();
                break;

            case 2:
                //Libera Lista;
                libera_lista(li);
                break;

            case 3:
                //Mostrar o Tamanho da Lista;
                x = tamanho_lista(li);
                break;

            case 4:
                //Inserir no inicio da lista;
                printf("\nInsira o numero da matricula do aluno: ");
                scanf("%d", &dados_aluno.matricula);

                printf("\nInsira o nome do aluno: ");
                fseek(stdin, 0, SEEK_END);
                scanf("%[^\n]", dados_aluno.nome);

                printf("\nInsira a nota 1 do aluno: ");
                scanf("%f", &dados_aluno.n1);

                printf("\nInsira a nota 2 do aluno: ");
                scanf("%f", &dados_aluno.n2);

                printf("\nInsira a nota 3 do aluno: ");
                scanf("%f", &dados_aluno.n3);

                printf("\nNumero matricula: %d - Nome: %s - Nota 1: %f, Nota 2: %f, Nota 3: %f", dados_aluno.matricula, dados_aluno.nome, dados_aluno.n1, dados_aluno.n2, dados_aluno.n3);

                insere_lista_inicio(li, dados_aluno);
                break;

            case 5:
                //Inserir no fim da lista;
                printf("\nInsira o numero da matricula do aluno: ");
                scanf("%d", &dados_aluno.matricula);

                printf("\nInsira o nome do aluno: ");
                fseek(stdin, 0, SEEK_END);
                scanf("%[^\n]", dados_aluno.nome);

                printf("\nInsira a nota 1 do aluno: ");
                scanf("%f", &dados_aluno.n1);

                printf("\nInsira a nota 2 do aluno: ");
                scanf("%f", &dados_aluno.n2);

                printf("\nInsira a nota 3 do aluno: ");
                scanf("%f", &dados_aluno.n3);

                printf("\nNumero matricula: %d - Nome: %s - Nota 1: %f, Nota 2: %f, Nota 3: %f", dados_aluno.matricula, dados_aluno.nome, dados_aluno.n1, dados_aluno.n2, dados_aluno.n3);

                insere_lista_final(li, dados_aluno);
                break;

            case 6:
                //Inserir em Posicao Especifica na Lista;
                printf("\nInsira o numero da matricula do aluno: ");
                scanf("%d", &dados_aluno.matricula);

                printf("\nInsira o nome do aluno: ");
                fseek(stdin, 0, SEEK_END);
                scanf("%[^\n]", dados_aluno.nome);

                printf("\nInsira a nota 1 do aluno: ");
                scanf("%f", &dados_aluno.n1);

                printf("\nInsira a nota 2 do aluno: ");
                scanf("%f", &dados_aluno.n2);

                printf("\nInsira a nota 3 do aluno: ");
                scanf("%f", &dados_aluno.n3);

                printf("\nNumero matricula: %d - Nome: %s - Nota 1: %f, Nota 2: %f, Nota 3: %f", dados_aluno.matricula, dados_aluno.nome, dados_aluno.n1, dados_aluno.n2, dados_aluno.n3);


                insere_lista_ordenado(li, dados_aluno);
                break;

            case 7:
                //Deletar no inicio da lista;
                x = remove_lista_inicio(li);
                break;

            case 8:
                //Deletar no final da lista;
                x = remove_lista_final(li);
                break;

            case 9:
                //Deletar em Posicao Especifica da Lista;
                printf("\nInsira o Numero da Matricula que Deseja Remover: ");
                scanf("%d", &matricula);
                x = remove_lista(li, matricula);
                break;

            case 10:
                //int x = tamanho_lista(li);

                printf("\nInsira a Posicao do Elemento que Esta Procurando: ");
                scanf("%d", &pos);

                x = consulta_posicao(li, pos, &dados_aluno);
                break;

            case 11:
                printf("\nInsira a Matricula que Esta Procurando: ");
                scanf("%d", &mat);

                x = consulta_lista_mat(li, mat, &dados_aluno);
                break;

            case 12:
                imprime_lista(li);
                break;

            case 13:
                printf("\nObrigado por Usar o Programa!");
                ativo = 0;
                break;

            default:
                printf("\nInsira uma opcao valida!\n");
                break;

        }

    }

    return 0;
}
