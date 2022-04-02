#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <setjmp.h>
#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(100)
#define THROW longjmp(ex_buf__, 1)
#define size 100
#define OMEGA "\u03a9"

int top;
int i;
int choice;
int stiva[size];
void pushPostfix(char character);
void pushHelpArray(char character);
char **str_split(char *a_str, const char a_delim);

int main()
{
    char text[] = "40 - [( 10 + 3 ) x ( 12 - 6 )]";
    char **tokens, numX[20], numY[20];
    int d;
    printf("ORIGINAL TEXT:\n%s\n\n", text);

    tokens = str_split(text, ' ');

    if (tokens)
    {
        int i = 0;
        while (*(tokens + i))
        // for (i = 0; *(tokens + i); i++)
        {
            printf("%s\n", *(tokens + i));
            // free(*(tokens + i));
            i++;
        }
        printf("\n");
        // free(tokens);
    }
    i = 0;
    while (*(tokens + i))
    {
            TRY
            {
                sprintf(numX, "%s", *(tokens + i));
                printf("%s\n", *(tokens + i));
                d = 0;
                while (d < 100)
                {
                    sprintf(numY, "%d", d);
                    if (numX[0] == numY[0])
                    {
                        pushPostfix(numX[0]);
                    }
                    d++;
                }
                // free(*(tokens + i));
                i++;
            }
                // THROW;
                printf("I do not appear\n");
            CATCH
            {
                printf("Got Exception!\n");
            }
            ETRY;
    }
    return 0;
}

void pushPostfix(char character)
{
	int element;
	if(top == size-1)
	{
		printf("Overfitting postfix\n");
	}
	else
	{
		printf("pushPostfix");
		scanf("%d", &element);
		printf("\n");
		top++;
		stiva[top]=element;
	}
}

void pushHelpArray(char character)
{
	int element;
	if(top == size-1)
	{
		printf("Overfitting help Array\n");
	}
	else
	{
		printf("pushHelpArray");
		scanf("%d", &element);
		printf("\n");
		top++;
		stiva[top]=element;
	}
}

void popHelpArray()
{
	int element;
	if(top == -1)
	{
		printf("Είναι ήδη κενή η στοίβα\n");
	}
	else
	{
		element=stiva[top];
		printf("Διαγράφηκε το: %d\n",stiva[top]);
		top--; // Διαγραφή
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