#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    system("clear");
    int i, process, status;
    pid_t pid1, pid2, pid3, pid4, pid5;
    printf("\nP0: with ID %d parent of all\n", getpid());
    process = 0;
    pid1 = fork();
    if (pid1 == 0)
    {
        printf("\nP1: with ID %d and my parent ID is %d\n", getpid(), getppid());
        process = 1;
    }
    else
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            printf("\nP2: with ID %d and my parent ID is %d\n", getpid(), getppid());
            process = 2;

            pid3 = fork();
            if (pid3 == 0)
            {
                process = 3;
                printf("P3: PID=%d, PPID=%d.\n", getpid(), getppid());
            }
            else
            {
                (pid4 = fork()) && (pid5 = fork());
                if (pid4 == 0)
                {
                    process = 4;
                    printf("P4: PID=%d, PPID=%d.\n", getpid(), getppid());
                }
                else if (pid5 == 0)
                {
                    process = 5;
                    printf("P5: PID=%d, PPID=%d.\n", getpid(), getppid());
                }
                else
                {
                    waitpid(pid4, &status, 0);
                    waitpid(pid5, &status, 0);
                }
            }
        }
        else
        {
            sleep(2);
        }
    }
    printf("P%d: PID=%d terminates.\n", process, getpid());
}