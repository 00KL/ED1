#include "listagen.h"

//structs
typedef struct ponto Ponto;
typedef struct cg Cg;

//Callbacks
int imprime(void* /*Ponto*/, void* /*NULL*/);
int igualdade(void* /*Ponto*/ , void* /*Ponto*/);
int CentroGeom(void* /*Ponto*/, void* /*Ponto*/);

//Funções principais
void imprime_ListaGen(ListaGen *);
ListaGen* inserePonto(ListaGen*, int, int);
