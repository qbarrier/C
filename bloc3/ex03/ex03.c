#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void votez(int *a, int *b)
{
    char str[4] = "oui";
    int quitter = -1;

    while(quitter != 0)
    {
        while(strcmp(str, "A") != 0 && strcmp(str, "B") != 0)
        {
            printf("Votre vote doit etre 'A' ou 'B'\n");
            scanf("%s", str);
        }

        if (strcmp(str, "A") == 0)
            (*a)++;
        else
            (*b)++;

        printf("Votre vote est : %s\n\n", str);
        while(strcmp(str, "oui") != 0 && (quitter = strcmp(str, "non") != 0))
        {
            printf("souhaitez-vous continuer ? ('non' pour quitter) : ('oui' pour continuer)\n");
            scanf("%s", str);
        }
    }
}

int main() 
{
    int votes_a = 0;
    int votes_b = 0;
    int total = 0;

    votez(&votes_a, &votes_b);
    total = votes_a + votes_b;
    printf("\nnombres de votes pour A : %d / %d\n", votes_a, total);
    printf("nombres de votes pour B : %d / %d\n\n", votes_b, total);
    

    //pourcentage de votes pour A :
    //sauter une ligne
   

    printf("pourcentage de votes pour A : %.1f %% \n", (float)votes_a / (total) * 100);
    //pourcentage de votes pour B :
    printf("pourcentage de votes pour B : %.1f %% \n\n", (float)votes_b / (total) * 100);

    if (votes_a > votes_b)
        printf("A a gagne de %d votes\n", votes_a - votes_b);
    else if (votes_a < votes_b)
        printf("B a gagne de %d votes\n", votes_b - votes_a);
    else
        printf("Egalitee %d votes chacuns\n", votes_a);

    return 0;
}