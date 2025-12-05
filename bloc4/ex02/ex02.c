#include <stdio.h>


// COMPILATION :
// gcc -Wall -o ex02.o -c ex02.c | gcc -o ex02 ex02.o

void affichage(int *tab, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("tab[%d] = %d\n", i, tab[i]);
    }
}

void fusion(const int a[], int na, const int b[], int nb, int res[])
{
    int nmax = na + nb;
    int index_res = 0;
    int index_a = 0;
    int index_b = 0;

    while (index_res < nmax)
    {
        if (index_a < na)
        {
            if (index_b < nb)
            {
                if (a[index_a] < b[index_b])
                {
                    res[index_res] = a[index_a];
                    // printf("res[%d] = %d et a[%d] = %d\n", index_res, res[index_res], index_a, a[index_a]);
                    index_a++;
                }
                else
                {
                    res[index_res] = b[index_b];
                    // printf("res[%d] = %d et b[%d] = %d\n", index_res, res[index_res], index_b, b[index_b]);
                    index_b++;
                }
            }
            else
            {
                res[index_res] = a[index_a];
                // printf("res[%d] = %d et a[%d] = %d\n", index_res, res[index_res], index_a, a[index_a]);
                index_a++;
            }    
        }
        else
        {
            res[index_res] = b[index_b];
            // printf("res[%d] = %d et b[%d] = %d\n", index_res, res[index_res], index_b, b[index_b]);
            index_b++;
        }
        // printf("index res = %d   index a = %d   index b = %d\n", index_res, index_a, index_b);
        index_res++;
    }
}




int main()
{
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int b[7] = {-42, -2, 5, 10, 10, 22, 88} ;
    int res[17];
    int na = 10;   
    int nb = 7;

    printf("\nSoit un tableau de taille %d\n", na);
    affichage(a, na);

    printf("\nEt un tableau de taille %d\n", nb);
    affichage(b, nb);

    
    fusion(a, na, b, nb, res);
    printf("\nla fusion des 2 trie de taille %d\n", nb + na);
    affichage(res, na + nb);
    
}