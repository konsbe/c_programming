#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100
#define OMEGA "\u03a9"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

typedef enum {false, true} bool;
int top, ctop;
int i;
int choice;
char stiva[size];
int marks[size];

void push(char character),pop(), status();
int mathFunc(int element);
void pushNum(int number);

//------------------------ Push ----------------------------




//------------------------- Main ---------------------------
int main()
{
	printf ("Πίνακας μορφής στοίβας\n");
	bool booly = false;
	char string[] = "4 - [(10+3) x (12-6)]";
	char str[] = " ";
	char numY[20], numX[20], numZ[20];
	top = -1;
	ctop = -1;
	int element;
	while (string[i] != '\0')
	{
		if (string[i] != str[0]){
			for (int j=0; j<10;j++){
				sprintf(numY, "%d", j);
			 	if (string[i] == numY[0]){
					int d = 0;
					while (d<100){
						sprintf(numX, "%d", d);
							if (string[i+1] == numX[0]){
								// printf("%s \n", strcat(numY,numX));
								pushNum(atoi(strcat(numY, numX)));
								i = i + 2;
								// int count = 0;
								// while (count < 10){
								// 	sprintf(numZ, "%d", count);
								// 		if (string[i+1] == numZ[0]){
								// 		pushNum(atoi(strcat(numY, numX))+ atoi(numZ));
								// 		}
								// 	count++;
								// }
								booly = false;
								d=9;
							}else{
								booly = true;
							}
							d++;
					}
				// d = 0;
				// 	while (d<10){
				// 		sprintf(numX, "%d", d);
				// 			if (string[i-2] == numX[0]){
				// 				booly = false;

				// 			}
				// 			d++;
				// 	}
					if (booly == true)
							{
								// printf("%s \n", numY);
								pushNum(atoi(numY));
								booly = false;
							}
				}
			}
		if (string[i] == '+' || string[i] == '-' || string[i] == '/' || string[i] == 'x' || string[i] == '(' || string[i] == ')' || string[i] == '[' || string[i] == ']' ){
			push(string[i]);
		}
		}
		i++;
    }
		for (int j=top; j>=0;j=j-1){
			printf("%c \n", stiva[j]);
		}
		printf("--------------------------------------\n");
		for (int j = ctop+1; j >=0; j=j-1)
		{
			printf("%d \n", marks[j-1]-marks[j]);
		}
	return 0;
}

void push(char character)
{
	if(top == size-1)
	{
		printf("Υπερχείλιση\n");
	}
	else
	{
		top++;
		stiva[top] = character;
		printf("%c others\n", stiva[top]);
		// sleep(1);
	}
}

void pushNum(int number)
{
	if(ctop == size-1)
	{
		printf("Υπερχείλιση\n");
	}
	else
	{

		ctop++;
		marks[ctop] = number;
		printf("%d nums\n", marks[ctop]);
		// sleep(1);

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
		element=marks[top];
		printf("Διαγράφηκε το: %d\n",marks[top]);
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
