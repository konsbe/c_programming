#include <stdio.h>

int main(){
    int size;
    int arr[size];

    printf("input size of array ");
    scanf("%d",&size);
    printf("array size is: %d\n", size);

    for(int i=0;i<size;i++){
        printf("input array[%d] --> ", i);
        scanf("%d",&arr[i]);
    }
    printf("\nThe array  is :\n");
    for(int i=0;i<size;i++){
        printf("array[%d]: %d\n",i,arr[i]);
    }


    return 0;
}
