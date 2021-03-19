/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o rango rango.c
Fecha:  Thu Mar 18 11:51:09 CST 2021
librerias:  stdio.h
resumen: Este programa pide dos números enteros al usuario y devuelve los números primos que hay en ese intervalo
entradas: n1, n2 (int)
salidas: p (int)
*/
 
#include <stdio.h>

int n1, n2, p, i, j;

int es_primo(x){
/*Esta función recibe un número entero y determina si es primo
 */
    j=2;
    p=1;
    for(;;){
            
       if(j<x-1 && p==1){
            //printf("i es %d \n",i);
            if(x%j==0){
                p=0;
                j++;
            }else{
                p=1; 
                j++;
            }
        }

        else{
            if(p==0){
                //printf("nel \n");
                break;
            }else {
                //printf("yes \n");
                break;
            }
        }

    }
return p;
}

int main(){
   
   printf("Ingrese un número entero: ");
   scanf("%d", &n1);
   printf("Ingrese otro número entero: ");
   scanf("%d", &n2);
     
   printf("Los números primos entre %d y %d son: \n", n1, n2);
   for(i=n1; i<=n2; i++){
 
           if(es_primo(i)==1){
               printf("%d \n",i);
                
           }
       
       } 

    

return 0;  
} 
