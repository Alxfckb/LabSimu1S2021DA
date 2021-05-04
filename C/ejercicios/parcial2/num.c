/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.5 (clang-1205.0.22.9)
Para comilar: gcc -o num num.c
Fecha:  Sat May 1 16:03:21 CST 2021
librerias:  math.h stdio,h
resumen: Se encuentra una raiz utilizando alguno de los s métodos numéricos vistos en clase
entradas: una funcion
salidas: una raiz de la funcion
*/


//Librerías
#include <stdio.h>
#include <math.h>

// Declarar la tolerancia
float tol=0.0001;
//Prototipado de funciones
float f(float x);
float df(float x);
void nr(float x0, float tol, int maxiter, int *actiter, float *sol);

int main(void){
  /*
  Función principal, se define xs(solucion), x0(x inicial),
   el número de iteraciones y la iteración actual
  */
  float xs;
  float x0;
  int iteraciones, aiteracion;
  iteraciones=25;
  x0=2;
  //Invocamos el método de Newton-Raphson con los valores anteriores
  nr(x0,tol,iteraciones,&aiteracion,&xs);
  //Mensaje de error
  if (aiteracion==iteraciones)
    printf("Sin soluciones luego de %d iterationes",iteraciones);

  //Mensaje de éxito
  else{
    printf("Solución x= %.5f luego de %d iterationes",xs,aiteracion);
  }

}

//Función f(x)=sin(x)/x
float f(float x){

  return sin(x)/x;

}

//Derivada respecto de x de la función f
float df(float x){

  return cos(x)/x - f(x)/x;
}

//Método Newton Raphson
void nr(float x0, float tol, int maxiter, int *actiter, float *sol){
/*
  Esta función implementa el método de Newton-Raphson para encontrar
  raices de una función
*/

  //Definir variables locales
  float xant, x, dif;
  //Iterador
  int i=1;
  //x inicial
  xant=x0;

  //Identidad que nos da valores de x, cuando la parte derecha se anula encontramos una raíz
  x=xant-f(xant)/df(xant);
  //Diferencia entre x actual y x anterior
  dif=fabsf(x-xant);

//Ciclo para iterar encontar solución
  while (dif>tol && i<maxiter) {

    xant=x;
    x=xant-f(xant)/df(xant);
    //Re definimos dif, xant y x para actualizarlos con cada repetición del ciclo
    dif=fabsf(x-xant);
    //Imprimir para ver cómo se acerca x a la solución
    printf("x= %f \n", x);
    //iteramos
    i++;
  }
  //Apuntar a memoria para la solución
    *sol=x;
  //Apuntar a memoria para ver la última iteración
    *actiter=i;
}
