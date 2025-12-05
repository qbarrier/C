#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ELEVES 55
#define PAD "--------------------------------------"

// COMPILATION :
// gcc -Wall -g -o ex01.o -c ex01.c | gcc -o ex01 ex01.o

typedef struct {
    int numero;
    char prenom[10];
    double notes[5];
    int ects[5];
    double moyenne;
} Eleves;

double moyenne(double *tab, int n)
{
    int index = 0;
    double moy = 0;

    while (index < n)
    {
        moy += tab[index++];
    }
    return (moy / n);
}


void ask_note( Eleves *s_eleve, int index)
{
    printf("Entrez la notes numero %d : ", index + 1);
    scanf("%lf", &s_eleve->notes[index]);
}

void ask_prenom(Eleves *s_eleve)
{
    printf("\nEntrez votre prenom : ");
    scanf("%s", s_eleve->prenom);
}

void ft_build(Eleves *s_eleve, int numero)
{
    int index = 0;

    printf("\nNumero de l'eleve : %d\n", numero);
    s_eleve->numero = numero;
    s_eleve->ects[0] = 5;
    s_eleve->ects[1] = 4;
    s_eleve->ects[2] = 3;
    s_eleve->ects[3] = 6;
    s_eleve->ects[4] = 2;
    ask_prenom(s_eleve);

    while (index < 5)
    {
        ask_note(s_eleve, index++);
    }

    s_eleve->moyenne = moyenne(s_eleve->notes, 5);
}


void ft_afficher_eleve(Eleves s_eleve)
{
    printf("\n%s ELEVE NUMERO : %-2d %s\n", PAD, s_eleve.numero, PAD);
    printf("Prenom : %s\n", s_eleve.prenom);
    printf("Notes : ");

    for (int index = 0; index < 5; index++)
    {
        printf("|%-6.2lf| ", s_eleve.notes[index]);
    }

    printf("\nECTS  : ");

    for (int index = 0; index < 5; index++)
    {
        printf("|%-6d| ", s_eleve.ects[index]);
    }

    printf("\nMoyenne : %.2lf\n", s_eleve.moyenne);
}

int main()
{
    Eleves new_eleve;

    ft_build(&new_eleve, 1);
    ft_afficher_eleve(new_eleve);
}