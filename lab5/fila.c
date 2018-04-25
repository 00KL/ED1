#include "pilha.h"
#include "fila.h"
/*gcc pilha.o fila.o progfila.o -o lab4.o
    antes é necessario compilar tudo separadamente com gcc -c*/

fila *cria_fila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f->p1 = cria_pilha();
    f->p2 = cria_pilha();

    return f;
}

void insere(pessoa* p, Fila *f){
    push(p, f->p1);
}

Pessoa retira(Fila *f){
    Pessoa* ṕ;

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

imprime_fila(Fila *f){
    
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
    
    while(!vazia_pilha(fila->p1)){
        if(retorna_idade(f->p1) > 60){

        }
    }
}

