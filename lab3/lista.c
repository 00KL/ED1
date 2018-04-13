#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include <string.h>
#include "lista.h"

/*TipoItem Aluno (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD. Devem ser definidos campos:
  - nome (string)
  - matricula (int)
  - endereco (string)
  */
 struct tipoitem {
    
    char* nome;
    int matricula;
    char* endereco; 
};

typedef struct celula celula{
    Tipoitem* itemDaCelula;
    celula* prox;
};

/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD.
  Usar lista COM Sentinela
  */
 struct tipolista {
    celula* prim, ulti;
};

/*Inicializa o sentinela de uma lista
* inputs: nenhum
* output: Sentinela inicializado
* pre-condicao: nenhuma
* pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL
*/
TipoLista* InicializaLista(){
    Tipolista* = lista;
    lista = (Tipolista* )malloc(sizeof(Tipolista));

    lista->prim = NULL;
    lista->ulti = NULL;

    return lista;
}

/*Insere um aluno na primeira posi��o da lista de alunos
* inputs: aluno a ser inserido na lista (do tipo TipoItem) e a lista
* output: nenhum
* pre-condicao: aluno e lista n�o s�o nulos
* pos-condicao: lista cont�m o aluno inserido na primeira posi��o
*/
void Insere (TipoItem* aluno, TipoLista* lista){
    if(lista->prim == NULL){
        celula* celula = (celula*) malloc(sizeof(celula));

        celula->itemDaCelula = InicializaTipoItem(aluno->nome, aluno->matricula, aluno->endereco);

        celula->prox = NULL;

        lista->prim = celula;

        lista->ulti = celula;
         
    } else {
        celula* celula = (celula*) malloc(sizeof(celula));

        celula->itemDaCelula = InicializaTipoItem(aluno->nome, aluno->matricula, aluno->endereco);

        celula->prox = lista->prim;

        lista->prim = celula;
    }



}

/*Retira um aluno de matr�cula mat da lista de alunos
* inputs: a lista e a matr�cula do aluno a ser retirado da lista
* output: o aluno (do tipo TipoItem) retirado da lista ou NULL, se o aluno n�o se encontrar na lista
* pre-condicao: lista n�o � nula
* pos-condicao: lista n�o cont�m o aluno de matr�cula mat
*/
TipoItem* Retira (TipoLista* lista, int mat){
    celula* aux = (celula*)malloc(sizeof(celula));

    aux->prox = lista->prim;

    do{
        if(aux->prox->itemDaCelula->matricula == mat){
            
            
        }



    }while(aux->prox == NULL);
}


/*Imprime os dados de todos os alunos da lista
* inputs: a lista de alunos
* output: nenhum
* pre-condicao: lista n�o � nula
* pos-condicao: dados dos alunos impressos na saida padrao
*/
void Imprime (TipoLista* lista);

/*Libera toda a mem�ria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
* inputs: a lista encadeada de alunos
* output: Lista vazia (NULL)
* pre-condicao: lista n�o � nula
* pos-condicao: mem�ria alocada � liberada
*/
TipoLista* Libera (TipoLista* lista);


/*Inicializa um TipoItem aluno
* inputs: o nome, a matricula e o endereco do aluno
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, matricula e endereco validos
* pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
*/
TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco){
    TipoItem* item = (TipoItem*)malloc(sizeof(TipoItem));

    item->nome = (char*)malloc( (strlen(nome) + 1/*strlen retorna tamanho sem o '\0' */ ) * sizeof(char));
    strcpy(item->nome, nome);

    item->matricula = matricula;

    item->endereco = (char*)malloc( (strlen(nome) + 1/*strlen retorna tamanho sem o '\0' */ ) * sizeof(char));
    strcpy(item->endereco, endereco);


    return item;
}


#endif /* LISTA_H_ */
