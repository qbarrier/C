#include <stdio.h>
#include <math.h>

double f(double x);
void f_procedure(double x, double *res);

double f(double x)
{
    double res =  pow(x, 2) + x - 1;
    return (res);
}

void f_procedure(double x, double *res)
{
    *res =  x * x  + x - 1;
}


int main() {
    double x;
    double res = 0;

    printf("\nRentez une valeure x : \n");
    scanf("%lf", &x);
    printf("x = %lf\n", x);
    
    res = f(x);
    printf("pour x = %lf : res de la fonction f = %lf\n", x, res);


    res = 0;
    f_procedure(x, &res);
    printf("pour x = %lf : res de la fonction f_procedure = %lf\n", x, res);
}