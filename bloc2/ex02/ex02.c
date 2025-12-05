#include <stdio.h>

//échange de valeurs entre x et y des valeurs pointées par x et y
void echange(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//ajoute un, ne modifie aucunes variable externes
void ajouteUn(int x)
{
    x = x + 1;
}

//ajoute 2 et modifie la variable pointé par x
void ajouteDeux(int *x)
{
    *x = *x + 2;
}

//ajoute 3 à x et y et modifie uniquement la variable pointée par y
void ajouteTrois(int x, int *y)
{
    x = x + 3;
    *y = *y + 3;
}


void affichage(int a, int b, int c, int d)
{
    static int etape = 0;
    int tab[4];
    int index = 0;

    tab[0] = a;
    tab[1] = b;
    tab[2] = c;
    tab[3] = d;

    putchar('\n');
    while (index < 4)
    {
        printf("Etape : |%d| la valeure de '%c' = %d\n", etape, index + 97, tab[index]);
        index++;
    }
    etape++;
}

int main()
{
    int a = 1, b = 2, c = 3, d = 4;

    printf("\n\nValeures de depart de a, b, c , d :\n");
    affichage(a, b, c, d);

    echange(&a, &b); echange(&c, &d);   /* 1 */
    printf("\n\nEtape 1 : On echange les valeures a <=> b et c <=> d :\n");
    affichage(a, b, c, d);

    ajouteUn(a); ajouteDeux(&b);        /* 2 */
    printf("\n\nEtape 2 : on ajoute +2 a b :\n");
    affichage(a, b, c, d);

    ajouteTrois(c, &d);                 /* 3 */
    printf("\n\nEtape 3 : on ajoute + 3 a d :\n");
    affichage(a, b, c, d);

    echange(&a, &d);                    /* 4 */
    printf("\n\nEtape 4 : On echange les valeures a <=> d :\n");
    affichage(a, b, c, d);

}

