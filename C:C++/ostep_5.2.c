#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("write.txt", O_RDWR | O_CREAT);
    char buffer[10];
    int rc = fork();
    // file descriptor not duplicated
    while (read(fd, buffer, 10) > 0) {
        printf("buf: %s | rc: %d\n", buffer, rc);
    }
    //write interleaved indeterminately
    char writebuf[1];
    for (int i = 0; i < 36; i++) {
        writebuf[0] = i + 48;
        write(fd, writebuf, 1);
    }

}