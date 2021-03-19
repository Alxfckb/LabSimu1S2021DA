/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o root root.c
Fecha:  Thu Mar 18 00:33:01 CST 2021
librerias:  stdio.h
resumen: Este programa calcula la raiz cuadrada entera de un número ingresado por el usuario
entradas: n (int)
salidas: r (int)
*/
 
#include <stdio.h> 

//Declaramos las variables n, r e inicializamos nuestro iterador
int n, r, i=1;

int main(){
     printf("Este programa calcula la raíz cuadrada del número que usted ingrese \ningrese un número entero: ");
     scanf("%d", &n);
     
     //Entramos a un loop infinito
     for(;;){
        //Condición para determinar si i es raiz cuadrada
        if(i*i==n){
            printf("La raiz cuadrada es %d", i);
            break;
        }else{
            //Iterar si i no es raiz
            i++;

            //Terminar el ciclo si i>n
            if (i>n){
                break;
            }
        }
        
    }

return 0;
}
 
