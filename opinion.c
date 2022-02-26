#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct covidList{
    char fullName[40];
    int age;
    char sex[10];
    char covidType[50];
    char birthday[50];
    struct covidList *next;
};

struct covidList *head;

void insertCovid( int age,char fullName[40], char sex[10], char covidType[50], char birthday[50]);
void readAll();
void readLength();
void exit();

int main(){
    int choice, a;
    char fName[40], sx[10], cType[50], bday[50];
    while (1)
    {
        printf("1. to insert\n");
        printf("2. to check the number of sick\n");
        printf("3. to print all sick people\n");
        printf("4. to exit\n");
        printf("Whats your choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter age:");
                scanf("%d", &a);
                printf("Enter fname:");
                scanf("%s", fName);
                printf("Enter sex:");
                scanf("%s", sx);
                printf("Enter cType:");
                scanf("%s", cType);
                printf("Enter birthDay:");
                scanf("%s", bday);
                insertCovid(a, fName, sx, cType, bday);
                break;
            case 2:
                readLength();
                break;
            case 3:
                readAll();
                break;
            case 4:
                return 0;
                break;
            default:
                printf("\n \t \t-----------------------------------");
                printf("\n \t \tSorry wrong answer i will terminate");
                printf("\n \t \t-----------------------------------\n");
                return 0;
            }
    }
    return 0;

};

void insertCovid(int age, char fullName[40], char sex[10], char covidType[50], char birthday[50]){
    printf("choice 1\n");
    struct covidList *pts;
    pts = malloc(sizeof(struct covidList));
    strcpy(pts->fullName, fullName);
    strcpy(pts->sex, sex);
    strcpy(pts->birthday, birthday);
    pts->age = age;
    if(head == NULL){
        pts->next = NULL;
        head = pts;
    } else {
        pts->next = head;
        head = pts;
    }
}
void readLength(){
    int counter = 0;
    struct covidList *ptr;
    ptr = head;
    while(ptr!=NULL){
        counter += 1;
        ptr = ptr->next;
    }
    printf("%d people with covid", counter);
}
void readAll(){
    struct covidList *temp;
    int counter = 0;
    temp = head;
    while(temp!=NULL){
        counter += 1;
        printf("%d.%s\n", counter, temp->fullName);
        temp = temp->next;

    }
}
