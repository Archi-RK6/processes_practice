#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t proc = fork();

    if (proc < 0) {
        perror("fork failed");
        return 1;
    }

    if (proc == 0) {
        printf("Child process #%d stops\n", getpid());
        exit(0); 
    } else {
        printf("Parent sleeping for 60 seconds.\n");
        sleep(60);
        printf("Parent waking up and waiting for child.\n"); 
        wait(NULL);
    }

    return 0;
}