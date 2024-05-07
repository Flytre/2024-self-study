#include <stdlib.h>
#include <stdio.h>

int main() {
    int *ptr = malloc(sizeof(int));
    *ptr = 100;
    ptr = NULL;
    printf("%d", *ptr);
}