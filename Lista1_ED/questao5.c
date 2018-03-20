#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
    
    char **vetorString = (char **)malloc(5 * sizeof(char *) );
    int i;

    for(i = 0; i < 5; i++){
        *(vetorString + i) = (char *)malloc(69 * sizeof(char));
    }

    for(i = 0;  i < 5; i++){
        scanf("%[^\n]s" , *(vetorString + i) );
        setbuf(stdin, NULL);
    }

    printf("\n\n");

    for(i = 0; i < 5; i++){
        printf("%s\n", *(vetorString + i) );
    }

    printf("\n\n");
}
    