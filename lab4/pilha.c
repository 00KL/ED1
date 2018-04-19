#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define max 10

/*TipoItem Pessoa (tipo opaco). Contem campos:
  - nome (string)
  - idade (int)
  - endereco (string)
  */
struct pessoa{
    char *nome;
    int idade;
    char *endereco;
};


/*Tipo que define a Pilha (tipo opaco)
  Atencao: Esta pilha pode conter ate 10 Pessoas
*/
struct pilha{
    Pessoa *pessoas[max];
    int topo;

};


/*Inicializa a Pilha
* inputs: nenhum
* output: P (a pilha criada)
* pre-condicao: nenhuma
* pos-condicao: P est� definida e vazia
*/
Pilha* cria_pilha(){
    Pilha *P = (Pilha*)malloc(sizeof(Pilha));

    P->topo = 0;

    return P;
}

/*Insere uma pessoa no topo da pilha (se houver espaco)
* inputs: P (uma pilha) e E (uma pessoa)
* output: nenhum
* pre-condicao: P nao vazia(fessera falou em aula q era n nula) e com espaco para o elemento.
* pos-condicao: Ao final da fun��o, a pilha tem E como o elemento
do topo
*/
void push(Pessoa* pessoa, Pilha* pilha){
    if(pilha->topo < max){
         pilha->pessoas[pilha->topo] = pessoa;
        pilha->topo = pilha->topo + 1;
    }
   
    

}


/*Retira uma Pessoa do topo da Pilha (se pilha n�o vazia)
* inputs: a Pilha
* output: a pessoa retirada do topo da pilha
* pre-condicao: Pilha n�o � nula e n�o � vazia
* pos-condicao: pilha n�o cont�m o elemento retirado do topo
*/
Pessoa* pop(Pilha *pilha){
    Pessoa *retirada;

    retirada = pilha->pessoas[pilha->topo-1];

    pilha->topo = pilha->topo - 1;

    return retirada;
}


/*Imprime as pessoas da pilha
 * inputs: a pilha
 * output: nenhum
 * pre-condicao: pilha P n�o vazia(fessera falou em aula q era n nula)
 * pos-condicao: Pilha permanece inalterada
 */
void imprime_pilha (Pilha* pilha){
    int i;

    for(i = 0; i < pilha->topo; i++){
        printf("%s\n",pilha->pessoas[i]->nome);
        printf("%d\n", pilha->pessoas[i]->idade);
        printf("%s\n\n", pilha->pessoas[i]->endereco);
    }

}


/*Libera a memoria ocupada pela pilha
* inputs: a Pilha
* output: NULL
* pre-condicao: Pilha n�o � nula
* pos-condicao: Toda memoria eh liberada
*/
Pilha* destroi_pilha(Pilha* pilha){
    int i;

    for(i = 0; i < pilha->topo; i++){
        
        free(pilha->pessoas[i]->nome);
        free(pilha->pessoas[i]->endereco);
        free(pilha->pessoas[i]);
    }

    free(pilha);

    return NULL;
}


/*Inicializa um TipoItem Pessoa
* inputs: o nome, a idade e o endereco da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
Pessoa* inicializaPessoa(char* nome, int idade, char* endereco){
    Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
    p->nome = (char*)malloc(sizeof(char)*strlen(nome));
    p->endereco = (char*)malloc(sizeof(char)*strlen(endereco));

    strcpy(p->nome, nome);
    p->idade = idade;    
    strcpy(p->endereco, endereco);
    
    return p;
}

