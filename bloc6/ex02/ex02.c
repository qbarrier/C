#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAD "--------------------------------------"

// COMPILATION :
// gcc -Wall -g -o ex02.o -c ex02.c | gcc -o ex02 ex02.o



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

    tab = malloc(size * sizeof(int));
    if (tab == NULL)
    {
        printf("Erreur : impossible d'allouer la memoire\n");
        return NULL;
    }
    return tab;
}

int *ft_realloc_tableau(int *tab, int size)
{
    tab = realloc(tab, size * sizeof(int));
    if (tab == NULL)
    {
        printf("Erreur : impossible de reallouer la memoire\n");
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

int ft_demande_aggrandir(void)
{
    char str[4] = "";

    printf("\n\nsouhaitez-vous recommencer avec un tableau plus grand ? ('oui' pour continuer)\n");
    scanf("%s", str);
    // printf("str = |%s|\n", str);
    if (strcmp(str, "oui") == 0)
        return 1;
    return 0;
}

int ft_agrandir_tableau(int **tab, int size)
{
    int new_size = 0;

//    printf("new size == |%d| size == |%d|\n", new_size, size);
    if (ft_demande_aggrandir() == 1 && ((new_size = ft_ask_num()) > 0))
    {
        if (new_size > size)
        {
            ft_realloc_tableau((*tab), new_size);
            ft_remplissage_tableau((*tab), new_size);
            return new_size;
        }
        else
        {
            printf("Nouvelle taille plus petite que l'ancienne == |%d<%d|\n", size, new_size);
        }
    }
    printf("new size == |%d| size == |%d|\n", new_size, size);
    return size;
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
    printf("\n SIZE == |%d|\n", size);
    ft_affichage_tableau(tab, size);

    size = ft_agrandir_tableau(&tab, size);
    printf("\n SIZE == |%d|\n", size);
    ft_affichage_tableau(tab, size);
    




    ft_free_tableau(tab);
}