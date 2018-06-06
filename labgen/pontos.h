#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listagen.h"

typedef struct ponto Ponto;

//Callbacks
void imprime(Ponto, int);
int igualdade(Ponto, Ponto);
void CentroGeom(Ponto, Ponto);

//Funções principais
void imprime_ListaGen(ListaGen *);
typedef struct cg Cg;
