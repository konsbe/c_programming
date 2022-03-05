#include "stdio.h"

int retrieve(int x);
void update(int y);

int main(){
    int k = 4; /* define the arrays */
    int l;
    l = retrieve(k);
    update(k);
    printf("%d",l);

  return 0;
}

int  retrieve(int x){
    // print(k);
    printf("%d\n", x);
    return x+2;
  }

void update(int y){
  printf("%d\n", y);
  return;
}
