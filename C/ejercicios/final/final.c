/*
Autor:  alexanderalvarado
Complilador:  Apple clang version 12.0.0 (clang-1200.0.32.29)
Para comilar: gcc -o final final.c
Fecha:  Thu May 13 10:06:51 CST 2021
librerias:  stdio.h, math.h
resumen: Examen final
entradas: --
salidas: archivo de texto con tiempos, posición y velocidad
*/

#include <stdio.h>
#include <math.h>

//Definir constantes
float t=0;  //tiempo
float G=6.693E-11, rt=6.378E6, mt=5.9736E24, L=6.5E-3; //constante de gravitación, radio de la tierra, masa de la tierra y constante térmica de la atmosfera
float R=287.06;   //Constante de los gases
float g=9.81;    //gravedad en la superficie de la tierra
float T0=288.15;  //temperatura al nivel del mar
int P0=101325;    //presión al nivel del mar
float delta=0.1; //Incremento del tiempo;

//Prototipos
float mc(float tsfc,float e0,float m0, float mf0,float t);
float mf(float tsfc, float e0,float mf0,float t);
float gy(float y);
float fa(float y, float cd, float a);
float den(float y);
float et(float tsfc, float e0,float mf0,float t);
void ficha(char name[10], float e0, float tsfc, float cd, float a, float m0, float mf0);
void gas(char name[10],float e0, float tsfc, float cd, float a, float m0, float mf0);
void graf(float e0, float tsfc, float cd, float a, float m0, float mf0);


int main(void){
    //Información del cohete 1
    ficha("Ah Mun",3E7, 3.248E-4, 61.27, 201.06,1.1E5, 1.5E6);
    gas("Ah Mun",3E7, 3.248E-4, 61.27, 201.06,1.1E5, 1.5E6);
    printf("\n");

    //Información del cohete 2
    ficha("Ahau Kin",2.7E7, 2.248E-4, 61.27, 201.06,1.1E5, 1.5E6);
    gas("Ahau Kin",2.7E7, 2.248E-4, 61.27, 201.06,1.1E5, 1.5E6);
    printf("\n");

    //Información del cohete 3
    ficha("Chac",2.5E7, 2.248E-4, 70.25, 215,1.8E5, 2.1E6);
    gas("Chac",2.5E7, 2.248E-4, 70.25, 215,1.8E5, 2.1E6);
    printf("\n");

}

//Masa final
float mf(float tsfc, float e0,float mf0,float t){
  /* Masa final calculadada integrando dmf, se le agrega mf0 puesto que al integrar
  sale una constante, es la masa inicial de combustible de cada cohete */
  return -tsfc*e0*t+mf0;
}

//Masa del cohete
float mc(float tsfc,float e0,float m0,float mf0, float t){
/*Masa total del cohete dependiendo del tiempo*/
  return m0+mf(tsfc,e0,mf0,t);
}

//Propulsión del cohete
float et(float tsfc, float e0,float mf0,float t){
  /*Función por partes de la propulsión del cohete */
  if (mf(tsfc,e0,mf0,t)>0){
    return e0;
  }else{
    return 0;
  }
}

//gravedad dependiente de altura
float gy(float y){
/*Gravedad en función de la altura*/
  return G*mt/pow((rt + y),2);
}

//Densidad dependiente de altura
float den(float y){
  /*Densidad del airde en función de la altura de vuelo*/
  // Condición para cuando y < T0/L
  if (y < T0/L){
  //Retornar la densidad
  return P0/(R*T0) * pow((1 - L*y/T0 ),g/(R*L));
  }
  // rho=0 para y > T0/L
  else {
    //Retornar la densidad
    return 0;
  }
return 0;
}

//fricción en función
float fr(float y, float cd,float a,float v){
  /* Fricción modelada tomando en cuenta la densidad del aire, coeficiente de forma,
   área transversal, aceleración y el módulo de la aceleracion */
  return 0.5*den(y)*cd*a*v* fabsf(v);
}

//Función para imprimir información sobre el cohete
void ficha(char name[10], float e0, float tsfc, float cd, float a, float m0, float mf0){
  printf("--------------------------------------------------------\n");
  printf("Nombre del Cohete: %s\n",name);
  printf("--------------------------------------------------------\n");
  printf("Empuje del Cohete: %f [N]\n",e0);
  printf("Consumo especifico del empuje TSFC: %f [kg/Ns]\n",tsfc);
  printf("Coeficiente de forma CD: %.2f \n",cd);
  printf("Sección transversal del cohete A: %.2f [m^2]\n",a);
  printf("Masa del propulsor m0: %.2f  [kg]\n",m0);
  printf("Masa inicial del combustible mf0: %.2f [kg] \n",mf0);
  printf("--------------------------------------------------------\n");
}

//Función que nos indica en qué momento nos quedamos sin combustible
void gas(char name[10],float e0, float tsfc, float cd, float a, float m0, float mf0){
  /*Esta función automatiza los cálculos para el cohete que nosotros le pidamos,
   tomando como argumento su nombre y sus características*/

   //Nos interesa saber qué sucede con el cohete mientras y>=0
   float y=55E-2; //altura inicial para los cohetes;
   float v=0;
   float ac=0;
   t=0;
   while(mf(tsfc,e0,mf0,t)>0){
     t+=delta;
     ac+=(et(tsfc,e0,mf0,t)-fr(y,cd,a,v))/mc(tsfc,e0,m0,mf0,t)-gy(y) ;
     v+=ac*t;
     y+=v*t;

    }
    printf("El cohete %s se quedó sin combustible en t=%.2f s\n",name,t);
    printf("Altura máxima en y=%.2fm\n",y);
}

//NO CORRER ESTA FUNCIÓN
void graf(float e0, float tsfc, float cd, float a, float m0, float mf0){
/*No correr, hay un bucle infinito xd*/
  FILE *file;
  file=fopen("xt.txt","wt");
  float y=55E-2; //altura inicial para los cohetes;
  float v=0;
  float ac;
  t=0;

  while(mf(tsfc,e0,mf0,t)>0){
      t+=delta;
      ac+=(et(tsfc,e0,mf0,t)-fr(y,cd,a,v))/mc(tsfc,e0,m0,mf0,t)-gy(y);
      v+=ac*t;
      y+=v*t;
      fprintf(file, "%.2f %.2f\n",y,t);
    }

  while(y>0){
    t+=delta;
    ac+= -fr(y,cd,a,v)/m0 -gy(y);
    v+=ac*t;
    y+=v*t;
    fprintf(file, "%.2f %.2f\n",y,t);
  }
  fclose(file);
}
