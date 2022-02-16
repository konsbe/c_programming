#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int am;
    char name[20];
    char surname[20];
    struct student *next;
};
struct student *head;


void add(int am, char name[20], char surname[20]){
    struct student *pts;

    pts= malloc(sizeof(struct student));
    pts->am = am;
    printf("the pointer is : %p\n",pts);
    strcpy(pts->name,name);
    strcpy(pts->surname,surname);
    if(head==NULL){
        pts->next = NULL;
        head = pts;

    } else{
        pts->next = head;
          printf("this is the next pointer %p\n",pts );
        head = pts;
    }
}

void readAll(){
    struct student *temp;
    temp=head;
    if(temp==NULL){
        return;
    }
    printf("*****************************************************\n");
    while (temp!=NULL){
        printf("Student: %s %s, with am:%d\n", temp->name, temp->surname, temp->am);
        printf("Student: %p %p, with am:%p\n", &temp->name, &temp->surname, &temp->am);
        temp=temp->next;
    }
    printf("*****************************************************\n");
}

void deleteList()
{
    struct student *prev;
    prev= head;
    if(temp==NULL){
        return;
    }
    while (prev!=NULL)
    {
        head = (head)->next;

        // printf("Deleting %d\n", prev->data);
        free(prev);
        return;
        // prev = head;
    }
}

int main(){
  struct Student* head = NULL;
    int i,AM, num;
    char stname[20],stsurname[20];
    while(1){
        printf("1.Add Student\n");
        printf("2.Display Students\n");
        printf("3.Delete\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&i);
        if(i==1){
            printf("Enter the student's AM:");
            scanf("%d",&AM);
            printf("Enter the student's name:");
            scanf("%s",stname);
            printf("Enter the student's surname:");
            scanf("%s",stsurname);
            add(AM,stname,stsurname);
        }
        else if (i==2){
            readAll();
        }

        else if (i==3){
          deleteList();

        }
        else if (i==4){
            return 0;
        }
    }
    return 0;
}