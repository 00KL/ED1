#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct celula celula ;

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

struct celula{
    TipoItem* itemDaCelula;
    celula* prox;
};

/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD.
  Usar lista COM Sentinela
  */
 struct tipolista {
    celula *prim, *ulti;
};

/*Inicializa o sentinela de uma lista
* inputs: nenhum
* output: Sentinela inicializado
* pre-condicao: nenhuma
* pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL
*/
TipoLista* InicializaLista(){
    TipoLista* lista;
    lista = (TipoLista* )malloc(sizeof(TipoLista));

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
    
    celula *cel = (celula*)malloc(sizeof(celula));

    cel->itemDaCelula = InicializaTipoItem(aluno->nome, aluno->matricula, aluno->endereco);


    if(lista->prim == NULL){
        
        cel->prox = NULL;

        lista->prim = cel;

        lista->ulti = cel;
         
    } else {

        cel->prox = lista->prim;

        lista->prim = cel;
    }



}

/*Retira um aluno de matr�cula mat da lista de alunos
* inputs: a lista e a matr�cula do aluno a ser retirado da lista
* output: o aluno (do tipo TipoItem) retirado da lista ou NULL, se o aluno n�o se encontrar na lista
* pre-condicao: lista n�o � nula
* pos-condicao: lista n�o cont�m o aluno de matr�cula mat
*/
TipoItem* Retira (TipoLista* lista, int mat){
    
    celula* aux;
    celula* retira;

    aux->prox = lista->prim;

    do{

        if(aux->prox->itemDaCelula->matricula == mat){
            aux->itemDaCelula = InicializaTipoItem(aux->prox->itemDaCelula->nome, aux->prox->itemDaCelula->matricula, aux->prox->itemDaCelula->endereco);

            free(aux->prox->itemDaCelula->nome);
            free(aux->prox->itemDaCelula->endereco);
            free(aux->prox->itemDaCelula);

            retira = aux->prox;

            aux->prox = aux->prox->prox;

            free(retira);

            return aux->itemDaCelula;
            
        }



    }while(aux->prox == NULL);



}


/*Imprime os dados de todos os alunos da lista
* inputs: a lista de alunos
* output: nenhum
* pre-condicao: lista n�o � nula
* pos-condicao: dados dos alunos impressos na saida padrao
*/
void Imprime (TipoLista* lista){
    celula* percorre = (celula*)malloc(sizeof(celula));

    percorre->prox = lista->prim;

    while(percorre->prox != NULL){
        printf("\n\n%s\n", percorre->prox->itemDaCelula->nome);
        printf("Matricula: %d\n", percorre->prox->itemDaCelula->matricula);
        printf("%s\n\n", percorre->prox->itemDaCelula->endereco);
        percorre->prox = percorre->prox->prox;
    }

}

/*Libera toda a mem�ria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
* inputs: a lista encadeada de alunos
* output: Lista vazia (NULL)
* pre-condicao: lista n�o � nula
* pos-condicao: mem�ria alocada � liberada
*/
TipoLista* Libera (TipoLista* lista){
    celula* percorre;


    while(lista->prim != NULL){
        percorre->prox = lista->prim;

        free(percorre->prox->itemDaCelula->nome);
        free(percorre->prox->itemDaCelula->endereco);
        free(percorre->prox->itemDaCelula);

        lista->prim = lista->prim->prox;
        free(percorre);
                
    }

}


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
