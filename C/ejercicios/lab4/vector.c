/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o vector vector.c
Fecha:  Sat Apr 17 15:57:50 CST 2021
librerias:  stdio.h
resumen: Se solicita al usuario que ingrese 5 números enteros. Estos se
almacenarán en un vector y al terminar de ingresar los números, se mostrará el vector ordenado de forma ascendente en terminal.

entradas: cinco números enteros
salidas: Un vector de longitud 5
*/



#include <stdio.h>

int v[10]={};
int input,i,j;
char opcion;
void imprimir(){

  for(i=0;i<10;i++){
    printf("%i ",v[i]);
  }
}
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
}

void ascendente(){
/*Ordena de forma ascendente por método de burbuja*/
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

}

void descendente(){
  /*Ordena de forma descendente por método de burbuja*/
  int n, aux;
  for (i=0; i<9; i++){

    for (j=0; j<10-i-1; j++){
      aux=v[j+1];
      if (v[j]<=v[j+1]){
          v[j+1]=v[j];
          v[j]=aux;
      }

    }

  }

}


int main(void){

   pedir();

  while( opcion!='a' && opcion!='b'){
    printf("Opciones:\na. Mostrar de forma ascendente\nb. Mostrar de forma descendente\n");
    scanf("%c",&opcion);

  }

 if (opcion=='a'){


   printf("Vector original: \n");
   imprimir();
   printf("\n");
   printf("Vector ordenado de forma ascendente: \n");
   ascendente();
   imprimir();

 }else if(opcion=='b'){


   printf("Vector original: \n");
   imprimir();
   printf("\n");
   printf("Vector ordenado de forma descendente: \n");
   descendente();
   imprimir();

 }

}
