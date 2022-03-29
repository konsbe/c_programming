#include <stdio.h>
#include <stdlib.h>
#define size 10
#define OMEGA "\u03a9"

int top;
int i;
int choice;
int stiva[size];

//------------------------ Push ----------------------------
void push()
{
	int element;
	if(top == size-1)
	{
		printf("Υπερχείλιση\n");
	}
	else
	{
		printf("Δώσε τιμή για γέμισμα της στοίβας:");
		scanf("%d", &element);
		printf("\n");
		top++;
		stiva[top]=element;
	}
}
//------------------------- Pop -----------------------------
void pop()
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
//------------------------- Show Contents ---------------------------
void status()
{
	if(top == -1)
	{
		printf("Κενή στοίβα\n"); // Adeia Lista
	}
	else if(top >= 0)
	{
		printf("Τα στοιχεία της στοίβας:\n");
		for(i = top; i >= 0; i--)
		{
			printf(" - %d\n",stiva[i]);
		}
		printf("\n");
	}
}

//------------------------- Main ---------------------------
int main()
{
	printf ("Πίνακας μορφής στοίβας\n");
	top = -1; // Αρχικοποίηση της top =-1 που σημαίνει άδεια στοίβα
	do
	{
		printf("1. Εκχώρηση\n2. Διαγραφή\n3. Κατάσταση\n4. Έξοδος\n");
		printf("Τι θα θέλατε ;");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			status();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Δώσε έγκυρη επιλογή!\n\n");
			break;
		}
	} while(choice!=4);
	return 0;
}
