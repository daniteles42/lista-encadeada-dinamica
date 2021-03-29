#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadeada.h"

struct elemento{

    struct aluno dados;

    struct elemento * prox;

};

typedef struct elemento Elem;

/* Função de criação de lista: Aqui é utilizado um ponteiro auxiliar chamado de li que
recebe uma alocação de memória. Se esse for diferente de NULO, seu valor recebe nulo e é retornado para
o ponteiro que o chamou. Assim ele aloca memória para um ponteiro do tipo Lista corretamente */

Lista * cria_lista(){

    Lista * li = (Lista *) malloc(sizeof(Lista));

    if(li != NULL){

        *li = NULL;

    }

    printf("\nLista Criada!\n");

    return li;

}

/* A função libera_lista, recebe um ponteiro do tipo lista como parâmetro. Caso seu valor seja diferente de NULL,
é criado um ponteiro do tipo elemento (que possui a estrutura de um nó da lista), que percorre os valores da lista.
Enquanto o valor do elemento da lista for diferente de nulo, ou seja, não é o último, o elemento auxiliar
recebe o valor do elemento da lista no momento. Apóx, o valor da lista recebe o próximo elemento.
e o nó é liberado da memória. Ao fim, o ponteiro Lista é liberado completamente, sendo percorrido parte a parte.*/

void libera_lista(Lista * li){

    if(li != NULL){

        Elem * no;

        while((*li) != NULL){

            no = *li;

            *li = (*li)->prox;

            free(no);

        }

        free(li);

        printf("\nLista Liberada!\n");
    }else{

        *li = NULL;

        free(li);

        printf("\nLista Liberada!\n");

    }

}

int tamanho_lista (Lista * li){

    if(li == NULL || (*li) == NULL){

        printf("\nLista Vazia!");

        return 0;

    }

    else{

        int quant = 0;

        Elem * no = *li;

        while(no != NULL){

            quant++;

            no = no->prox;

        }

        printf("\nO tamanho da lista eh igual a: %d\n", quant);

        return quant;
    }

}

int lista_vazia(Lista * li){

    if(li == NULL || (*li) == NULL){

        return 1;

    }

    else{

        return 0;

    }

}

int insere_lista_inicio(Lista * li, struct aluno al){

    if(li == NULL){

        printf("\nLista Vazia!\n");
        return 0;

    }

    else{

        Elem * no;

        no = (Elem *) malloc(sizeof(Elem));

        if(no == NULL){

            return 0;

        }

        else{

            no->dados = al;

            no->prox = (*li);

            (*li) = no;

            printf("\nElemento Inserido na Lista com Sucesso!\n");

            return 1;

        }

    }

}

int insere_lista_final(Lista * li, struct aluno al){

    if(li == NULL){

        printf("\nLista Vazia!\n");

        return 0;

    }

    else{

        Elem * no;

        no = (Elem *) malloc(sizeof(Elem));

        if(no == NULL){

            printf("\nLista Vazia!\n");
            return 0;

        }else{

            no->dados = al;
            no->prox = NULL;

            if((*li) == NULL){

                *li = no;

            }else{

                Elem * aux;

                aux = *li;

                while(aux->prox != NULL){

                    aux = aux->prox;

                }
                aux->prox = no;
            }

            return 1;
        }

    }
}

int insere_lista_ordenado(Lista * li, struct aluno al){

    if(li == NULL){
        printf("\nLista Vazia!\n");
        return 0;
    }else{

        Elem * no = (Elem *) malloc(sizeof(Elem));

        if(no == NULL){
            printf("\nLista Vazia!\n");
            return 0;

        }else{

            no->dados = al;
            if((*li) == NULL){

                no->prox = NULL;
                *li = no;
                printf("\nElemento Inserido com Sucesso!\n");
                return 1;
            }else{

                Elem * ant, * atual = *li;

                while(atual != NULL && atual->dados.matricula < al.matricula){

                    ant = atual;
                    atual = atual->prox;


                }if(atual == *li){

                    no->prox = (*li);
                    *li = no;

                }else{

                    no->prox = atual;
                    ant->prox = no;
                }

                printf("\nElemento Inserido na Lista!\n");
                return 1;


            }


        }

    }



}

void imprime_lista(Lista * li){

    if(li == NULL){

        printf("\nLista Vazia!\n");
        return;

    }

    if((*li) == NULL){
        printf("\nLista Vazia!\n");
        return;
    }

    if(li != NULL){

        Elem * no = *li;

        while(no != NULL){

            printf("\nMatricula: %d", no->dados.matricula);
            printf("\nNome: %s", no->dados.nome);
            printf("\nNota1: %f", no->dados.n1);
            printf("\nNota2: %f", no->dados.n2);
            printf("\nNota3: %f\n", no->dados.n3);

            no = no->prox;

        }
    }else{

        printf("\nLista Vazia!\n");

    }

}

int remove_lista_inicio(Lista * li){

    if(li == NULL){

        printf("\nLista Vazia!\n");
        return 0;
    }

    if((*li) == NULL){

        printf("\nLista Vazia!\n");
        return 0;
    }

    else{

        Elem *no = *li;

        *li = no->prox;

        free(no);

        printf("\nObjeto Removido com Sucesso!\n");

        return 1;

    }

}

int remove_lista_final(Lista * li){

    if(li == NULL || (*li) == NULL){

        printf("\nLista Vazia!\n");
        return 0;

    }else{

        Elem * ant, *no = *li;
        while(no->prox != NULL){

            ant = no;
            no = no->prox;

        }

        if(no == (*li)){

            *li = no->prox;

        }else{

            ant->prox = no->prox;
        }
        free(no);
        printf("\nObjeto Removido com Sucesso!\n");
        return 1;
    }

}

int remove_lista(Lista * li, int matricula){

    if(li == NULL || (*li) == NULL){

        printf("\nNao foi possivel remover, lista ja vazia!\n");
        return 0;

    }else{

        Elem *ant, *no = *li;
        while(no != NULL && no->dados.matricula != matricula){

            ant = no;

            no = no->prox;

        }

        if(no == NULL){

            printf("\nMatricula nao encontrada!\n");

            return 0;

        }

        if(no == (*li)){

            *li = no->prox;

        }

        else{

            ant->prox = no->prox;

        }

        free(no);

        printf("\nObjeto Removido com Sucesso!\n");

        return 1;

    }


}

int consulta_posicao(Lista * li, int pos, struct aluno * al){

    if(li == NULL || pos <= 0){

        printf("\nEssa posicao nao existe na lista!\n");
        return 0;

    }else{

        Elem * no = *li;

        int i = 1;

        while(no->prox != NULL && i < pos){

            no = no->prox;

            i++;
        }

        if(no == NULL){

            printf("\nPosicao Nao Encontrada!\n");

            return 0;

        }else{

            *al = no->dados;

            printf("\nValor encontrado na lista, na posicao: %d\n", i);

            printf("\nMatricula da Posicao %d: Numero: %d - Nome: %s - Nota 1: %f - Nota 2: %f - Nota 3: %f\n", i, al->matricula, al->nome, al->n1, al->n2, al->n3);

            return 1;

        }

    }

}

int consulta_lista_mat(Lista * li, int mat, struct aluno * al){

    if(li == NULL || (*li) == NULL){

        printf("\nLista Vazia!\n");

        return 0;
    }else{

        Elem * no = *li;

        while(no != NULL && no->dados.matricula != mat){

            no = no->prox;

        }

        if(no == NULL){

            printf("\nElemento nao encontrado na lista!\n");

            return 0;

        }else{

            *al = no->dados;

            printf("\nElemento Encontrado na Lista!\n");

            printf("\nRegistro da Matricula Buscada: Numero: %d - Nome: %s - Nota 1: %f - Nota 2: %f - Nota 3: %f\n", al->matricula, al->nome, al->n1, al->n2, al->n3);

            return 1;

        }



    }

}

void menu(){

    //system("cls");

    printf("\n###### MENU ######");
    printf("\nAluno: Daniel Carvalho Teles - 0103N");
    printf("\n1 - Criar Lista");
    printf("\n2 - Liberar Lista");
    printf("\n3 - Mostrar o Tamanho da Lista");
    printf("\n4 - Inserir no Inicio da Lista");
    printf("\n5 - Inserir no Fim da Lista");
    printf("\n6 - Inserir na Lista Ordenado");
    printf("\n7 - Deletar do Inicio da Lista");
    printf("\n8 - Deletar do Fim da Lista");
    printf("\n9 - Deletar Elemento da Lista por matricula Definida");
    printf("\n10 - Consultar Posicao de um Elemento na Lista");
    printf("\n11 - Consultar se um Elemento esta na Lista");
    printf("\n12 - Mostrar Lista");
    printf("\n13 - Sair");
    printf("\nSelecionar Opcao: ");

}




