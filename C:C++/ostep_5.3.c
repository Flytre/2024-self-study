#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pipefds[2];
    if (pipe(pipefds) == -1) {
        perror("pipe");
        exit(-1);
    }

    int rc = fork();
    char buf[1];
    if (!rc) {
        close(pipefds[0]);
        printf("hello\n");
        write(pipefds[1], buf, 1);
        close(pipefds[1]);
        exit(0);
    } else {
        close(pipefds[1]);
        read(pipefds[0], buf, 1);
        close(pipefds[0]);
        printf("goodbye\n");
    }
}