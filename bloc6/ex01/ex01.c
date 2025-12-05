#include <stdio.h>
#include <stdlib.h>

#define PAD "--------------------------------------"

// COMPILATION :
// gcc -Wall -o ex01.o -c ex01.c | gcc -o ex01 ex01.o



int ft_ask_num(void)
{
    int size;
    printf("Entrez la taille de votre tableau (Entier Strictement positif):\n");
    scanf("%d", &size);

    if (size > 0)
    {
        printf("Taille de votre tableau : %d\n", size);
        return size;
    }
    printf("Erreur : taille de votre tableau est invalide : |%d|\n", size);
    return -1;
}

int *ft_malloc_tableau(int size)
{
    int *tab;

    tab = malloc((size + 8) * sizeof(int));
    if (tab == NULL)
    {
        printf("Erreur : impossible d'allouer la memoire\n");
        return NULL;
    }
    return tab;
}

void ft_free_tableau(int *tab)
{
    free(tab);
    tab = NULL;
}

void ft_remplissage_tableau(int *tab, int size)
{
    int index = 0;

    printf("\nRemplissez votre tableau de %d nombres:\n", size);

    while (index < size)
    {
        printf("Entrez le %d-ieme element de votre tableau :\n", index + 1);
        scanf("%d", &tab[index]);
        index++;
    }
}

void ft_affichage_tableau(int *tab, int size)
{
    int index = 0;

    printf("%s TABLEAU DE %d SIZE %s\n", PAD, size, PAD);
    while (index < size)
    {
        printf("Tab[%d] : |%d|\n", index + 1, tab[index]);
        index++;
    }
}

int main()
{
    int size;
    int *tab;

    if ((size = ft_ask_num()) < 0)
        return -1;
    if((tab = ft_malloc_tableau(size)) == NULL)
        return -1;
    ft_remplissage_tableau(tab, size);
    ft_affichage_tableau(tab, size);
    ft_free_tableau(tab);
}