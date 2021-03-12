/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o operadores operadores.c
Fecha:  Fri Mar 12 11:10:33 CST 2021
librerias: 
resumen:                            Ejemplo de cómo utilizar operadores
entradas:
salidas:
*/

#include <stdio.h>

//definicion de constantes
enum boolean {False, True};
//Declaracion e inicializacion de variables globales
int x, y, res; 

int main(){
    //cambiamos valor de las variables 
    x=2;
    y=3;
    printf("valor de x = %d, valor de y= %d \n",x,y);
    //operaciones normales + - * / %
    res = x + y;
    printf("resultado = %d, %d, %d \n",res,x,y);
    //suma utilizando la misma variable
    x+=y;
    printf("resultado suma: %d, %d \n",x,y);
    x=2;
    //resta usandola misma variable
    x-=y;
    printf("resultado resta %d, %d \n", x,y);
    x=2;
    x*=x;
    printf("x*x = %d \n",x);
    x=2;
    x/=y;
    printf("x/y: %d \n", x);
    x=2;
    x%=y;
    printf("x mod y = %d",x);
return 0;
}
