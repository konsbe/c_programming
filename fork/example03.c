#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    int p;
    pid_t pid1, pid2, pid3, pid4, pid5;
    printf("P0: of all: %d\n", getpid());

    p = 0;
    pid1 = fork();

    if (pid1 == 0)
    { // Child Process, lets say B.
        printf("P2: with id: %d and its Parent id: %d \n", getpid(), getppid());
        p = 2;
        pid2 = fork();
        if (pid2 == 0)
        { // Child process, lets say D.
            printf("P3: with id: %d and its Parent id: %d \n", getpid(), getppid());
            p = 3;
        }
        printf("P%d: PID=%d terminates.\n",p, getpid());

}
if(pid1 > 0){
    pid3 = fork();
    if(pid3 == 0){ // Child process, lets say C.
        printf("P5: with id: %d and its Parent id: %d \n", getpid(), getppid());
        p = 5;
        pid4 = fork();
        if(pid4 == 0){ // Child process, lets say E.
            printf("P4: with id: %d and its Parent id: %d \n", getpid(), getppid());
            p = 4;
        }
    }
    printf("P%d: PID=%d terminates.\n",p, getpid());
}
for(int i=0; i<3; i++)
  wait(NULL);
}