/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o vector vector.c
Fecha:  Sat Apr 17 15:57:50 CST 2021
librerias:  stdio.h
resumen: Se solicita que el usuario ingrese 10 números pares entre 2 y 20.
Rechaza números incorrectos y solicita otro hasta obtener uno correcto.
entradas: números pares entre 2 y 20
salidas: Un vector de longitud 10
*/



#include <stdio.h>

int v[10]={};
int input,i,j;

void pedir(){

  for(i=0; i<10; i++){

    printf("Ingrese un número par:\n ");
    scanf("%i",&input);
    if (input%2==0 && 2<=input && input<=20){

      v[i]=input;


    }else{
      printf("Número incorrecto, ingrese un número par\n");
      i--;
    }

  }
  printf("Vector original: ");
  for(i=0; i<10; i++){

      printf("%i  ",v[i]);

  }


}

void orden(){

  int n, aux;
  for (i=0; i<9; i++){

    for (j=0; j<10-i-1; j++){
      aux=v[j+1];
      if (v[j]>=v[j+1]){
          v[j+1]=v[j];
          v[j]=aux;
      }

    }

  }

  printf("Vector ordenado:\n");
  for(i=0;i<10;i++){
    printf("%i ",v[i]);
  }

}

int main(void){
pedir();
orden();

}
