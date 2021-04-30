/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o c coordenandas.c
Fecha:  Sat Apr 17 15:57:50 CST 2021
librerias:  stdio.h
resumen: Se solicita al usuario dos posiciones en coordenadas (x,y,z). Al obtenerlas debe de
almacenarlas en dos vectores, el programa automaticamente debe de mostrar la magnitud de cada vector,
la suma de los vectores, el productor escalar y el producto vectorial.

salidas: impresiones en terminal
*/


//librerías a utilizar
#include <stdio.h>
#include <math.h>
//Declarar iterador, variables para almacenar resultados y vectores para almacenar la información del usuario
int i;
int ind[3][2]={{1,2},{0,2},{0,1}};
float coor,tam,tam2,punto,sum;
float v1[3]={};
float v2[3]={};
float v3[3]={};
float cruz[3]={};


void pedir(){
  /*
  Función que pide coordenadas (x,y,z) al usuario
  y las almacena en los vectores v1 y v2
  */

  puts("Ingrese coordenadas x,y,z para el vector 1: ");
  for (i=0;i<3;i++){
    scanf("%f",&coor);
    v1[i]=coor;
  }

  puts("Ingrese coordenadas x,y,z para el vector 2: \n");
  for (i=0;i<3;i++){
    scanf("%f",&coor);
    v2[i]=coor;
  }

}


void mag(){
/*
Función que calcula la magnitud de los vectores v1 y v2 e imprime estos valores
en terminal
*/
  for(i=0;i<3;i++){

    tam+=v1[i]*v1[i];
    tam2+=v2[i]*v2[i];
  }

  printf("Tamaño del vector 1: %f\n",sqrt(tam));
  printf("Tamaño del vector 2: %f",sqrt(tam2));
}

void dot(){
/*
  Función que calcula el producto punto entre v1 y v2 e imprime el resultado
*/
  for(i=0;i<3;i++){
    punto+=v1[i]*v2[i];
  }
  printf("\nEl producto punto entre v1 y v2 es: %f", punto);
}

void suma(){
/*
  Función que realiza la suma entre coordenadas y las almacena en un
  nuevo vector que será impreso en terminal
*/
  for(i=0;i<3;i++){
    v3[i]=v1[i]+v2[i];
  }

  printf("\nEl vector suma es: ");
  printf("[");
  for(i=0;i<3;i++){

    printf("%.2f ", v3[i]);
    printf(",");

  }
  printf("]");
}


void vect(){
/*
Función que calcula el producto cruz entre dos vectores, almacena el resultado
 en un nuevo vector y se imprime en terminal
*/
    for(i=0;i<3;i++){
      cruz[i]=pow(-1,i)*(v1[ind[i][0]]*v2[ind[i][1]]-v1[ind[i][1]]*v2[ind[i][0]]);

  }
  printf("\nEl producto vectorial es: ");
  printf("[");
  for(i=0;i<3;i++){

    printf("%.2f ", cruz[i]);
    printf(",");

  }
  printf("]");
}



int main(void){
  pedir();
  mag();
  dot();
  suma();
  vect();
}
