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

void saveList();
void loadList();
void add(int am, char name[20], char surname[20]);
void update(int am,int newAm, char name[20], char surname[20]);
void readAll();
void deleteItem();


int main(){
//   struct Student* head = NULL;
    int i,AM, num, newAm;
    char stname[20],stsurname[20];

    while(1){
        printf("1.Add Student\n");
        printf("2.Display Students\n");
        printf("3.Delete\n");
        printf("4.Save List\n");
        printf("5.Load List\n");
        printf("6.Update\n");
        printf("7.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&i);
        switch(i){


            case 1 :
                printf("Enter the student's AM:");
                scanf("%d",&AM);
                printf("Enter the student's name:");
                scanf("%s",stname);
                printf("Enter the student's surname:");
                scanf("%s",stsurname);
                add(AM,stname,stsurname);
                break;

            case 2 :
                readAll();
                break;


            case 3 :
            deleteItem();
                break;

            case 4 :
                saveList();
                break;

            case 5 :
                loadList();
                break;

            case 6 :
                printf("Enter the student's AM you want to change:");
                scanf("%d",&AM);
                printf("Enter the student's new Am:");
                scanf("%d",&newAm);
                printf("Enter the student's name:");
                scanf("%s",stname);
                printf("Enter the student's surname:");
                scanf("%s",stsurname);
                update(AM, newAm, stname, stsurname);
                break;
            default:
                return 0;
            }
        }
    return 0;
    }


void add(int am, char name[20], char surname[20]){
    struct student *pts;

    pts= malloc(sizeof(struct student));
    pts->am = am;
    // printf("the pointer is : %p\n",pts);
    strcpy(pts->name,name);
    strcpy(pts->surname,surname);
    if(head==NULL){
        pts->next = NULL;
        head = pts;

    } else{
        pts->next = head;
        //   printf("this is the next pointer %p\n",pts );
        head = pts;
    }
}

void update(int am, int newAm, char name[20], char surname[20]){
    struct student *upts;
    upts = head;
    if (head == NULL)
    {
        printf("\n \t \t \t \t-----------------------------------\n");
        printf("\n \t \t \t \t        sorry %p not found         \n",upts );
        printf("\n \t \t \t \t-----------------------------------\n");
        return;
    }
    else
    {
        while (upts != NULL) {
            if (am == upts->am){
                upts->am = newAm;
                strcpy(upts->name,name);
                strcpy(upts->surname,surname);
                return;
            }
            upts =upts->next;
            if (upts == NULL){
                printf("\n \t \t \t \t-----------------------------------\n");
                printf("\n \t \t \t \t         sorry %p not found        \n",upts );
                printf("\n \t \t \t \t-----------------------------------\n");
            }

        }
    }
}

void readAll(){
    struct student *temp;
    temp=head;
    if(temp==NULL){
        return;
    }
    printf("\n \t \t \t \t*****************************************************\n");
    while (temp!=NULL){
        printf("\n \t \t \t \tStudent: %s %s, with am:%d\n", temp->name, temp->surname, temp->am);
        printf("\n \t \t \t \tStudent: %p %p, with am:%p\n", &temp->name, &temp->surname, &temp->am);
        temp=temp->next;
    }
    printf("\n \t \t \t \t*****************************************************\n");
}

void deleteItem()
{
    struct student *dptr;
    dptr= head;
    if(dptr==NULL){
        return;
    }
    while (dptr!=NULL)
    {
        head = (head)->next;
        // printf("Deleting %d\n", prev->data);
        free(dptr);
        return;
        // prev = head;
    }
}

void loadList(){
    head=NULL;
    FILE *fptr;
    fptr = fopen("./studentlist.txt","r");
    if(fptr==NULL){
        printf("\n \t \t \t \t-----------------------------------\n");
        printf("\n \t \t \t \tSomething went wrong with the file!\n");
        printf("\n \t \t \t \t-----------------------------------\n");
        return;
    }
    struct  student s;
    while (fread(&s,sizeof(struct student),1,fptr)){
        add(s.am,s.name,s.surname);
    }
    fclose(fptr);
    printf("\n \t \t \t \t-----------------------------------\n");
    printf("\n \t \t \t \t    Data loaded to linked list!    \n");
    printf("\n \t \t \t \t-----------------------------------\n");
}

void saveList(){
    struct student *r;
    r = head;
    if(r==NULL){
        return;
    }
    FILE *fptr;
    fptr = fopen("./studentlist.txt","wb");
    if(fptr==NULL){
        fptr = fopen( "./studentlist.txt" , "a" );
        // fptr = fopen( "./data/studentlist.txt" , "wb" );
        fwrite(r, sizeof(struct student),1,fptr);
        r = r->next;
        // printf("Something went wrong with the file!\n");
        return;
    }
    while (r!=NULL){
        fwrite(r, sizeof(struct student),1,fptr);
        r = r->next;
    }
    fclose(fptr);
    printf("\n \t \t \t \t-----------------------------------\n");
    printf("\n \t \t \t \t      List saved successfully      \n");
    printf("\n \t \t \t \t-----------------------------------\n");
}