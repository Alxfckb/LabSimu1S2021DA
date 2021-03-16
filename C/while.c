#include <stdio.h>


int main(){

    int contador = 0;
    while(contador<10){
        printf("%d", contador);
        contador++;
    }
    printf("\n");
    do{
        printf("%d, ", contador);
        contador--;
    }while(contador!=0);
    printf("\n");
return 0;
}
