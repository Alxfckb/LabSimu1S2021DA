/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o fibo fibo.c
Fecha:  Fri Mar 19 12:21:58 CST 2021
librerias: 
resumen:
entradas:
salidas:
*/
 
 

#include <stdio.h>
long fibo(int n);

int main(){

    int n,k;
    do{

        printf("introducir el valor de n: ");
        scanf("%d",&n);

    }while(n<=1);
    puts("Serie fibonacci \n");
    printf("1");
    
    for (k=2; k<=n; k++){
        
        printf("%ld %s", fibo(k), (k %7==0 ? "\n": "") );

    }
return 0;
}
 
long fibo(int n){

    if(n==0 || n==1)
        return n;
    else 
        return fibo(n-2)+fibo(n-1);
}


