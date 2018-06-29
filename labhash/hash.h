#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPAL 64 //tamanho em caracteres de uma palavra
#define MAXTAB 127 //tamanho maximo da tabela hash

typedef struct palavra palavra;
typedef palavra* hash[MAXTAB];

//texto* inicializa_hash(texto*);
void inicializa_hash(hash);
int gera_indice(char*);
int le_palavra(FILE*, char* );
palavra *acessa(hash , char*);
void imprime_crescente(palavra **);
void free_palavras(hash);
