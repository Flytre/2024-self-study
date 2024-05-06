#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        return 1;
    }

    int rc1 = fork();
    char *buf[1] = {"_"};
    if (!rc1) {
        buf[0] = "a";
        close(pipefd[0]);
        write(pipefd[1], buf, 1);
        close(pipefd[1]);
        exit(0);
    }

    int rc2 = fork();
    if(!rc2) {
        close(pipefd[1]);
        read(pipefd[0], buf, 1);
        printf("%s\n", buf[0]);
        close(pipefd[0]);
        exit(0);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(rc1, NULL, 0);
    waitpid(rc2, NULL, 0);
    exit(0);
}