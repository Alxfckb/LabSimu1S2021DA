/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o m mat.c
Fecha:  Sat Apr 17 15:57:50 CST 2021
librerias:  stdio.h
resumen: Se solicitan al usuario llenar dos matrices y se hacen las siguientes operaciones
a) matriz A por una constante
b) suma de matrices
c) resta de matrices
d)multiplicación de matrices
e) determiabte de la matriz a
f) transpuesta de la matriz A
g) inversa de la matriz A
salidas: Un vector de longitud 10
*/

//Librerías
#include <stdio.h>
#include <math.h>

//Declarar arreglos a utilizar y variables
int ind[3][2]={{1,2},{0,2},{0,1}};
int matA[3][3]={};
int matB[3][3]={};
int tmatB[3][3]={};
int sum[3][3]={};
int multi[3][3]={};
int aMatA[3][3]={};
int det;


int i, j,n,ent;

void pedir(){
  /*
  Esta función pide al usuario llenar la matriz A y la matriz B
  */
  printf("Ingrese la matriz A\n");
  for(i=0; i<3;i++){
    for(j=0; j<3;j++){
      scanf("%d",&ent);
        matA[i][j]=ent;
    }
  }

    printf("Ingrese la matriz b\n");

  for(i=0; i<3;i++){
    for(j=0; j<3;j++){
      scanf("%d",&ent);
        matB[i][j]=ent;
    }
  }
}

void printmat(int a[3][3]){

  /* Esta función recibe una matriz de 3x3 y la imprime en terminañ */
  for(i=0; i<3;i++){
    for(j=0; j<3;j++){

        printf("%d ",a[i][j]);
    }
    printf("\n");
  }


}

void esc(){
/*Esta escala la matriz A por un factor de 3 */
  for(i=0; i<3;i++){
    for(j=0; j<3;j++){
      aMatA[i][j]= 3* matA[i][j];
    }
  }

}

void suma(){
  /*
  Esta función hace la suma de dos matrices
  */
  for(i=0; i<3;i++){
    for(j=0; j<3;j++){
      sum[i][j]=matA[i][j]+matB[i][j];
    }
  }
}

void prod(){
/*
Esta función calcula la multiplicación de dos matrices, basada en la fórmula
 dada por índices  c_ij=Sum n_0^3 a_in * b_nj */
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      for(n=0;n<3;n++){

          multi[i][j]+=matA[i][n]*matB[n][j];
      }
    }
  }

}

void tras(){
  /*
  Esta función calcula la traspuesta de una matriz*/
  for(i=0; i<3;i++){
    for(j=0; j<3;j++){
      tmatB[i][j]=matB[j][i];
    }
  }
}

void determinante(){
/*Esta función calcula el determinante de la matriz A, por medio de cofactores.
Para matrices 3x3 es casi un producto cruz.*/
  for(i=0;i<3;i++){

      det+=matA[0][i]*pow(-1,i)*(matA[1][ind[i][0]]*matA[2][ind[i][1]]- matA[1][ind[i][1]]*matA[2][ind[i][0]]);
    }
    printf("%d", det);
}

int main(void){
  pedir();
  printf("Matriz A: \n");
  printmat(matA);
  printf("\n");

  printf("Matriz B: \n");
  printmat(matB);
  printf("\n");

  printf("Matriz 3*A: \n");
  esc();
  printmat(aMatA);
  printf("\n");

  printf("Matriz A+B: \n");
  suma();
  printmat(sum);
  printf("\n");

  printf("Matriz AxB: \n");
  prod();
  printmat(multi);
  printf("\n");
  printf("Matriz B^T: \n");
  tras();
  printmat(tmatB);
  printf("\n");
  printf("Det(matriz A): \n");
  determinante();

}
