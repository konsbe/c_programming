#include "stdio.h"

float retrieve(float arr[], float c ,int i);
float update(float arr[], float c, int i);

int main(){
  float A[10],B[10],C[10]; /* define the arrays */
  
  for(int i=0;i<10;i++){
    A[i]=retrieve(C,C[i],i);
    A[i]=update(A,B[i],i);
    printf("A[%d]=%f\n",i,A[i]);
  }
  return 0;
}

float retrieve(float arr[], float c, int i){
  c=arr[i];
  return c;
  }

float update(float arr[], float c, int i){
  arr[i]=arr[i]+c;
  return arr[i];
}
