/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o media media.c
Fecha:  Tue Mar 16 12:25:28 CST 2021
librerias: stdio.h
resumen: se obtienen 3 valores de entrada, verifica que sean positivos y realiza la media aritmetica de los valores positivos
entradas: x (numeros reales obtenidos en terminal)
salidas:  media (media aritmética calculada en el programa)
*/

#include <stdio.h>
int main(){

    float x=0, media=0, max, min;                                   //Declarar e inicializar x(entrada de usuario) y media (media aritmética)
    int i=0, n=0;                                                   //Declarar e inicializar iterador i y contador n
   
    printf("Calcula la media aritmética \n");
    
    
    while(i<3){
        //pedir tres numeros reales en terminal
        printf("Ingrese un número real: ");
        scanf("%f", &x);                                            
        min=x;
        max=x;

        if(x>=max){
            max=x;

        }else {
            max=max;  
        }
       
       
        //Determinar maximos y minimos
        

       
        //Calculo de media y conteo
        if (x >= 0){
            //Contar cuantos positivos hay
            n++;                                                   
            //Agregar a la media si son positivos
            media+=x;                                               
        }
        //Iterar para repetir el ciclo
        i++;                                                       
    }

    if (n==0){
        //Indicar al usuario que todos los numeros ingresados son negativos
        printf("los valores eran negativos \n ");                       
    }else{
        //Imprimir media
        printf("La media aritmética es: %.2f ",media/n);            
   
        // Imprimir máximo y mínimo
        printf("el máximo es %f y el mínimo es %f \n",max,min);
    } 
return 0;
}
