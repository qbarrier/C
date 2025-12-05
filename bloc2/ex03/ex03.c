#include <stdio.h>

void permute(int a, int b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void permute2(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 101;
    int b = 42;

    printf("\nValeurs de depart : a = %d, b = %d\n", a, b);
    permute(a, b);
    printf("\nValeurs apres permutation permute(int a, int b) : a = %d, b = %d\n", a, b);
    permute2(&a, &b);
    printf("\nValeurs apres permutation2 permute2(int *a, int *b): a = %d, b = %d\n", a, b);

}