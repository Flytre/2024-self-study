#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
int main() {
    int rc = fork();
    if(!rc) {
        int status;
        wait(&status); //wait should be used the opposite way, for a parent to wait for the child to terminate
        printf("child! status: %d\n", status);
    } else {
        printf("parent!\n");
    }
}