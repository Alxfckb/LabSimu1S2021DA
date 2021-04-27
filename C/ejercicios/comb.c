#include <stdio.h>
#include <math.h>

int ind[3][2]={{1,2},{0,2},{0,1}};
int x[3]={};
int i,j;
int a[3]={6,3,7};
int b[3]={9,4,3};
int det;
int mat[3][3]={{2,1,5},{6,3,7},{9,4,3}};



void cruz(){

    for(i=0;i<3;i++){
      x[i]=pow(-1,i)*(a[ind[i][0]]*b[ind[i][1]]-a[ind[i][1]]*b[ind[i][0]]);

  }
for (i=0;i<3;i++){
  printf("%d ", x[i]);
}

}


void determinante(){

  for(i=0;i<3;i++){

      det+=mat[0][i]*pow(-1,i)*(mat[1][ind[i][0]]*mat[2][ind[i][1]]- mat[1][ind[i][1]]*mat[2][ind[i][0]]);


  }

printf("Determinante %d", det);

}

int main(void){

  cruz();
  determinante();
}
