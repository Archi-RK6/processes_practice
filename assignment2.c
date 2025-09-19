#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t proc1 = fork();
    
    if (proc1 < 0) {
        perror("fork failed");
        return 1;
    }

    if (proc1 == 0) {
        printf("Child  PID  = %d\n", getpid());
        return 10;
    }  else  {
        int procStatus1;
        wait(&procStatus1);

        if (WIFEXITED(procStatus1))
            printf("The first child exited with status = %d\n", WEXITSTATUS(procStatus1));
        else 
            puts("child did not exit successfully");
    }

    pid_t proc2 = fork();
    
    if (proc2 < 0) {
        perror("fork failed");
        return 1;
    }

    if (proc2 == 0) {
        printf("Child  PID  = %d\n", getpid());
        return 20;
    }  else  {
        int procStatus2;
        waitpid(proc2, &procStatus2,  0);

        if (WIFEXITED(procStatus2))
            printf("The second child exited with status of %d\n", WEXITSTATUS(procStatus2));
        else 
            puts("child did not exit successfully");
    }

    return 0;
}