/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o alturas alturas.c
Fecha:  Wed Mar 17 22:24:59 CST 2021
librerias:  stdio.h
resumen: Este programa lee un número indeterminado de alturas, para cuando se ingresa un numero negativo. Calcula la media, máximo y mínimo.
entradas: alturas (x)->(float)
salidas: media, max, min (todas float)
*/

#include <stdio.h>
int main(){
    //Declarar e inicializar variables
    float media=0, max=0, min=0, n=0,x, cmin;

    //Entrar a un bucle infinito 
    for(;;){

        //Pedir una altura en terminal
        printf("Ingrese una altura: ");
        scanf("%f", &x);
        
        //Contar la contribucion a la media solamente de numeros positivos
        if (x>=0){
            n++;
            media+=x;
            
            //Condicion para actualizar el máximo
            if(x>=max){
                max=x;
            }else{
                max=max;
            }
            //Tomamos como mínimo al primer número positivo ingresado
            if(n==1){
                min=x;
            }
            //Codición para actualizar el mínimmo
            if(x<=min){
                min=x;
            }else{
                min=min;
            }
        }else{
            //Imprimir la información recolectada y terminar el ciclo si detectamos un negativo
            printf("Media: %f, máximo %f, mínimo %f", media/n, max, min); 
            break;
        }
    }
return 0;
}
