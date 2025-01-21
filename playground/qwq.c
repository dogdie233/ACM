#include <stdio.h>

int main() {
    char str[] = { 'N', 'O', 0, 'Y', 'E', 'S', 0 };
    printf(str + (getchar() & 1) * 3);
}