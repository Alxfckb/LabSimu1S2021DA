/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o calculadora calculadora.c
Fecha:  Tue Apr 6 11:15:18 CST 2021
librerias:  stdio.h
resumen: Calculadora del examen corto
entradas: enteros entre 0 y 4 para seleccionar el modo de la calculadora
salidas: enteros, resultados de la operación
*/
#include <stdio.h>

float a,b;

//Función que suma dos números
int suma(x,y){
float resultado;

    resultado=a+b;

printf("Resultado: %f \n", resultado);
return 0;
}

//Función que resta dos números
int resta(x,y){
float dif;

    dif=a-b;

printf("Diferencia: %f \n", dif);
return 0;
}

//Función que multiplica dos números
int multiplicacion(x,y){
float producto;

    producto=a*b;

printf("Producto: %f \n", producto);
return 0;
}

//Función que divide dos números
int division(x,y){

float cociente;
//caso de divisor=0
if (b!=0){
    cociente=a/b;
    printf("Cociente: %f \n", cociente);
  }else {
    printf("No se puede dividir entre cero");
  }

return 0;
}

//Función principal
int  main(void){
int n;

do{
  //Elegir una operación
  printf("\nIngrese una opcion \n");
  printf("0. Salir \n1. Suma a+b \n2. Resta a-b \n3. Multiplica aXb \n4. Divide a/b\n");

  scanf("%d", &n);
  if (n==0){
    break;
  }
  //Pedir a y b
  printf("\nIngrese a \n");
  scanf("%f", &a);
  printf("Ingrese b \n");
  scanf("%f", &b);

  //Elegir qué operación hacer
switch (n){
  //Caso suma
  case 1:
    suma(a,b);
    break;
  //Caso resta
  case 2:
    resta(a,b);
    break;
  //Caso multiplicación
  case 3:
    multiplicacion(a,b);
    break;
  //Caso división
  case 4:
    division(a,b);
    break;
}
} while (n!=0);
return 0;
}
