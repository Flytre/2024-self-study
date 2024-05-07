#include <stdlib.h>
#include <stdio.h>

int main() {
    int *data = malloc(sizeof(int) * 100);
    data[0] = 999;
    data[50] = 200;
    free(data + 50);
    printf("%d\n", data[0]);
    printf("%d\n", data[50]);
    printf("%d\n", data[75]);
}