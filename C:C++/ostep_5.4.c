#include <unistd.h>

int main() {
    int rc = fork();
    if (rc == 0) {
        char *cmd = "/bin/ls";
        char *args[3] = {cmd, "/Users/flytre/Music/", NULL};
        execv(cmd, args);
    } else {
        execl("/bin/ls", "ls", "/Users/flytre/Movies/", NULL);
    }
}