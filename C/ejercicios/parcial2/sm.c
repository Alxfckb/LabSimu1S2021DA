#include <stdio.h>

int main(void){
  int i;
  int v[3]={1,2,3};
  float sum;
  for (i=0; i<3; i++){

    sum+=v[i];

  }
  printf("sum %f", sum);
}
