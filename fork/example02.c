#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc,int  status, char *argv[]){

   pid_t num;
    printf("Starting\n");
    printf("Original process with PID=%d, PPID=%d.\n", getpid(),getppid());

   num = fork();
   if(num!=0){
       printf("I am the parent with PID=%d, PPID=%d.\n", getpid(), getppid());

       wait(&status);
       printf("I am child with PID=%d, PPID=%d.\n", getpid(), getppid());
   }
   else
   {
    //    fork();
       printf("I am the child with PID=%d.\n", num);
       sleep(5);
   }
    // fork();
    // printf("Level 1 process with PID=%d, PPID=%d.\n", getpid(),getppid());
    // fork();
    printf("PID=%d terminates.\n", getpid());
    exit(7);
}


// void aFunc(int a) {
//     *a = 5;
// }
// int main() {
//     int b = 10;
//     afunc(&b);
//     // printf(b);
// }
