#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    system("clear");
    int i, process;
    pid_t pid0, pid1, pid2, pid3, pid4, pid5;
    printf("\n \t \t I am the parent process with ID %d \n", getpid());
    process = 0;
    pid0 = fork();
    if (pid0 == 0)
    {
        printf("\nP1: with PID %d and my parent ID is %d\n", getpid(), getppid());
        process = 1;
        sleep(2);
    }
    else
    {
        pid1 = fork();
        if (pid1 == 0)
        { // Child Process, lets say B.
            printf("P2: with id: %d and its Parent id: %d \n", getpid(), getppid());
            process = 2;
        } else {
            printf("P1: with id: %d and its Parent id: %d \n", getpid(), getppid());
            process = 1;

        }
            printf("\nP0: with PID %d and my parent ID is %d\n", getpid(), getppid());
    }
    printf("P%d: PID=%d terminates.\n", process, getpid());
}