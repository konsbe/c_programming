/*
we have an array
A(1:2,1:3,3:3,1:2)
with limits up and down:
l1=1 u1=3
l2=1 u2=2
l3=3 u3=3
l4=1 u4=3
foundation andress b=100 and length component L=6

addr(A[i,j,k,z])=c0 +c1*i +c2*j +c3*k +cd*z

where:

 cd=L <=> cd=6
 c(j-1)=(u(j)-l(j)+1)*cj
 c0=b-c1*l1-c2*l2-...-cd*ld
we have a 2 dimension array with l1=1 u1=1 , l2=2 u2=3
*/
#include<stdio.h>
int c(int j);
int addr(int l1, int l2, int l3, int l4);
int main(){
  int count = 1;
  for (int l2 = 1; l2 < 4; l2++)
  {
    for (int l1 = 1; l1 < 3; l1++)
    {
      for (int l3 = 3; l3 < 4; l3++)
      {
        for (int l4 = 1; l4 < 4; l4++)
        {
          printf("%d: adrr(A[%i,%i,%i,%i])= c(0)+c(1)*l1+c(2)*l2+c(3)*l3+c(4)*l4= %i+%i*%i+%i*%i+%i*%i+%i*%i= %i\n", count, l1, l2, l3, l4, c(0), c(1), l1, c(2), l2, c(3), l3, c(4), l4, addr(l1, l2, l3, l4));
          count += 1;
        }
      }
    }
  }
}


int c(int j){
  int l[5]={0,1,1,3,1}, u[5]={0,2,3,3,2};
  switch(j){
  case 4 :
    return 6;

  case 0:
    return 100-c(1)*l[1]-c(2)*l[2]-c(3)*l[3]-c(4)*l[4];

  default:
    return (u[j+1]-l[j+1]+1)*c(j+1);

  }
}

int addr(int l1, int l2, int l3, int l4){
  return c(0)+c(1)*l1+c(2)*l2+c(3)*l3+c(4)*l4;
}