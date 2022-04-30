// This is clever and it should work
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <setjmp.h>
#include <unistd.h>
typedef enum
{
    F,
    T
} boolean;

// #define after T
struct arrays
{
    char prefix[20];
    struct arrays *next;
};

struct harrays{
    char praxies[20];
    struct harrays *hnext;
};
struct arrays *head;
struct harrays *hhead;
int counter, isAfter;

char **str_split(char *a_str, const char a_delim), popPaxies();
void add(char item[20]), addSymbol(char symbol[20]), addPostfix(char postItems[20]), popPostfix();
void popSymbol();
void readAll(),readAllP();
void popAll();

int main()
{
    char text[] = "4 - [( 10 + 3 ) * ( 12 - 6 )]";
    char textChar[] = "4 - [( 10 + 3 ) * ( 12 - 6 )]";
    char string1[sizeof(text)],c[1];
    char **tokens, numX[20], numY[20];
    int d, atoiNum, makepraxies,a,b;
    struct arrays *rev;
    struct harrays *crev;
    printf("\t\t\t\t\t\t\tORIGINAL TEXT:\n\t\t\t\t\t\t%s\n\n", text);

    tokens = str_split(text, ' ');

    if (tokens)
    {
        int i = 0;
        while (*(tokens + i))
        // for (i = 0; *(tokens + i); i++)
        {
            // printf("%s\n", *(tokens + i));
            add(*(tokens + i));
            // free(*(tokens + i));
            i++;
        }
        printf("\n");
        popAll();
        printf("\n\n\t\t\t\t\t\t\tORIGINAL TEXT:\n\t\t\t\t\t\t%s\n\n", textChar);
        readAll();
        // free(tokens);
    }
    rev = head;
    if (rev == NULL)
    {
        return 0;
    }
    printf("\n \t \t \t \t*****************************************************\n");
    while (rev != NULL)
    {

        printf("\n\t\t\t\t\tPREFIX: %s", rev->prefix);
        if (makepraxies<2 && (!strcmp(rev->prefix, "*") || !strcmp(rev->prefix, "-") ||
         !strcmp(rev->prefix, "+") || !strcmp(rev->prefix, "/"))){
                addSymbol(rev->prefix);
                // popPostfix();
        }
        else if (makepraxies == 1){
            makepraxies = 0;
            a = atoi(rev->prefix);
            crev = hhead;
            if (crev == NULL)
            {
                return 0;
            }else{
                b = atoi(crev->praxies);
                popSymbol();
            }
            crev = crev->hnext;
            printf("\n\t \t \t \t \ta=%d %s b=%d", a, crev->praxies, b);
            popSymbol();
        }
        else
        {
            addSymbol(rev->prefix);
            // popPostfix();
            makepraxies += 1;
        }
        readAllP();
        sleep(1);
        rev = rev->next;
    }
    return 0;
}

void add(char item[20]){

    int isNumber, isAfter;
    int result;
    char plus[]="+", decrease[]="-", multiply[]="*", devide[]="/", *ret;
    struct arrays *pts;
    pts= malloc(sizeof(struct arrays));
    result= strcmp(item, plus);
    if (result == 0){
        isNumber = 1;
        isAfter = 1;
        addSymbol(item);
    }
    result= strcmp(item, decrease);
    if (result == 0){
        isNumber = 1;
        isAfter = 1;
        addSymbol(item);
    }
    result= strcmp(item, multiply);
    if (result == 0){
        isNumber = 1;
        isAfter = 1;
        addSymbol(item);
    }
    result= strcmp(item, devide);
    if (result == 0){
        isNumber = 1;
        isAfter = 1;
        addSymbol(item);
    }
    ret = strstr(item, "(");
    if (ret){
        isNumber = 1;
        isAfter = 0;
    }
    ret = strstr(item, ")");
    if (ret){
        isNumber = 1;
        isAfter = 0;
    }
    if(isNumber == 1){
        isNumber = 0;

    } else {
        addPostfix(item);
        if (isAfter == 1)
        {
            sleep(1);
            popSymbol();
            counter += 1;
            isAfter = 0;
            }
    }
    readAll();
    readAllP();
    sleep(2);
}
void addPostfix(char postItems[20]){
    boolean isNumber;
    struct arrays *pts;
    pts= malloc(sizeof(struct arrays));
    strcpy(pts->prefix, postItems);
    strcpy(pts->prefix, postItems);
    if (head == NULL)
    {
        pts->next = NULL;
        head = pts;
    }
    else
    {
        pts->next = head;
        //   printf("this is the next pointer %p\n",pts );
        head = pts;
        // printf("arrays size:    %lu\n", sizeof(arrays));
    }
}
void addSymbol(char symbol[20]){
    boolean isNumber;
    struct harrays *pts;
    pts= malloc(sizeof(struct harrays));
    strcpy(pts->praxies, symbol);
    // printf("praxies: %s\n", symbol);
    if (hhead == NULL)
    {
        pts->hnext = NULL;
        hhead = pts;
    }
    else
    {
        pts->hnext = hhead;
        hhead = pts;
    }
}
void popSymbol()
{
    struct harrays *dptr;
    dptr = hhead;
    if (dptr == NULL)
    {
        return;
    }
    while (dptr != NULL)
    {
        // printf("\n%s this\n", dptr->praxies);
        addPostfix(dptr->praxies);
        hhead = (hhead)->hnext;
        free(dptr);
        return;
        // prev = head;
    }
}
void popPostfix()
{
    struct arrays *hptr;
    hptr = head;
    if (hptr == NULL)
    {
        return;
    }
    while (hptr != NULL)
    {
        // printf("\n%s this\n", dptr->praxies);
        addPostfix(hptr->prefix);
        head = (head)->next;
        free(hptr);
        return;
        // prev = head;
    }
}

char  popPaxies()
{
    struct harrays *dptr;
    dptr = hhead;

    while (dptr != NULL)
    {
        // printf("\n%s this\n", dptr->praxies);
        addPostfix(dptr->praxies);
        hhead = (hhead)->hnext;
        free(dptr);
        return *dptr->praxies;
        // prev = head;
    }
}
void popAll()
{
    struct harrays *dptr;
    dptr = hhead;
    if (dptr == NULL)
    {
        return;
    }
    while (dptr != NULL)
    {
        // printf("\n%s this\n", dptr->praxies);
        sleep(1);
        addPostfix(dptr->praxies);
        hhead = (hhead)->hnext;
        free(dptr);
        // return;
        dptr = hhead;
    }
}

// void popAll()
// {
//     struct harrays *prev;
//     prev = hhead;
//     if (prev == NULL)
//     {
//         return;
//     }
//     while (prev != NULL)
//     {
//         hhead = (hhead)->hnext;

//         printf("Deleting %s\n", prev->praxies);
//         free(prev);
//         // return;
//         prev = head;
//     }
// }

void readAll(){
    struct arrays *temp;
    temp=head;
    if(temp==NULL){
        return;
    }
    printf("\n \t \t \t \t*****************************************************\n");
    while (temp!=NULL){
        printf("\n\t\t\t\t\tPREFIX: %s", temp->prefix);
        temp=temp->next;
    }
    // printf("\n \t \t \t \t*****************************************************\n");
}
void readAllP(){
    struct harrays *temp;
    temp=hhead;
    if(temp==NULL){
        return;
    }
    // printf("\n \t \t \t \t*****************************************************\n");
    while (temp!=NULL){
        printf("\t \t\tITEM: %s\n\t\t\t\t\t\t", temp->praxies);
        temp=temp->hnext;
    }
    printf("\n \t \t \t \t*****************************************************\n");
}

char **str_split(char *a_str, const char a_delim)
{
    char **result = 0;
    size_t count = 0;
    char *tmp = a_str;
    char *last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char *) * count);

    if (result)
    {
        size_t idx = 0;
        char *token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    return result;
}
