#include "pilha.h"
#include "fila.h"
/*gcc pilha.o fila.o progfila.o -o lab4.o
    antes é necessario compilar tudo separadamente com gcc -c*/

struct fila{
   Pilha *p1;
   Pilha *p2;
};


Fila *cria_fila(){
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->p1 = cria_pilha();
    f->p2 = cria_pilha();

    return f;
}

void insere(Pessoa* p, Fila *f){
    push(p, f->p1);
}

Pessoa *retira(Fila *f){
    Pessoa* p;

    copia_pilha(f->p1, f->p2);

    p = pop(f->p2);

    copia_pilha(f->p2, f->p1);

    return p;
}

void copia_pilha(Pilha *p1, Pilha *p2){
    while(!vazia_pilha(p1)){
        push(pop(p1), p2);
    }
}

void imprime_fila(Fila *f){

    copia_pilha(f->p1, f->p2);

    imprime_pilha(f->p2);

    copia_pilha(f->p2, f->p1);

}

int Vazia_fila(Fila *f){
    return vazia_pilha(f->p1);
}

/*Separa a fila f de tal forma que as pessoas com idade maior que 60 sejam movidas
  para a fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores".
* inputs: a fila de pessoas, as filas f_maiores e f_menores (inicialmente vazias)
* output: nao tem
* pre-condicao: fila f n�o � nula
* pos-condicao: fila f vazia, pessoas com idade maior ou igual a 60 na fila "f_maiores"
e as pessoas com idade menor que 60 para a fila "f_menores"
usar o pop para uma varaivel pessoa em p1
checar a idade da pessoa
usar o push para colocar a pessoa nem p2*/
void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores){

    copia_pilha(f->p1, f->p2);
    Pessoa *p;

    while(!vazia_pilha(f->p2)){
         p = pop(f->p2);

        if(retorna_idade(p) > 60){
            push(p, f_maiores->p1);
        }
        else{
            push(p, f_menores->p1);
        }

        push(p, f->p1);

    }
}

/*Libera toda a mem�ria utilizada pelas estruturas de dados.
* inputs: a fila de pessoas
* output: NULL
* pre-condicao: fila f n�o � nula
* pos-condicao: Mem�ria liberada */
Fila* destroi_fila (Fila* f){
    destroi_pilha(f->p1);
    destroi_pilha(f->p2);
    free(f);

    return NULL;
}
