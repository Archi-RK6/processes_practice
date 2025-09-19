#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    pid_t proc = fork();
    
    if (proc < 0) {
        perror("fork failed");
        return 1;
    }

    if (proc == 0) {
        printf("Child  PID  = %d\n", getpid());
        return 0;
    }  else  {
        printf("Parent  PID  = %d\n", getpid());
    }

    return 0;
}