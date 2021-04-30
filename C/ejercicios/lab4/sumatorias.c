/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o s sumatorias.c
Fecha:  Sat Apr 17 15:57:50 CST 2021
librerias:  stdio.h
resumen: se solicita al usuario un número entero que servirá de límite superior para cuatro sumatorias.
Se mostrará el resultado de las sumatorias en terminal.

entradas: un número entero
salidas: Cuatro flotantes
*/

//Librerías
#include<stdio.h>
#include <math.h>

//Declarar iterador, límite superior y variables donde se almacenará el valor de las sumatorias.
int i,n;
float s1;
float s2;
float s3;
float s4;

void pedir(){

  printf("Ingrese un número entero");
  scanf("%i",&n);

}
float a(int n){
  //Sumatoria a)
  for (i=1; i<n+1;i++){
      s1+=pow(i,2)*(i-3);
  }
  //Devolver el valor de la sumatoria
  return s1;
}

float b(int n){
//Sumatoria b)
  for (i=2;i<n+1;i++){
    s2+=3/(i-1);
  }
  //Devolver el valor de la sumatoria
  return s2;
}
float c(int n){
  //Sumatoria c)
  for (i=1; i<n+1;i++){
      s3+= (1/sqrt(5))* pow(((1+sqrt(5))/2),i) - (1/sqrt(5))*pow(((1-sqrt(5))/2),i);
  }
  //Devolver el valor de la sumatoria
  return s3;
}

float d(int n){
  //Sumatoria d)
  for(i=2;i<n+1;i++){
    s4+=0.1*(3*pow(2,i-2)+4);
  }
  //Devolver el valor de la sumatoria
  return s4;
}

int main(void){

  pedir();
  printf("S1 = %.2f \n", a(n));
  printf("S2 = %.2f \n", b(n));
  printf("S3 = %.2f \n", c(n));
  printf("S4 = %.2f \n", d(n));

}
