#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc,int  status, char *argv[]){

   pid_t num, c;
   int process;
   printf("Starting\n");
   printf("Original process P0 with PID=%d, PPID=%d.\n", getpid(), getppid());

   num = fork();
   if(num!=0){
       printf("P2 process with PID=%d, PPID=%d.\n", getpid(), getppid());
       process = 2;
       wait(&status);
       c = fork();
       if (c != 0)
       {
           printf("P3 process with PID=%d, PPID=%d.\n", getpid(), getppid());
           process = 3;
            printf("P5 process with PID=%d, PPID=%d.\n", getpid(), getppid());
           process = 5;

           wait(&status);
       }
       else
       {
           //    fork();
           printf("P4 process with PID=%d, PPID=%d.\n", getpid(), getppid());
           process = 4;

           wait(&status);
        sleep(2);
       }
   }
   else
   {
    //    fork();
        printf("P1 process with PID=%d, PPID=%d.\n", getpid(), getppid());
        process = 1;

        wait(&status);
        sleep(2);
   }
    // fork();
    // printf("Level 1 process with PID=%d, PPID=%d.\n", getpid(),getppid());
    // fork();
    printf("P%d: PID=%d terminates.\n",process, getpid());
    exit(7);
    printf(" PID=%d terminates.\n", getpid());
}


// void aFunc(int a) {
//     *a = 5;
// }
// int main() {
//     int b = 10;
//     afunc(&b);
//     // printf(b);
// }
