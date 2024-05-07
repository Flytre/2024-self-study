#include <stdlib.h>
#include <stdio.h>

int main() {
    int *data = malloc(sizeof(int) * 100);
    data[0] = 10;
    data[1] = 50;
    printf("%d\n", data[1]);
    data[100] = 0;
}