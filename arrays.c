#include <stdio.h>
//declare functions void
float retrieve( float p);
float update(float num1, float num2);
// float retrieve(int arr[])    //declare a function tha gets an array as argument

int main () {

   float strc_1[ 3 ]; /* array of 10 float */
   float strc_2[ 3 ]; /* array of 10 float */
   float strc_3[ 3 ]; /* array of 10 float */
   float *p1;
   float *p2;
   float num1;
   float num2;
   int i;


   for (i = 0; i < 3; i++)
   {
       printf("enter value for array_1[%d] --> ", i);
       scanf("%f", &    strc_1[i]);
       printf("enter value for array_2[%d] --> ", i);
       scanf("%f", &    strc_2[i]);
   }

   for (i = 0; i < 3; i++)
   {
       p1 = &strc_1[i];
       num1 = retrieve( *p1);
       printf("value is -->%f +", strc_1[i]);
       p2 = &strc_1[i];
       num2 = retrieve(  *p2);
       printf("value is -->%f ,", strc_2[i]);
    //    printf("pointer is -->%f\n =", *p2);
       strc_3[i] = update(num1, num2);
       printf("value is -->%f \n", strc_3[i]);
   }

   return 0;
}
float retrieve(float p)
{

    float pointer;
    pointer = p;
    // printf("pointer from function -->%p\n =", &pointer);
    // printf("value of the pointer  -->%f\n =", pointer);
    return pointer;
}

float update(float val1,float val2)
{
    float sum;
    sum = val1 + val2;
    return sum;
}

// int retrieve(int arr[]) // This is the return type (void means no value is computed and returned by the function!)
// {
//     int i;
//     for (i = 0; i < 10; i++)
//     {
//         printf("enter value for array_1[%d] --> %d/n", i, arr[i]);

//     }
//     return 0;
// }
