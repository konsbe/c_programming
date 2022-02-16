#include <stdio.h>
#include <stdlib.h>
// #define size 10


void push(int size, int stiva, int top), pop(int size, int stiva, int top), display(int i,int stiva, int top);

//------------------------- Main ---------------------------
int main()
{
int i;
int choice;
    int top;
    int size;
    int stiva[size];
    printf ("Give a size for your stack:");
    scanf ("%d", &size);

    printf ("Array like stack\n\n");
	top = -1; // this means an empty stack =-1
	do
	{
		printf("1. Input\n2. Delete\n3. Situation\n4. Exit\n\n");
		printf("What you like ?");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			push(size,*stiva,top);
			break;
		case 2:
			pop(size, *stiva,top);
			break;
		case 3:
			display(i,*stiva,top);
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Give a correct value!\n");
			break;
		}
	} while(choice!=4);
	return 0;
}

//------------------------ Push ----------------------------
void push(int size, int stiva, int top)
{
    int position = top + 1;
    int element;
    if(top == size-1)
	{
		printf("Overfitting\n");
	}
	else
	{
		printf("Give a value as an input to the stack:");
		scanf("%d", &element);
		// top++;
		// stiva[position]=element;
	}
}
//------------------------- Pop -----------------------------
void pop(int size, int stiva, int top)
{
	int element;
	if(top == -1)
	{
		printf("Overfitting\n");
	}
	else
	{
		element=stiva[&top];
		printf("You just delete: %d",stiva[&top]);
		printf("\n");
		top--; // Delete
	}
}
//------------------------- Show Contents ---------------------------
void display(int i,int stiva, int top)
{
	if(top == -1)
	{
		printf("Empty stack\n"); // Adeia Lista
	}
	else if(top >= 0)
	{
		printf("The items of the stack is:\n");
		for(i = top; i >= 0; i--)
		{
			printf("%d\n",stiva[&i]);
		}
	}
}