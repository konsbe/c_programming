#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
//
int main () {

    int size;
    printf("how many students you need? --> ");
    scanf("%d",&size);
    struct Student student, arr_st[size][30];
    char arr_course[size][size*30];
    // int (*ptr)[size];
    char str[size][50], givenSubj[30];

    printf("array is arr[%d][30]\n", size);
    for (int i = 0; i < size; i++)
    {

        printf("Please insert the unique number: ");
        scanf("%s", arr_st[i][30].am);
        printf("Please insert your name: ");
        scanf("%s", arr_st[i][30].name);
        printf("Please insert your surname:");
        scanf("%s",arr_st[i][30].surname);
        printf("Please insert your futhers name:");
        scanf("%s",arr_st[i][30].fathers_name);
        printf("Please insert your adress:");
        scanf("%s",arr_st[i][30].adress);
        printf("Please insert your phone number:");
        scanf("%s",arr_st[i][30].phone_number);
        printf("Please insert your mobile number:");
        scanf("%s",arr_st[i][30].mobile_number);
        printf("Please insert the course he/she selects: ");
        scanf("%s", arr_st[i][30].selected_course);
    }

    printf("which subject you are looking for? --> ");
    scanf("%s", givenSubj);

    for (int i = 0; i < size; i++)
    {

        if(strcmp( givenSubj,  arr_st[i][30].selected_course ) == 0 ){
               printf("found in position: %d\n",i );
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("Position %d student: %s \n",i,arr_st[i][30].name);
    }



    return 0;

 }
