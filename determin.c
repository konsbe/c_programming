#include "stdio.h"
#include "string.h"
#include <unistd.h>
//dilwsh N-thesewn 50
#define N 50

//dilwsh synwnymwn me vash thn ekfwnhsh

#define lparenth '('
#define rparenth ')'

//ypodiknyei thn arxh ths stoivas
#define ISYMBOL '!'

//dilwsh stoivas me megethos N
char stack[N];

//arxikopoihsh adeias stoivas
int top = -1;

//apothikeyei string pou eisagei o xrhsths
char eisodos[N];

//synwnimo gia to char
typedef char element;

//prwtotypa synarthsewn

void push_element(element simvolosira);
void pop_element();
element get_top();
void stack_empty();
void displayStack();

void main () {

  int i=0;

  printf("Please enter a string for examination for blocking parenthesis :\n");
  scanf("%s", eisodos);
  push_element(ISYMBOL);


	//elegxos an teleivnei to string
	while(eisodos[i]!='\0')
	{
	  //vasi ekfwnhshs ginontai oi aparaithth elegxoi kai oi antistoixes energeies
	  if(eisodos[i]==lparenth)
	  {
	    push_element(lparenth);
		  	printf("K1 push %c\n", eisodos[i]);
			displayStack();
			sleep(1);
	  }

	  else if (eisodos[i]==rparenth)
	  {
	    pop_element();
			printf("K2 pop %c\n", eisodos[i]);
			displayStack();
			sleep(1);
	  }

	  else
	  {
		  printf("Invalid input, pop %c\n", eisodos[i]);
	  }
	i++;
  }

	//elegxei an exei meinei to "!" petaei mynhma nai alliws minima oxi
  	if(get_top()==ISYMBOL)
  	{
   		printf("K3 YES\n");
    }

  	else
    {
    	printf("NO\n");
    }

 }

//synarthsh pou kanei push stoixeio sthn stoiva
void push_element(element simvolosira)
{
	if(top==N-1)
	{
		printf("push_element: The stack is full\n");
	}
	else
	{
		top++;
		stack[top]=simvolosira;
	}

}

//synarthsh pou vgazei stoixeio apo thn stoiva
void pop_element()
{
	if(top==-1)
	{
		printf("pop_element: Error-Stack empty\n");
	}

	else
		top--;
}

// Epistrefei to top stoixeio ths stoivas
element get_top()
{
	return stack[top];
}

// elegxow an stoiva einai adeia
void stack_empty()
{
	if(top==-1)
	printf("The stack is empty");
}

// ektposi ths stoivas
void displayStack()
{
	int i;

	for(i=0; i<=top; i++)
	{
		printf("%c", stack[i]);
	}

	printf("\n");
}


