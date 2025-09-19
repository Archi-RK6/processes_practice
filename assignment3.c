#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void funcOne(){
    printf("I AM A MASSAGE ONE\n");
}

void funcTwo(){
    printf("I AM A MASSAGE TWO\n");
}


int main(){
    if (atexit(funcOne))
    {
        fprintf(stderr, "atexit() failed!\n");
    }

    if (atexit(funcTwo))
    {
        fprintf(stderr, "atexit() failed!\n");
    }
    printf("Hello!\n");
    return 0;
}