#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif
#include <stdio.h>
#define OMEGA "\u03a9"

float retrieve(float S[], int i);
float update(float c1, float c2, int i);

int main()
{       
        int i;
        float c1, c2, A[10], B[10], C[10];

      	system("clear");
        for(i=0;i<10;i++)
        {       
                printf("[Δώσε τιμή της συνιστώσας B[%d]: ",i);
                c1=retrieve(B,i);
                printf(" Δώσε τιμή της συνιστώσας C[%d]: ",i);
                c2=retrieve(C,i);
                printf(" %.2f  %.2f\n",c1,c2);
                A[i]=update(B[i],C[i]);

        }
        
        for(i=0;i<10;i++) printf("Αποτέλεσμα αθροίσματος συνιστώσας A[%d]=%.2f\n",i, A[i]);
        
        system("pause");
        return 0;
}

float retrieve(float S[], int i)
{
        float c;
        scanf("%f",&S[i]);
        c=S[i];
        return(c);
}


float update(float c1, float c2)
{
        return c1 + c2;    
}

