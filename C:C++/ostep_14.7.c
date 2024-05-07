#include <stdlib.h>
#include <stdio.h>

int main() {
    int *data = malloc(sizeof(int) * 100);
    data[50] = 200;
    free(data);
    printf("%d", data[50]);
}