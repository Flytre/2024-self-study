#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    int rc = fork();
    if (!rc) {
        printf("child!\n");
    } else {
        int status;
        waitpid(rc, &status, 0);
        printf("parent!\n");
    }
}