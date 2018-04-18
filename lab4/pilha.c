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
    Pilha P = (Pilha*)malloc(sizeof(Pilha));

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
    pilha->pessoas[pilha->topo] = pessoa;
    pilha->topo++;
}


/*Retira uma Pessoa do topo da Pilha (se pilha n�o vazia)
* inputs: a Pilha
* output: a pessoa retirada do topo da pilha
* pre-condicao: Pilha n�o � nula e n�o � vazia
* pos-condicao: pilha n�o cont�m o elemento retirado do topo
*/
Pessoa* pop(Pilha* pilha){
    Pessoa *retirada;

    retirada = pilha->pessoas[pilha->topo];

    pilha->topo--;

    return retirada;
}


/*Imprime as pessoas da pilha
 * inputs: a pilha
 * output: nenhum
 * pre-condicao: pilha P n�o vazia(fessera falou em aula q era n nula)
 * pos-condicao: Pilha permanece inalterada
 */
void imprime_pilha (Pilha* pilha);


/*Libera a memoria ocupada pela pilha
* inputs: a Pilha
* output: NULL
* pre-condicao: Pilha n�o � nula
* pos-condicao: Toda memoria eh liberada
*/
Pilha* destroi_pilha(Pilha* pilha);


/*Inicializa um TipoItem Pessoa
* inputs: o nome, a idade e o endereco da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
Pessoa* inicializaPessoa(char* nome, int idade, char* endereco);

