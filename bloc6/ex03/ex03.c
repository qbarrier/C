#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAD "--------------------------------------"

// COMPILATION :
// gcc -Wall -g -o ex03.o -c ex03.c | gcc -o ex03 ex03.o

typedef struct {
    char nom[30];
    int age;
} Utilisateur;

Utilisateur *ft_malloc_user(int size, Utilisateur *s_tab)
{
    s_tab = malloc(size * sizeof(Utilisateur));
    if (s_tab == NULL)
    {
        printf("Erreur : impossible d'allouer la memoire\n");
        return NULL;
    }
    return s_tab;
}

Utilisateur *ft_realloc_user(Utilisateur *s_tab, int size)
{
    Utilisateur *s_tpm;

    s_tpm = realloc(s_tab, size * sizeof(Utilisateur));
    if (s_tpm == NULL)
    {
        printf("Erreur : impossible de reallouer la memoire\n");
        return NULL;
    }
    return s_tpm;
}

void ft_free_user(Utilisateur *s_tab)
{
    free(s_tab);
    s_tab = NULL;
}

int ft_ask_num(void)
{
    int size;

    printf("Entrez le nombre d'utilisateur a saisir (Entier Strictement positif):\n");
    scanf("%d", &size);
    if (size > 0)
    {
        printf("Nombre d'utilisateur saisis : %d\n", size);
        return size;
    }
    printf("Erreur : nombre invalide : |%d|\n", size);
    return -1;
}

void ft_remplissage_users(Utilisateur *s_tab, int size, int index)
{
    while (index < size)
    {
        printf("\n%sEntrez l'utilisateur numero %d:%s\n", PAD, index + 1, PAD);
        printf("Nom : ");
        scanf("%s", s_tab[index].nom);
        printf("Age : ");
        scanf("%d", &s_tab[index].age);
        printf("\n nom rentre = |%s| age rentre = |%d|\n", s_tab[index].nom, s_tab[index].age);
        index++;
    }
}



void ft_affichage_users(Utilisateur *s_tab, int size)
{
    int index = 0;
    while (index < size)
    {
        printf("User[%-2d] : nom = |%-10s| age = |%-2d|\n", index + 1, s_tab[index].nom, s_tab[index].age);
        index++;
    }
}



int ft_agrandir_users(Utilisateur **s_tab, int size)
{
    int size_up = 0;
    if ((size_up = ft_ask_num()) > 0)
    {
        (*s_tab) = ft_realloc_user((*s_tab), size_up + size);
        printf("size up == |%d| size == |%d|\n", size_up, size);
        ft_remplissage_users((*s_tab), size_up + size, size);
        return (size_up + size);
    }
    return -1;
}


int main()
{
    int size;
    Utilisateur *s_tab = NULL;

    if ((size = ft_ask_num()) < 0)
        return -1;
    if((s_tab = ft_malloc_user(size, s_tab)) == NULL)
        return -1;
    ft_remplissage_users(s_tab, size, 0);
    printf("%s TABLEAU DE %d SIZE %s\n", PAD, size, PAD);
    ft_affichage_users(s_tab, size);

    if ((size = ft_agrandir_users(&s_tab, size)) < 0)
        return -1;

    printf("%s TABLEAU DE %d SIZE %s\n", PAD, size, PAD);
    ft_affichage_users(s_tab, size);


    ft_free_user(s_tab);
}