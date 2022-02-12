#include <stdio.h>
#include <math.h>

//declare functions void
int doubleVal( float k);


int main () {
    float val4;
    float val1;
    float val2;
    float val3;
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Your name is %s.", name);
   val1 = 10;
   val3 = 20;
       printf("my val is %f:\n", val1);

   val2 = doubleVal(val1);

   val4 = doubleVal(val3);

   return 0;
}

int doubleVal(float k ){
    float p;
    p = sqrt(9.0);

    printf("variable p become %.15f:\n", p);
    return p;
}

//     float pointer;
//     pointer = p;
//     printf("pointer from function -->%p\n =", &pointer);
//     printf("value of the pointer  -->%f\n =", pointer);
//     return pointer;
// }



