#include <stdio.h>


void table(int n)
{
    printf("\ntable de %d :\n", n);
    for (int i = 1; i <= 10; i++)
    {
        printf("( %d x %-2d ) = ( %-2d )\n", n, i, n*i);
    }
}

int main() {
    int n = 0;

    printf("\nEntrez un entier n pour calculer sa table: ");
    scanf("%d", &n);
    table(n);
}