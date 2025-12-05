#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ELEVES 55
#define PAD "--------------------------------------"

// COMPILATION :
// gcc -Wall -o ex03.o -c ex03.c && gcc -o ex03 ex03.o

typedef struct {
    int numero;
    char prenom[10];
    double notes[5];
    int ects[5];
    double moyenne;
} Eleves;

typedef struct {
    char nom_matiere[10];
    double note_min;
    double note_max;
    double moyenne;
    char nom_major[20];
} Matieres;

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

// Garder pour modifier manuellement un eleve
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

void ft_create_eleve(Eleves *s_eleve, int numero, char *prenom, double *notes)
{
    int index = 0;

    // printf("\nNumero de l'eleve : %d\n", numero);
    s_eleve->numero = numero;

    s_eleve->ects[0] = 5;
    s_eleve->ects[1] = 4;
    s_eleve->ects[2] = 3;
    s_eleve->ects[3] = 6;
    s_eleve->ects[4] = 2;

    strcpy(s_eleve->prenom, prenom);

    while (index < 5)
    {
        s_eleve->notes[index] = notes[index];
        index++;
    }

    s_eleve->moyenne = moyenne(s_eleve->notes, 5);
    // printf("s_eleve->moyenne = %6lg\n\n", s_eleve->moyenne);
}



void ft_init_eleves(Eleves *s_eleve)
{
    int index = 0;
    char prenoms[MAX_ELEVES][20] = {"Sophie", "Alice", "Bob", "Charlie", "David", "Emily", "Frank", "Grace", "Harry", "Itaka", 
        "John", "Mary", "Fernand", "Georges", "Zack", "Zephyr", "Zoe", "Maggie", "Mary", "Margot", 
        "Mathilde", "Michel", "Marcel", "Marcelle", "Patoche", "Paul", "Pierre", "Rachel", "Robert", "Rose", 
        "Simon", "Sylvie", "Thomas", "Valentin", "Victor", "Xavier", "Yves", "Yvette", "Ryan", "Richie",
        "Thibault", "Topias", "Tom", "Tony", "Tristan", "Ulysse", "Justine", "Joris", "Juste", "Jean-Luc",
        "Jean-Pierre", "Jean-Yves", "Jean", "Karim", "Oslo"};

    //double notes[nombre - 1][5]
    //13*4 +3 = 55
    double notes[MAX_ELEVES][5] = { {12.47, 7.30, 18.92, 3.11, 15.08}, {4.63, 19.74, 6.02, 11.55, 13.89}, {17.42, 5.01, 2.77, 14.68, 9.30}, 
                                    {8.66, 12.15, 3.44, 16.89, 7.02},  {19.12, 1.55, 10.38, 4.92, 6.44},  {14.77, 5.40, 7.71, 18.03, 13.25}, {3.90, 11.28, 15.60, 9.14, 20.00},
                                    {6.33, 7.88, 12.99, 4.07, 17.54},  {13.66, 2.48, 19.13, 14.05, 8.21}, {5.72, 10.11, 16.44, 3.89, 12.56}, {9.31, 4.55, 6.99, 18.70, 2.14}, 
                                    {12.00, 15.27, 7.16, 9.77, 4.82},  {17.10, 13.66, 3.24, 5.99, 19.81}, {8.41, 11.33, 20.00, 7.27, 10.50}, {10.80, 6.44, 4.12, 18.26, 15.34}, 
                                    {2.89, 9.77, 13.25, 11.80, 7.18},  {19.03, 14.77, 8.62, 5.51, 3.80},  {6.11, 16.90, 9.32, 12.77, 1.48},  {7.45, 3.02, 10.55, 18.44, 14.99}, 
                                    {13.37, 8.22, 6.08, 4.44, 19.52},  {11.66, 17.33, 5.92, 2.34, 15.70}, {4.21, 19.10, 12.88, 7.17, 9.05},  {16.92, 6.09, 3.55, 14.22, 11.48}, 
                                    {7.14, 9.88, 19.60, 4.18, 6.77},   {12.99, 3.33, 15.48, 9.01, 17.82}, {8.05, 10.60, 6.45, 13.37, 2.71},  {14.55, 7.80, 4.28, 12.50, 18.31}, 
                                    {5.34, 16.22, 11.18, 1.99, 9.70},  {3.48, 14.02, 20.00, 8.50, 10.22}, {18.44, 6.17, 7.66, 15.80, 12.95}, {11.88, 3.07, 9.02, 19.72, 4.11}, 
                                    {6.90, 17.55, 14.66, 5.39, 8.77},  {12.20, 4.48, 3.92, 13.10, 19.33}, {9.77, 11.55, 7.40, 16.88, 6.03},  {14.08, 2.99, 18.60, 5.44, 12.16}, 
                                    {7.66, 8.11, 10.37, 3.60, 15.28},  {20.00, 6.66, 4.91, 11.92, 9.49},  {5.77, 13.40, 12.14, 18.55, 3.21}, {10.14, 15.60, 6.30, 7.45, 17.10}, 
                                    {2.99, 9.88, 14.72, 4.66, 8.33},   {19.25, 3.40, 11.05, 16.12, 5.57}, {8.44, 12.33, 9.91, 2.70, 14.05},  {6.25, 18.11, 7.48, 10.89, 13.62}, 
                                    {17.80, 4.20, 5.55, 9.00, 12.44},  {3.77, 11.02, 19.33, 6.88, 8.55},  {15.66, 7.44, 12.55, 4.31, 13.20}, {9.12, 5.00, 17.81, 14.30, 6.90}, 
                                    {12.48, 10.77, 3.56, 18.00, 7.77}, {4.33, 8.88, 15.14, 11.22, 2.90},  {16.40, 6.50, 9.80, 19.10, 5.03},  {7.33, 14.55, 10.14, 4.03, 12.88}, 
                                    {11.50, 3.44, 13.99, 17.66, 6.20}, {18.70, 5.33, 2.11, 8.40, 14.10},  {7.66, 8.11, 10.37, 3.60, 15.28},  {4.33, 19.74, 15.14, 11.22, 2.90} };


    while (index < MAX_ELEVES)
    {
        ft_create_eleve(&s_eleve[index], 1 + index, prenoms[index], notes[index]);
        index++;
    }
}

void ft_init_matieres(Matieres *s_matiere)
{
    int index = 0;
    char matieres[5][10] = {"Maths", "LV1", "EPS", "Chimie", "Dev"};

    while (index < 5)
    {
        strcpy(s_matiere[index].nom_matiere, matieres[index]);
        s_matiere[index].note_min = 0;
        s_matiere[index].note_max = 0;
        s_matiere[index].moyenne = 0;
        strcpy(s_matiere[index].nom_major, "");
        index++;
    }
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

void ft_afficher_all_eleves(Eleves *s_eleve)
{
    int index = 0;
    while (index < MAX_ELEVES)
    {
        ft_afficher_eleve(s_eleve[index]);
        index++;
    }
}


/////////////////// EX 02 :



void ft_afficher_matiere(Matieres s_matiere)
{
    printf("\n%s   MATIERE : %-8s %s\n", PAD, s_matiere.nom_matiere, PAD);
    printf("Note Min  : |%-5.2lf|\n", s_matiere.note_min);
    printf("Note Max  : |%-5.2lf|\n", s_matiere.note_max);
    printf("Moyenne   : |%-5.2lf|\n", s_matiere.moyenne);
    printf("Nom Major : |%s|\n", s_matiere.nom_major);
}

void ft_afficher_all_matieres(Matieres *s_matiere)
{
    int index = 0;
    while (index < 5)
    {
        ft_afficher_matiere(s_matiere[index]);
        index++;
    }
}

double ft_moyenne_matiere(Eleves *s_eleve, int index_matiere)
{
    double moy = 0;
    int index_eleve = 0;

    while (index_eleve < MAX_ELEVES)
    {
        moy += s_eleve[index_eleve].notes[index_matiere];
        index_eleve++;
    }
    // printf("total == |%lf / %d = %lf|\n", moy, MAX_ELEVES, moy / MAX_ELEVES);
    return (moy / MAX_ELEVES);
}

void ft_matiere_range(Eleves *s_eleve, Matieres *s_matiere, int index_matiere)
{
    double tmp_min = 20;
    double tmp_max = 0;
    int index_eleve = 0;

    while (index_eleve < MAX_ELEVES)
    {
        if (tmp_min > s_eleve[index_eleve].notes[index_matiere])
        {
            tmp_min = s_eleve[index_eleve].notes[index_matiere];
            s_matiere[index_matiere].note_min = tmp_min;
        }
        else if (tmp_max < s_eleve[index_eleve].notes[index_matiere])
        {
            tmp_max = s_eleve[index_eleve].notes[index_matiere];
            s_matiere[index_matiere].note_max = tmp_max;
        }
        index_eleve++;
    }

}


///////////////////// Ex 03 :

void ft_major(Eleves *s_eleve, Matieres *s_matiere, int index_matiere)
{
    int index_eleve = 0;
    int tmp = 0;

    printf("\n\n%sLE/LA OU LES ELEVE(S) MAJEURS DANS LA MATIERE | %-8s | SONT :%s\n\n", PAD, (*s_matiere).nom_matiere, PAD);
    while (index_eleve < MAX_ELEVES)
    {
        if ((*s_matiere).note_max == s_eleve[index_eleve].notes[index_matiere])
        {
            tmp = index_eleve;
            printf("Numero | %-2d | %-10s | !!! AVEC LA NOTE DE |%-5.2lf|\n", s_eleve[index_eleve].numero ,s_eleve[index_eleve].prenom, s_eleve[index_eleve].notes[index_matiere]);
        }
        index_eleve++;
    }
    strcpy((*s_matiere).nom_major, s_eleve[tmp].prenom); // le dernier majeur sera retenu.
}


void ft_generale_moy(Eleves *s_eleve, Matieres *s_matiere, int index_matiere)
{
    int index_eleve = 0;
    int inferieur = 0;


    printf("\n\n%s LE NOMBRE D'ELEVE EN DESSOUS DE LA MOYENNE DE CLASSE | %-5.2lf | EN | %-8s | SONT :%s\n\n", PAD, (*s_matiere).moyenne , (*s_matiere).nom_matiere, PAD);
    while (index_eleve < MAX_ELEVES)
    {
        if (s_eleve[index_eleve].notes[index_matiere] < (*s_matiere).moyenne)
        {
            inferieur++;
            // printf("\nNote eleve | %-10s | %-8s | %-5.2lf |\n",s_eleve[index_eleve].prenom, (*s_matiere).nom_matiere, s_eleve[index_eleve].notes[index_matiere]);

        }
        index_eleve++;
    }
    printf("\n| %-2d | ELEVES\n", inferieur);
}

void ft_calcul_matiere(Eleves *s_eleve, Matieres *s_matiere)
{
    for(int index = 0; index < 5; index++)
    {
        s_matiere[index].moyenne = ft_moyenne_matiere(s_eleve, index);
        ft_matiere_range(s_eleve, s_matiere, index);
        ft_major(s_eleve, &s_matiere[index], index);
        ft_generale_moy(s_eleve, &s_matiere[index], index);
    }
}








int main()
{
    Eleves s_eleve[MAX_ELEVES];
    Matieres s_matiere[5];

    ft_init_eleves(s_eleve);
    // ft_afficher_all_eleves(s_eleve);
    ft_init_matieres(s_matiere);
    // ft_afficher_all_matieres(s_matiere);

    // Soit les matières suivantes :
    // Maths, LV1, EPS, Chimie, Dev
    // s_eleve->notes[0] == Maths
    // s_eleve->notes[1] == LV1
    // s_eleve->notes[2] == EPS
    // s_eleve->notes[3] == Chimie
    // s_eleve->notes[4] == Dev

    ft_calcul_matiere(s_eleve, s_matiere);

     ft_afficher_all_matieres(s_matiere);

    
}