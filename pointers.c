#include <stdio.h>
#include <string.h>
//struct
struct Student {
    char am [10];
    char name [15];
    char surname [15];
};
// pointers who points a value

// struct *Student;
//

// student.am;


int main () {

     struct Student student;
    struct Student *pointerS;


    int foo1 = 1;
    //  what is a pointer ?
    // integer <- of pointer <- value = position in memory
    int *foo = &foo1; //hex




    printf("value --> %d and the position in memory --> %p\n", *foo, foo);
    printf("\n");
    printf("\nLets check what happens in array\n");
    printf("\n");



    int arr[4]={1,2,3,4};
    printf("\n");
    printf("\nthe pointer of the array is stored in memory in place%p\n", arr);
    printf("\n");
    printf("\nthe pointer of an array holds the value of the %d argument\n", *arr);
    printf("\n");
    // array with two values
    for (int i = 0; i < 4; i++){
        //position of memory for each value of the array
        printf("the position in memory of the arr[%d] is --> %p\n",i, arr + i);
    }
    printf("\nconclusion pointers in memory have diffrent of 4 bytes the one from another\n");
    printf("\n");

    for (int i = 0; i < 2; i++){
        //accessing each value the array from a pointer
        printf("the value of a pointer\"%p\" is -->%d\n", arr + i ,*(arr+i));
                                                                // arr[i]
    }



    //structures
    strcpy(student.am, "mmp2312");
    strcpy(student.name , "kostas");
    strcpy(student.surname, "mplimplikos");
    printf("name \"%s\" am\"%s\" surname\"%s\" \n", student.name,student.am, student.surname);
    printf("\n");
    printf("\nLets check what happens in a struct that has been located in place: %p\n", pointerS);
    printf("\n");
    printf("\nthe pointer of a struct holds the value of the first parameter\n");
    printf("\n");
    printf("am position in memory \"%p\"\n", pointerS->am);
    printf("name position in memory \"%p\"\n", pointerS->name);
    printf("surname position in memory \"%p\"\n", pointerS->surname);
    // passing the values to pointer
    pointerS = &student;
    printf("surname position in memory \"%s\"\n", pointerS->am);
                                                    // student.am
    printf("surname position in memory \"%s\"\n", pointerS->name);
    printf("surname position in memory \"%s\"\n", pointerS->surname);
    printf("\nconclusion pointers in memory have diffrent of 4 bytes the one from another\n");



    return 0;
 }