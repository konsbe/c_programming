#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(int argc,int  status, char *argv[]){

    {
        int pid_t, pid;
        printf("P0: i;m the original process. PID=%d, PPID=%d.\n", getpid(), getppid());
        pid = fork();
        if (pid != 0)
        {
            printf("P1: I'm P1: PID=%d, PPID%d. \n",  getpid(), getppid());
            // execl(./pathname, argv, ..., NULL);
            execl("./aplo", "aplo", "5", NULL);
        } else {
            printf("P2: I'm the child. PID=%d, PPID%d. \n",  getpid(), getppid());
            execl("firkingtrees.c", "firkingtrees", "2", NULL);

        }
    }
}
