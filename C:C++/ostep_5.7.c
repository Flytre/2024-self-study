#include <unistd.h>
#include <stdio.h>
int main() {
    int rc = fork();
    if(!rc) {
        close(STDOUT_FILENO);
        printf("test\n");
    }
}