#include <stdio.h>

double moyenne_notes(void)
{
    double moy = 0;
    double note = 0;
    int nbr_notes = 0;

    printf("\nEntrez vos notes de 0 à 20:\n");
    while (scanf("%lf", &note) && note != -1 )
    {
        if (note < 0 || note > 20) 
        {
            printf("\nLes notes doivent etre comprises entre 0 et 20\n");
        }
        else
        {
            nbr_notes++;
            moy += note;
            printf("La note |%lf| a ete prise, vous en etes a |%d| notes, le total des vos notes est de |%lf|, la moyenne acutelle est de |%lf|\n", note, nbr_notes,moy, (moy / nbr_notes));
        }
        printf("Entrez -1 pour terminer\n");
    }
    moy = moy / nbr_notes;
    return moy;
}

int main() {

    double res = moyenne_notes();
    printf("\nLe moyenne des notes est de : %lf\n", res);
}