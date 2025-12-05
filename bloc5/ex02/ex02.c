#include <stdio.h>
#include <string.h>
#include <time.h>

// COMPILATION :
// gcc -Wall -o ex02.o -c ex02.c | gcc -o ex02 ex02.o

struct Utilisateur {
    char login[10];
    char mdp[13];
    char entite[8];
    char creation_date[10];
};


void date_aaaammdd(char *str_date)
{
    time_t t = time(NULL);
    struct tm *date = localtime(&t);
    char new_date[10];

    strftime(new_date, sizeof(new_date), "%Y%m%d", date);
    strcpy(str_date, new_date);
    // printf("date = %s\n", str_date);    
}

void create(struct Utilisateur *user, char *login, char *mdp, char *entite)
{
    strcpy(user->login, login);
    strcpy(user->mdp, mdp);
    strcpy(user->entite, entite);
    date_aaaammdd(user->creation_date);
}

//afficher liste des structures
void affichage(struct Utilisateur *user, int n)
{
    int index = 0;
    while (index < n)
    {
        printf("\n%d : login = | %-10s|   mdp = | %-13s|   entite = | %-8s|   creation_date = | %-9s|\n", 
            index, user[index].login, user[index].mdp, user[index].entite, user[index].creation_date);
        index++;
    }
}

void affichage_par_entite(struct Utilisateur *user, int n, char *entite)
{
    int index = 0;

    // printf("\n\n");
    while (index < n)
    {
        if (strcmp(user[index].entite, entite) == 0)
        {
            printf("\n%d : login = | %-10s|   mdp = | %-13s|   entite = | %-8s|   creation_date = | %-9s|\n", 
                    index, user[index].login, user[index].mdp, user[index].entite, user[index].creation_date);
        }
        index++;
    }
}

void affichage_par_date(struct Utilisateur *user, int n, char *date)
{
    int index = 0;

    // printf("\n\n");
        while (index < n)
    {
        if (strcmp(user[index].creation_date, date) == 0)
        {
            printf("\n%d : login = | %-10s|   mdp = | %-13s|   entite = | %-8s|   creation_date = | %-9s|\n", 
                    index, user[index].login, user[index].mdp, user[index].entite, user[index].creation_date);
        }
        index++;
    }
}


int main ()
{
    struct Utilisateur users[10];
    int n = 10;
    int index = 0;
    char date_du_jour[10];
    date_aaaammdd(date_du_jour);

    create(&users[index++], "itaka", "12345", "SNCF");
    create(&users[index++], "john", "22345", "SNCF");
    create(&users[index++], "bob", "32345", "IT");
    create(&users[index++], "alice", "42345", "DARTY");
    create(&users[index++], "charles", "52345", "ENGIE");
    create(&users[index++], "david", "62345", "SNCF");
    create(&users[index++], "emily", "72345", "ENGIE");
    create(&users[index++], "frank", "82345", "IT");
    create(&users[index++], "grace", "92345", "IT");
    create(&users[index++], "harry", "102345", "EDF");

    index = 0;
    affichage(users, n);

    printf("\n\n\n---------------USERS SNCF---------------\n");
    affichage_par_entite(users, n, "SNCF");

    printf("\n\n\n---------------USERS IT---------------\n");
    affichage_par_entite(users, n, "IT");

    printf("\n\n\n---------------USERS DARTY---------------\n");
    affichage_par_entite(users, n, "DARTY");

    printf("\n\n\n---------------USERS ENGIE---------------\n");
    affichage_par_entite(users, n, "ENGIE");

    printf("\n\n\n---------------USERS EDF---------------\n");
    affichage_par_entite(users, n, "EDF");

    printf("\n\n\n---------------USERS CREATION DATE DU JOUR : %s---------------\n", date_du_jour);
    affichage_par_date(users, n, date_du_jour);

    strcpy(users[4].creation_date, "20200101");
    strcpy(users[2].creation_date, "19990101");
    strcpy(users[9].creation_date, "20200101");

    printf("\n\n\n---------------USERS CREATION DATE DU JOUR : %s APRES MODIFICATION ---------------\n", date_du_jour);
    affichage_par_date(users, n, date_du_jour);

    printf("\n\n\n---------------USERS CREATION DATE DU : %s---------------\n", "20200101");
    affichage_par_date(users, n, "20200101");

}