#include <stdio.h>

int Square(int n) {
    // Using %zu for size_t ensures clean compilation across all systems
    printf("%zu Bytes\n", sizeof(int));
    printf("%zu Bytes\n", sizeof(n));
    return n * n;
}

int main() {
    int num;
    printf("Enter a Number: ");

    // Always good to check if scanf successfully reads an integer
    if (scanf("%d", &num) == 1) {
        int value = Square(num);
        printf("%d\n", value);
    }

    return 0;
}
