#include <stdio.h>
#include <string.h>
#define NBR_BULLETIN 12

// COMPILATION :
// gcc -Wall -o ex03.o -c ex03.c | gcc -o ex03 ex03.o

struct bulletin {
    char nom[25];
    double note;
};

void create(struct bulletin *b, char **nom, double *note, int n)
{
    int index = 0;
    while (index < n)
    {
        b[index].note = note[index];
        strcpy(b[index].nom, nom[index]);
        index++;
    }
}

void affichage(struct bulletin *b, int n)
{
    int index = 0;

    printf("\n\n\n-------------BULLETINS-------------\n");
    while (index < n)
    {
        printf("\n%2d : nom = | %-10s|   note = | %-6lg|\n", index, b[index].nom, b[index].note);
        index++;
    }
}

void aff_best_notes(struct bulletin *b, int n)
{
    int index = 0;
    double note = 0;
    int nb_best = 0;

    printf("\n\n\n-------------LES MEILLEURS NOTES SONT ATTRIBUES A : -------------\n");
    while (index < n)
    {
        // printf("\n%2d : nom = | %-10s|   note = | %-6.2lf|\n", index, b[index].nom, b[index].note);
        if (b[index].note > note)
        {
            nb_best = 1;
            note = b[index].note;
        }
        else if (b[index].note == note)
        {
            nb_best++;
        }
        index++;
    }
    index = 0;
    if (note == 0)
    {
        printf("\n-------------PERSONNE VOS NOTE SONT LITTERALLEMENT TOUTES NULLES !!! -------------\n");
    }
    else
    {
        if (nb_best == 1)
        {
            printf("\n-------------NOTRE MEILLEUR ELEVE QUI EST : -------------\n");
        }
        else
        {
            printf("\n-------------NOS %d MEILLEURS ELEVES QUI SONT : -------------\n", nb_best);
        }

        while (index < n)
        {
            if(b[index].note == note && note > 0)
            {
                printf("\n| %-10s|  avec une note de | %-6lg|\n", b[index].nom, b[index].note);
            }
            index++;
        }
    }
    

}

int main()
{
    // double notes[NBR_BULLETIN] = {20, 12, 7, 6.5, 13, 11.5, 20, 13, 5, 18.25, 20, 12};
        // test full zero
    // double notes[NBR_BULLETIN] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        //test 1 note supérieure
    double notes[NBR_BULLETIN] = {0, 12, 7, 6.5, 13, 11.5, 18, 13, 5, 18.25, 19.99, 20};
    char *noms[NBR_BULLETIN] = {"Sophie", "Alice", "Bob", "Charlie", "David", "Emily", "Frank", "Grace", "Harry", "Itaka", "John", "Mary"};
    struct bulletin b[NBR_BULLETIN];
    int n = NBR_BULLETIN;
 
    create(b, noms, notes, n);
    
    affichage(b, n);
    
    aff_best_notes(b, n);


}