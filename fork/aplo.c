#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    system ("clear");
    int i,process ;
    pid_t pid0,pid1,pid4,pid5,childb1,childb2,pid3;
    printf("\n \t \t I am the parent process with ID %d \n",getpid());
    process = 0;
    pid0 = fork();
    if (pid0 == 0)
        {
            printf("\nP1: with ID %d and my parent ID is %d\n",getpid(),getppid());
            process = 1;
            printf("\nP2: with ID %d and my parent ID is %d\n",getpid(),getppid());
        }else{
            pid1 = fork();
            if (pid1 == 0)
            {
                    pid3 = fork();
                if (pid3 != 0)
                {
                    printf("\nP3: with ID %d and my parent ID is %d\n",getpid(),getppid());
                    process = 3;
                    printf("P%d: PID=%d terminates.\n",process, getpid());
                    printf("\nP4: with ID %d and my parent ID Sis %d\n",getpid(),getppid());
                    process = 4;
                    printf("P%d: PID=%d terminates.\n",process, getpid());
                    printf("\nP5: with ID %d and my parent ID is %d\n",getpid(),getppid());
                    process = 5;
                    printf("P%d: PID=%d terminates.\n",process, getpid());
                }
                process = 2;

            }
            else
            {
                sleep(2);
            }
        }
    printf("P%d: PID=%d terminates.\n",process, getpid());
}