#include <stdio.h>

int max_tableau(const int t[], int n);

int max_tableau(const int t[], int n) {
    int index = 0;
    int max = 0;

    if (n > 0)
    {
        max = t[0];
        while (index < n) 
        {
            if (t[index] > max) {
                max = t[index];
            }
            index++;
        }
    }
    return max;
}

int main() {

     int tab[10] = {1, 10, 3, 4, 5, 7, 8, 6, 9, 2};
     int n = 10;

    printf( "\nLe maximum du tableau de n = %d : {1, 10, 3, 4, 5, 7, 8, 6, 9, 2}; est de : %d\n", n, max_tableau(tab, n));

    int tab2[4] = {-100, 0, -101, -2};
    int tab3[1] = {-12};
    int tab4[2] = {0, -1};
    
    printf( "Le maximum du tableau de n = 4 : {-100, 0, -101, -2} est de : %d\n", max_tableau(tab2, 4));
    printf( "Le maximum du tableau de n = 1 : {-12} est de : %d\n", max_tableau(tab3, 1));
    printf( "Le maximum du tableau de n = 2 : {0, -1} est de : %d\n", max_tableau(tab4, 2));
}