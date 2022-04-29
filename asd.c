// This is clever and it should work
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <setjmp.h>
#define TRY                    \
    do                         \
    {                          \
        jmp_buf ex_buf__;      \
        if (!setjmp(ex_buf__)) \
        {
#define CATCH \
    }         \
    else      \
    {
#define ETRY \
    }        \
    }        \
    while (100)
#define THROW longjmp(ex_buf__, 1)
#define size 100
#define OMEGA "\u03a9"

int top;
int i;
int choice;
int stiva[size];
void pushPostfix(char character);
char **str_split(char *a_str, const char a_delim);

struct list1
{
    int am;
    char name[20];
    char sex[20];
    int age;
    struct list1 *next;
};
struct list1 *head;
void add(int am, char name[20], char sex[20]);

int main()
{
    char text[] = "4 - [( 10 + 3 ) x ( 12 - 6 )]";
    char string1[sizeof(text)];
    char **tokens, numX[20], numY[20];
    int d, atoiNum;
    printf("ORIGINAL TEXT:\n%s\n\n", text);

    tokens = str_split(text, ' ');

    if (tokens)
    {
        int i = 0;
        while (*(tokens + i))
        // for (i = 0; *(tokens + i); i++)
        {
            printf("%s\n", *(tokens + i));
            // numX = *(tokens + i);
            strncat(string1, (*(tokens + i)), 1);
            // free(*(tokens + i));
            i++;
        }
        printf("\n");
        // free(tokens);
    }
    printf("%s", string1);
    return 0;
}

void pushPostfix(char character)
{
    int element;
    if (top == size - 1)
    {
        printf("Overfitting postfix\n");
    }
    else
    {
        printf("pushPostfix");
        printf("\n");
        top++;
        stiva[top] = character;
        printf("%c", stiva[top]);
    }
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
