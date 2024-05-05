#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int x = 100;
    int rc = fork();
    if (rc == 0) {
        //child
        printf("child %d\n", x);
        x = 150;
    } else {
        printf("parent: %d\n", x);
        x = 50;
    }
}