#include "listahet.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MOVEL 0
#define IMOVEL 1


/*Estrutura Cliente
  - nome (string)
  - id (int)
  */
struct cliente{
  char* nome;
  int id;
};

/*Estrutura Movel
  - placa (int)
  - ano (int)
  - valor (float)
  */
struct movel{
  int placa;
  int ano;
  float valor;
};

/*Estrutura Imovel
  - identificador (int)
  - ano (int)
  - valor (float)
  */
struct imovel {
  int identificador;
  int ano;
  float valor;
};

/*Tipo que define a lista heterogenea
  Use o ponteiro genérico para implementar a lista (void*)
  Campos da celula da lista:
   - dono (Cliente*)
   - item (void*)
   - Prox (struct listahet*)
   - identificador do item (int)
*/
struct listahet{
  Cliente *dono;
  void *item;
  struct listahet* Prox;
  int identificador_do_item;
};

/*Tipo que define a sentinela da ListaHet
  Campos da sentinela:
  - primeiro (ListaHet*)
  - ultimo (ListaHet*)
*/
struct sentinela{
  ListaHet *primeiro;
  ListaHet *ultimo;
};


/*Cria lista vazia
* inputs: nenhum
* output: lista vazia
* pre-condicao: nenhuma
* pos-condicao: lista criada e vazia
*/
ListaHet *cria (){
  ListaHet* elemento = (ListaHet*)malloc(sizeof(ListaHet));
  elemento->dono = NULL;
  elemento->item = NULL;
  elemento->Prox = NULL;

  return elemento;
}

/*Cria uma estrutura do tipo Cliente
* inputs: nome do cliente e o identificador do cliente
* output: Endereço da estrutura cliente criada
* pre-condicao: nome e id validos
* pos-condicao: estrutura cliente criada, com os campos nome e id
  corretamente atribuidos
*/
Cliente* cria_cliente (char* nome, int id){
  Cliente *pessoa = (Cliente *)malloc(sizeof(Cliente));
  pessoa->nome = (char *)malloc(sizeof(char)*strlen(nome)+1);
  strcpy(pessoa->nome, nome);
  pessoa->id = id;

  return pessoa;
}

/*Cria uma estrutura do tipo Movel
* inputs: placa, ano de fabricacao e valor do automovel
* output: Endereço da estrutura movel criada
* pre-condicao: placa, ano e valor validos
* pos-condicao: estrutura movel criada
*/
Movel* cria_movel (int placa, int ano, float valor){
  Movel *carro = (Movel*)malloc(sizeof(Movel));
  carro->placa = placa;
  carro->ano = ano;
  carro->valor = valor;

  return carro;
}

/*Cria uma estrutura do tipo Imovel
* inputs: identificador, ano de construcao e o valor do imovel
* output: Endereço da estrutura imovel criada
* pre-condicao: id, ano e valor validos
* pos-condicao: estrutura imovel criada
*/
Imovel* cria_imovel (int id, int ano, float valor){
  Imovel *casa = (Imovel*)malloc(sizeof(Imovel));
  casa->identificador = id;
  casa->ano = ano;
  casa->valor = valor;

  return casa;
}




/*Insere um item (do tipo Movel) na primeira posicao da lista
* inputs: a lista, o cliente dono do automovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e automovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_movel (ListaHet* lista, Cliente* dono, Movel* item){
  ListaHet* novo = (ListaHet*)malloc(sizeof(ListaHet));
  novo->dono = dono;
  //isso é valido pois um ponteiro void pode apontar para qualquer coisa
  novo->item = item;
  novo->Prox = lista;
  //nao e possivel acessar o campo de placa
  //logo e necessario uma funcao para extrair essa informacao
  novo->identificador_do_item = MOVEL;

  return novo;
}


/*Insere um item (do tipo Imovel) na primeira posicao da lista
* inputs: a lista, o cliente dono do imovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e imovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_imovel (ListaHet* lista, Cliente* dono, Imovel* item){
  ListaHet* novo = (ListaHet*)malloc(sizeof(ListaHet));
  novo->dono = dono;
  //isso é valido pois um ponteiro void pode apontar para qualquer coisa
  novo->item = item;
  novo->Prox = lista;
  //nao e possivel acessar o campo de placa
  //logo e necessario uma funcao para extrair essa informacao
  novo->identificador_do_item = IMOVEL;

  return novo;
}




void imprime_cliente(Cliente *dono){
  printf("Dono: %s\n", dono->nome);
  printf("id: %d\n", dono->id);
}

void imprime_movel(Movel *carro){
  printf("placa: %d\n", carro->placa);
  printf("ano: %d\n", carro->ano);
  printf("valor: %.2f\n", carro->valor);
}

void imprime_imovel(Imovel *casa){
  printf("Identificador: %d\n", casa->identificador);
  printf("Ano: %d\n", casa->ano);
  printf("Valor: %.2f\n", casa->valor);
}

/*Imprime os elementos da lista. Para cada elemento da lista, deve-se imprimir
  os dados do Cliente, seguido dos dados do imóvel (caso o item seja um imóvel)
  ou dos dados do automóvel (caso o item seja um movel)
* inputs: a lista
* output: nao tem
* pre-condicao: lista valida
* pos-condicao: lista inalterada
*/
void imprime (ListaHet* lista){
  ListaHet *percorre;
  for(percorre = lista ; percorre->Prox != NULL ; percorre = percorre->Prox ){
    imprime_cliente(percorre->dono);

    if(percorre->identificador_do_item == MOVEL){
      imprime_movel(percorre->item);
    }
    else{
      imprime_imovel(percorre->item);
    }

    printf("\n");

  }
  printf("\n");
}

void free_Cliente(Cliente* pessoa){
  free(pessoa->nome);
  free(pessoa);
}

void free_Movel(Movel* carro){
  free(carro);
}

void free_Imovel(Imovel* casa){
  free(casa);
}

/*Retira da lista todos os itens assegurados de um dado cliente
* inputs: a lista e o identificador do cliente
* output: lista atualizada
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista nao contem itens do cliente cujo identificador
eh id_cliente
*/
ListaHet* retira_cliente (ListaHet* lista, int id_cliente){
  ListaHet *percorre = lista, *auxiliar = NULL;
  Cliente *retirado;

  if(lista->dono == NULL){
    return lista;
  }

  while(percorre->Prox != NULL){

    if(percorre->dono->id == id_cliente){
      retirado = percorre->dono;

      if(percorre->identificador_do_item  == MOVEL){
        free_Movel(percorre->item);
      }
      else{
        free_Imovel(percorre->item);
      }

      if(auxiliar == NULL){
         lista = percorre->Prox;
         free(percorre);
         percorre = lista;
      }
      else{
         auxiliar->Prox = percorre->Prox;
         free(percorre);
         percorre = auxiliar->Prox;
      }

    }


    else{
      auxiliar = percorre;
      percorre = percorre->Prox;
    }

  }

  free_Cliente(retirado);

  return lista;
}



float valor_Movel(Movel *carro, float taxa){
  return (carro->valor * taxa);
}

float valor_Imovel(Imovel *casa, float taxa){
  return (casa->valor * taxa);
}

/*Calcula o valor total assegurado de um dado cliente (incluindo moveis e imoveis).
  Note que o valor assegurado depende da taxa estipulada para o tipo do item.
  O calculo do valor assegurado para UM dado item deve ser: valor_item*taxa_item
* inputs: a lista, o endereco do cliente, e as taxas para o calculo do valor
  assegurado.
* output: valor total assegurado, que deve ser a soma dos valores assegurados
  de todos os itens do dado cliente
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista inalterada
*/
float calcula_valor_assegurado (ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel){
  ListaHet *percorre = lista;
  float valor_total;


  while(percorre->Prox != NULL){
    //printf("%s - %s - test\n", dono->nome, percorre->dono->nome);
    if(dono->nome == percorre->dono->nome){
      if(percorre->identificador_do_item == MOVEL){
        valor_total += valor_Movel(percorre->item, taxa_movel);
      }
      else{
        valor_total += valor_Imovel(percorre->item, taxa_imovel);
      }
    }

    percorre = percorre->Prox;
  }

  return valor_total;
}
