#include <stdio.h>

// COMPILATION :
// gcc -Wall -o ex01.o -c ex01.c | gcc -o ex01 ex01.o

void affichage(int *tab, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("tab[%d] = %d\n", i, tab[i]);
    }
}

void remplissage(int *tab, int n)
{
    int num;

    for (int i = 0; i < n; i++)
    {
        num = 0;
        printf("Entrez un entier (0 par defaut) pour remplir le tableau %d / %d:\n", i + 1, n);
        scanf("%d", &num);
        tab[i] = num;
    }
    affichage(tab, n);
}

void reverse_tableau(int *tab, int n)
{
    int temp;
    int len = n -1;
    int index = 0;

    while(index < n && len > index && len > 0)
    {
        temp = tab[len];
        tab[len] = tab[index];
        tab[index] = temp;
        index++;
        len--;
    }
    printf("\nAffichage du tableau inverse : \n");
    affichage(tab, n);
}



int main()
{
    int n = 10;
    int tab[10];

    printf("\nEntrez le nombre de valeurs a remplir dans le tableau de %d nombres:\n", n);

    remplissage(tab, n); 
    reverse_tableau(tab, n);

    n = 1;

    printf("\n\nEntrez le nombre de valeurs a remplir dans le tableau de %d nombres:\n", n);
    remplissage(tab, n); 
    affichage(tab, n); // double l'affichage pour bien vérifier que le tableau est bien rempli en dehors de la fonction
    reverse_tableau(tab, n);
    affichage(tab, n); // double l'affichage pour bien vérifier que le tableau est bien rempli en dehors de la fonction

    n = 5;

    printf("\n\nEntrez le nombre de valeurs a remplir dans le tableau de %d nombres:\n", n);
    remplissage(tab, n); 
    reverse_tableau(tab, n);


}