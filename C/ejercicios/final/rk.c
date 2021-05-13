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
#include <math.h>

//Prototipo
float f(float t, float y);
float df(float t, float y);
float ptay(float t, float y, float h);
float nmt(float a, float b, float n);

int main(void){
  float a=0, b=2;
  int n;
  n=50;
  printf("El valor es %.2f",nmt(a,b,n));

}
// f(t)
float f(float t, float y){
  float res=0;
  res = y - pow (t,2) + 1;

return res;
}
float df(float t, float y){
  float res=0;
  res = f(t,y) - 2*t;

return res;
}
//Polinomio de Taylor
float ptay(float t, float y, float h){
  float res=0;
  res = f(t,y)+h/2 * df(t,y) ;

return res;
}
//Método numérico de Taylor
float nmt(float a, float b, float n){
  float h, t, w=0, y;
  h=(b-a)/n;
  t = a;
  y = 0.5;

  for (int i=0; i<n; i++){
    w+=h*ptay(t,y,h);
    t+=h;
    y+=w;
  }
return y;
}
