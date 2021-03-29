#ifndef LISTADINENCADEADA_H_INCLUDED
#define LISTADINENCADEADA_H_INCLUDED

/*Aqui terá:

- Protótipos das funçoes;

- Tipo de dados armazenados na lista;

- O ponteiro Lista;

*/

struct aluno{

    int matricula;
    char nome[30];
    float n1, n2, n3;

};

typedef struct elemento * Lista;

Lista * cria_lista();

void libera_lista(Lista * li);

int tamanho_lista (Lista * li);

void menu();

int lista_vazia(Lista * li);

int insere_lista_inicio(Lista * li, struct aluno al);

int insere_lista_final(Lista * li, struct aluno al);

int insere_lista_ordenado(Lista * li, struct aluno al);

void imprime_lista(Lista * li);

int remove_lista_inicio(Lista * li);

int remove_lista_final(Lista * li);

int remove_lista(Lista * li, int matricula);

int consulta_posicao(Lista * li, int pos, struct aluno * al);

int consulta_lista_mat(Lista * li, int mat, struct aluno * al);


#endif // LISTADINENCADEADA_H_INCLUDED
