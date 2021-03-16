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
    float x=0, media=0;
    int i=0, n=0;
    printf("Calcula la media aritmética \n");

    while(i<3){
        printf("Ingrese un número real: ");
        scanf("%f", &x);
        if (x >= 0){
            n++;
            media+=x;
        }
        i++;
    }
    if (n==0){
        printf("los valores eran negativos");
    }else{
        printf("La media aritmética es: %.2f ",media/n);
    }

return 0;
}
