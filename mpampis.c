#include <stdio.h>

#include<string.h>
struct Student {
    char am [10];
    char name [15];
    char surname [15];
    char fathers_name[15];
    char adress[30];
    char phone_number[10];
    char mobile_number [10];
    char selected_course [20];

};
 int main () {
            int size,i;
            char name[30];
            struct Student student, arr[size][30];
            printf("How many students you need?");
            scanf("%d",&size);
            for (i = 0; i < size; i++)
            {
            printf("Please insert the unique number: ");
            scanf("%s",arr[i][30].am);
            printf("Please insert your name:");
            scanf("%s",arr[i][30].name);
            }
            for(i = 0; i<size; i++){
                printf("am:%s, name:%s,\n", arr[i][30].am,arr[i][30].name);
            }
            printf("PLease type the name you are looking for.");
            scanf("%s",name);
            for(i = 0; i<size; i++ ) {
                if(strcmp( name,  arr[i][30].name ) == 0 ){
                printf("found in position: %d\n",i );
                     }
            }
return 0;
}
