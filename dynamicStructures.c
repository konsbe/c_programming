#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//dilwse
struct Student {
    char am [10];
    char name [15];
    // char surname [15];
    // char fathers_name[15];
    // char adress[30];
    // char phone_number[10];
    // char mobile_number [10];
    char selected_course [20];

};

int main () {

    int size;
    struct Student student, arr_st[size][30], *pointerS;
    char arr_course[size][size*30];
    int bool = 0;
    int (*ptr)[size];
    char str[size][50], givenSubj[30];



    printf("how many students you need? --> ");

    scanf("%d",&size);
    printf("array is arr[%d][30]\n", size);
    for (int i = 0; i < size; i++)
    {

        printf("Please insert the unique number: ");
        scanf("%s", arr_st[i][30].am);
        printf("Please insert your name: ");
        scanf("%s", arr_st[i][30].name);
        printf("Please insert the course he/she selects: ");
        scanf("%s", arr_st[i][30].selected_course);
        // printf("%p\n",  &arr_st[i][30].selected_course);

        sprintf(str[i], "%p", &arr_st[i][30].selected_course);

        printf("%d: %s\n",i,arr_course[i]);
        // printf("%s\n", arr_course);
        // strcpy(arr_st[i], arr_st[i][30].selected_course);
        // arr_course[size][30] = arr_st[i][30].selected_course + i;
        // printf("Please insert your surname:");
        // scanf("%s",arr_st[i][30].surname);
        // printf("Please insert your futhers name:");
        // scanf("%s",arr_st[i][30].fathers_name);
        // printf("Please insert your adress:");
        // scanf("%s",arr_st[i][30].adress);
        // printf("Please insert your mobile number:");
        // scanf("%ls",arr_st[i][30].mobile_number);
        // printf("Please insert your phone number:");
        // scanf("%s",arr_st[i][30].phone_number);
    }

    printf("which subject you are looking for? --> ");
    scanf("%s", givenSubj);

    for (int i = 0; i < size; i++)
    {
        printf("%d --> pointer with arrow: %p\n", i, arr_st[i]);

        if(strcmp( givenSubj,  arr_st[i][30].selected_course ) == 0 ){
               printf("found in position: %d\n",i );
        }
        printf("%d --> pointers: %p\n", i, &arr_st[i][30].name);
        printf("%d --> pointers: %p\n", i, &arr_st[i][30].am);
        printf("%d --> pointers: %p\n", i, &arr_st[i][30].selected_course);
        printf("%d --> pointers: %s\n", i, arr_st[i][30].selected_course);
        }

    for (int i = 0; i < size; i++)
        {
            printf("pointers value is: %ls\n",ptr[i]);
            printf("selected courses is: %s\n",(arr_course[i]));
            printf("%d --> %s\n",i, arr_course[i]);
        }


return 0;

 }
    // for (int i = 0; i < size; i++)
        // {
            // printf("student: %d with name: %s with am: %s and selected course: %s\n", i, arr_st[i][30].name, arr_st[i][30].am,arr_st[i][30].selected_course);
        // }




// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// #define ROW 5
// #define COL 10

// int main(void)
// {
//     int i, j;
//     char a[ROW][COL] = {"string1", "string2", "string3", "string4", "string5"};
//     char *b[ROW];

//     for (i=0 ; i<5; i++) {
//         if ((b[i] = malloc(sizeof(char) * COL)) == NULL) {
//             printf("unable to allocate memory \n");
//             return -1;
//         }
//     }

//     strcpy(b[0], "string1");
//     strcpy(b[1], "string2");
//     strcpy(b[2], "string3");
//     strcpy(b[3], "string4");
//     strcpy(b[4], "string5");


//     char (*ptr1)[COL] = a;
//     printf("Contents of first array \n");
//     for (i=0; i<ROW; i++)
//         printf("%s \n", *ptr1++);
//         printf("%p \n", ptr1++);


//     char **ptr2 = b;
//     printf("Contents of second array \n");
//     for (i=0; i<ROW; i++)
//         printf("%s \n", ptr2[i]);

//     /* b should be free'd */
//     for (i=0 ; i<5; i++)
//         free(b[i]);

//     return 0;
// }