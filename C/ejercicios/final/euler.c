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

float df(float A, float k, float h);

int main(void){
    float area=1, k=0.1,h=10, t=0, delta=0.1;
    FILE *pf;
    pf = fopen("altura.txt","wt");
    while (h>=0){

      //Validar el valor de la altura en t=3
      if(round(t)==3.0){
        printf("\n la altura en %f es: %f", t,h);
      }

       //Añadir valores al archivo
       fprintf(pf, "%.2f\t%.2f\n",t,h);
       //Ejecutar el método numérico
       h+=delta*df(area,k,h);
       t+=delta;


    }
    //Ingresar el ultimo valor del archivo
     fprintf(pf, "%.2f\t%.2f\n",t,h);
     //Cerrar archivo
     fclose(pf);
     printf("\n El tiempo cuando h=0 es de %.2f",t);
}

float df(float A, float K,float h){

    float res;
    res = - K*sqrt(h)/A;
return res;
}
