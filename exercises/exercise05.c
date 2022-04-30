#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int am;
    char name[20];
    char sex[20];
    int age;
    struct student *next;
};
struct student *head;

void saveList();
void loadList();
void add(int am, char name[20], char sex[20]);
void update(int am,int newAm, char name[20], char sex[20]);
void readAll();
void deleteItem();

int main(){


    int i,AM, num, newAm, counter;
    char stname[20],stsex[20];
    struct student *students = (struct student*)malloc(100 * sizeof(students));
    int age;

    while (1)
    {
        printf("1.Add Student\n");
        printf("2.Display Students\n");
        printf("3.Delete\n");
        printf("4.Save List\n");
        printf("5.Load List\n");
        printf("6.Update\n");
        printf("7.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&i);
        if (i!=1 && i!=2 && i!=3 && i!=4 && i!=5 && i!=6 && i!=7){
            i = 2;
        }
        switch (i)
        {

        case 1:
            printf("Enter the student's AM:");
            scanf("%d", &AM);
            printf("Enter the student's name:");
            scanf("%s", stname);
            printf("Enter the student's sex:");
            scanf("%s", stsex);
            printf("Enter the student's age:");
            scanf("%d", &age);
            add(AM, stname, stsex);
            students[counter].am = head->am;
            counter += 1;
            break;

        case 2:
            readAll();
            printf("studen 0: %d\n", students[counter-1].am);
            break;

        case 3:
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
                printf("Enter the student's sex:");
                scanf("%s",stsex);
                printf("Enter his/her sex:");
                scanf("%d", &age);
                update(AM, newAm, stname, stsex);
                break;
            default:
                return 0;
            }
    }
    return 0;
    }


void add(int am, char name[20], char sex[20]){
    struct student *pts;

    pts= malloc(sizeof(struct student));
    pts->am = am;
    // printf("the pointer is : %p\n",pts);
    strcpy(pts->name,name);
    strcpy(pts->sex,sex);
    if(head==NULL){
        pts->next = NULL;
        head = pts;
        // printf("student size: %lu\n", sizeof(student));


    } else{
        pts->next = head;
        //   printf("this is the next pointer %p\n",pts );
        head = pts;
        // printf("student size:    %lu\n", sizeof(student));

    }
}

void update(int am, int newAm, char name[20], char sex[20]){
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
                strcpy(upts->sex,sex);
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
        printf("\n \t \t \t \tStudent: %s %s, with am:%d\n", temp->name, temp->sex, temp->am);
        printf("\n \t \t \t \tStudent: %p %p, with am:%p\n", &temp->name, &temp->sex, &temp->am);
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
        add(s.am,s.name,s.sex);
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



