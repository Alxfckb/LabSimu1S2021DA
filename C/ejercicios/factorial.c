/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o vector vector.c
Fecha:  Sat Apr 17 15:57:50 CST 2021
librerias:  stdio.h
resumen: Este programa encuentra el factorial de un numero entero ingresado,
utlilizando una función recursiva
entradas: Números enteros
salidas: Factorial del número ingresado
*/


//Librerías
#include <stdio.h>

//Definir n
int n;


int factorial(n){
/*Función recursiva que devuelve el factorial de un número entero */
  if(n<2)
    return 1;

  else if (n>1)

    return factorial(n-1)*n;

return n;
}

int main(void){

//Pedir un número entero
printf("Ingrese un número: ");
scanf("%d",&n);

//Calcular e impirmir elfactorial
printf("%d! = %d", n ,factorial(n));

}
