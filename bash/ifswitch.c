/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o ifswitch ifswitch.c
Fecha:  Fri Mar 12 11:52:19 CST 2021
librerias: 
resumen:                                    Ejemplo del uso de if y switch
entradas:
salidas:
*/
#include <stdio.h>

int main(void){
    //Declaro variables locales
    char letra;
    int x;
    printf("Ingrese una vocal: ");
    letra = getchar();
    printf("vocal es: %c \n", letra);
    
    if (letra == 'a'){
        printf("vocal es %c \n", letra);    
    }
    printf("ingrese un valor de 0 a 5: ");
    scanf("%d",&x);
    if (x > 3){
        printf("el valor es mayor \n");
    }else{
        printf("el valor es menor \n");
    }
    (x==2)? printf("el valor es 2 \n"): printf("es cualquier otro valor \n");
    
    if (x!=0){
        if (x>1){
            printf("hola");
        }else{
            printf("%d \n ",x);
        }

    if (x >= 0 && x<=3){
        printf("%d \n",x);
    }else if(x==4) {
        printf("es igual a 4 \n ";)
    }else if (x>4){
        printf("es mayor \n");
    }
    }
}
