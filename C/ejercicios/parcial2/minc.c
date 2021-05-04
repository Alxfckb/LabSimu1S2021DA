/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.5 (clang-1205.0.22.9)
Para comilar: gcc -o minc minc.c
Fecha:  Sat May 1 12:01:56 CST 2021
librerias:  stdio.h y math.h
Resumen: Este programa implementa el método de mínimos cuadrados para resolver
un problema del segundo examen parcial
Entradas: datos x , datos y
Salidas: Una ecuación lineal
*/


//Librerías
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Iterador
int i;
/*
float v[]={54.3,61.8,72.4,88.7,118.6,194.0};
float p[]={61.2,49.2,37.6,28.4, 11,10.2};
*/
//Vector con Log(x[i])
float x[]={3.994524,4.123903,4.282207,4.485260,4.775756,5.267858 };
//Vector con Log(x[i])
float y[]={4.114147,3.895894, 3.627004,3.346389,2.954910,2.322388};
//Longitud de los vectores
int n = sizeof(x)/sizeof(x[0]);


//Prototipos
float XY(float x1[], float x2[]);
float X1(float x1[]);
float M();
float B();
void graphics();

int main(){
/*
Función principal, muestra la mejor aproximación y
  transcribe los datos a un archivo de texto
*/
  printf("La mejor aproximación está dada por y = %f x + %f\n", M(),B());
  graphics();
  printf("La presión para V=100 in3 es %.2f lb/in^3",exp(B())/pow(100,-M()) );
return 0;
}

//Sum x_i*y_i
float XY(float x1[], float x2[]){
  /*Esta función hace la sumatoria de x_i*y_i */
  //variable local
  float sum2=0;

    for(i=0; i<n; i++){

      sum2+=x1[i]*x2[i];
    }
    //retornar suma
  return sum2;
}
//Sum x_i
float X1(float x1[]){
  /*Esta función suma todos los valores en una lista x1[]*/
  //variable local
    float sum=0;
    for (i=0; i<n; i++){
      sum+=x1[i];
      //printf("j= %d %f, x= %f \n", j,sum, x1[j]);
    }
    //returnar suma
    return sum;
}

//Calcular m
float M(){
  /*Esta función calcula la pendiente usando la fórmula vista en clase*/

  //variable local
  float m;

  m = ( n*XY(x,y) - X1(x)*X1(y)) / (n*XY(x,x) - pow(X1(x),2) );
  //retornar pendiente
  return m;
}

//Calcular b
float B(){
  /*Esta función calcula el intercepto utiliando la fórmula vista en clase*/
  float b;
  b=(X1(y)-M()*X1(x))/n;
//Retornar intercepto
return b;
}
//Graficar
void graphics(){
/*Esta función escribe un archivo de texto que se utilizará para
 graficar los resultados obtenidos*/
  FILE * data;
  //Abrir archivo en modo escritura
  data = fopen("data.txt", "w");

  //Imprimir la forma de la ecuación
  fprintf(data, "y=%fx+%f \n",M(),B());

  //Imprimir columnas X Y en el archivo de texto
  for (i=0; i<n; i++){
    fprintf(data, "%f %f \n",x[i],y[i]);
  }
  //cerrar archivo
  fclose(data);
  //Ejecutar el archivo de gnuplot
  system("gnuplot -p graph.gp");
}
