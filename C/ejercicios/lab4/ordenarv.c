/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o o ordenarv.c
Fecha:  Sat Apr 17 15:57:50 CST 2021
librerias:  stdio.h
resumen: Se solicita que el usuario ingrese 5 números enteros, se almacenan en un vector y
se imprime el vector ordenado de forma ascendente en terminal.

entradas: 5 números enteros
salidas: Un vector de longitud 5
*/


//Librería
#include <stdio.h>
//Declarar vector, entrada e iteradores
int j,i,input;
int v[5]={};

void pedir(){
/*Se piden cinco valores al usuario y se alamacenan en el vector v */
  for(i=0; i<5; i++){

    printf("Ingrese un número\n ");
    scanf("%i",&input);
    v[i]=input;
  }

}

void orden(){
/*Esta función ordena el vector que ingresa el usuario por el método de burbuja*/
  int n, aux;
//Pasada
  for (i=0; i<4; i++){

    //Navegar en el vector
    for (j=0; j<5-i-1; j++){
      //Se selecciona la posición j+1 como auxiliar
      aux=v[j+1];
      //Intercambiar posición si el elemento j+1 es menor que el elemento j
      if (v[j]>=v[j+1]){
          v[j+1]=v[j];
          v[j]=aux;
      }

    }

  }

}

void imprimir(){
/*Imprimir el vector v en terminal */
  for(i=0;i<5;i++){
    printf("%i ",v[i]);
  }
}

int main(void){

  pedir();
  printf("Vector original:\n");
  imprimir();
  orden();
  printf("\nVector ordenado:\n");
  imprimir();
}
