/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "matriz.h"






//Tipo matriz (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct matriz{
    int n;
    int m;
    int **mat;
} matriz;

/*Inicializa uma matriz de nlinhas e ncolunas
* inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
* output: ponteiro para a matriz inicializada
* pre-condicao: nlinhas e ncolunas diferentes de 0
* pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas  
*/
Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    int i;
    
    matriz *matriz = (matriz *)malloc(sizeof(matriz)); 
    matriz->n = nlinhas;
    matriz->m = ncolunas;
    
    matriz->mat = (int **)malloc(matriz->n * (int *));
    
    for(i = 0; i < matriz->n; i++ ){
        
        matriz->mat[i] = (int *)malloc(matriz->m * sizeof(int));
 
    }
    
    return matriz;
    
}

/*Modifica o elemento [linha][coluna] da matriz mat
* inputs: a matriz, a linha, a coluna, e o novo elemento
* output: nenhum
* pre-condicao: matriz mat existe, linha e coluna são válidos na matriz
* pos-condicao: elemento [linha][coluna] da matriz modificado
*/
void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->mat[linha][coluna] = elem;
}

/*Retorna o elemento mat[linha][coluna]
* inputs: a matriz, a linha e a coluna
* output: elemento mat[linha][coluna]
* pre-condicao: matriz mat existe, linha e coluna são válidos na matriz
* pos-condicao: mat não é modificada
*/
int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->mat[linha][coluna];
}

/*Retorna o número de colunas da matriz mat
* inputs: a matriz
* output: o número de colunas da matriz
* pre-condicao: matriz mat existe
* pos-condicao: mat não é modificada
*/
int recuperaNColunas (Matriz* mat){
    return mat->m;
}

/*Retorna o número de linhas da matriz mat
* inputs: a matriz
* output: o número de linhas da matriz
* pre-condicao: matriz mat existe
* pos-condicao: mat não é modificada
*/
int recuperaNLinhas (Matriz* mat){
    return mat->n;
}

/*Retorna a matriz transposta de mat
* inputs: a matriz
* output: a matriz transposta
* pre-condicao: matriz mat existe
* pos-condicao: mat não é modificada e matriz transposta existe
*/
Matriz* transposta (Matriz* mat){
    int i, j;
    
    matriz *matriz = (matriz *)malloc(sizeof(matriz)); 
    matriz->n = mat->m;
    matriz->m = mat->n;
    
    matriz->mat = (int **)malloc(matriz->m * (int *));
    
    for(i = 0; i < matriz->m; i++ ){
        
        matriz->mat[i] = (int *)malloc(matriz->n * sizeof(int));
 
    }
    
    for(i = 0; i < matriz->n; i++ ){
        
        for(j = 0; j < matriz->m; j++){
            matriz->mat[i][j] = mat->[j][i];

        }
    }
    
    return matriz;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
* inputs: as matrizes mat1 e mat2
* output: a matriz multiplicação
* pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 
* correponde ao numero de linhas de mat2 
* pos-condicao: mat1 e mat2 não são modificadas e a matriz multiplicacao existe
*/
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    
    //Criacao matriz multiplicacao
    int i, j, x, aux = 0;
    
    matriz *multi = inicializaMatriz ( mat1->n , mat2->m);
    
    //Multiplicacao
    for(i = 0; i < multi->n; i++){
        
        for(j = 0; j< multi->m; j++){
            
            //codigo para receber resultado em aux AQUI
            
            multi->mat[i][j] = aux;
        }
        
    }
   
    
    
    
    
    return multi;
    
    
}

/*Imprime a matriz
* inputs: matriz mat
* output: nenhum
* pre-condicao: matriz mat existe  
* pos-condicao: nenhuma
*/
void imprimeMatriz(Matriz* mat){
    
    int i, j;
    
    printf("\n\n");
    
    for(i = 0; i < matriz->n; i++ ){
        
        for(j = 0; j < matriz->m; j++){
            printf("%d  ", mat->mat[i][j]); 
        }
        
        printf("\n");
    }
    
    printf("\n\n");
}


/*Libera memória alocada para a matriz
* inputs: matriz mat
* output: nenhum
* pre-condicao: matriz mat existe  
* pos-condicao: toda a memória alocada para matriz foi liberada
*/
void destroiMatriz(Matriz* mat){
    int i;
    
    
    for(i = 0; i < matriz->n; i++ ){
        
        free(mat->mat[i]);
        
    }
    
    free(mat->mat);
    
    free(mat);
}
