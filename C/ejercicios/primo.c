/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o primo primo.c
Fecha:  Thu Mar 18 00:56:27 CST 2021
librerias:  stdio.h
resumen: Este programa lee un número mayor que 1 y determina si es primo.
entradas: n
salidas: primo, no primo (str)
*/
 
//Declarar variable de entrada, iterador e indicador de primos encontrados
int n, i=2, p=1; 

#include <stdio.h>
int main(){

    //Pedir un número en terminal
    printf("Ingrese un número entero: ");
    scanf("%d",&n);

    //Verificar que sea mayor que 1
    if (n>1){
    
        //Loop infinito para encontrar divisores del número ingresado
        for(;;){
            

            if(i<n-1 && p==1){
               
               //Si es divisor de n 
               if(n%i==0){
                   p=0;
                   i++;

               }else{
                   i++;

               }
            }

            else{
                if(p==0){
        
                    printf("No es primo");
                    break;
                }else{
                    printf("Es primo");
                    break;
                }
            }

        }
    }

return 0;
}
 
