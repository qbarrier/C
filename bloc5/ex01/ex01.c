#include <stdio.h>
#include <string.h>

// COMPILATION :
// gcc -Wall -o ex01.o -c ex01.c | gcc -o ex01 ex01.o

struct Produit {
    char nom[25];
    int code;
    int ref;
    double prix;
    int quantite;
};

//fonction build structure
void build(struct Produit *p, int code)
{
    printf("Entrez le nom du produit sans espaces :\n");
    scanf("%s", p->nom);
    p->code = code;
    p->ref = code + 1014200;
    printf("Entrez le prix (nb positif) :\n");
    scanf("%lf", &p->prix);
    printf("Entrez la quantite disponible (nb entier positif) :\n");
    scanf("%d", &p->quantite);
}

//fonction affichage structure
void affichage(struct Produit *p)
{
    printf("\t------------------%s--------------------\n", p->nom);
    printf("\nnom = %s\n", p->nom);
    printf("code = %d\n", p->code);
    printf("ref = %d\n", p->ref);
    printf("prix = %.2lf\n", p->prix);
    printf("quantite = %d\n", p->quantite);
    printf("\t---------------------------------------------------\n\n");
}

//fonction création une instance définie

void create(struct Produit *p, char *nom, int code, int ref, double prix, int quantite)
{
    strcpy(p->nom, nom);
    p->code = code;
    p->ref = ref;
    p->prix = prix;
    p->quantite = quantite;
}

double commande(struct Produit *p, int nbr, int code)
{
    double total = -1;
    int index = 0;

    while (index < nbr)
    {
        if (p[index].code == code)
        {
            printf("Le produit |%s| code |%d| a ete trouve, son prix est de |%.2lf| et sa quantite est de |%d|\n", p[index].nom, p[index].code, p[index].prix, p[index].quantite);
            total = (p[index].prix * p[index].quantite);
            return(total);
        }
        index++;
    }
    return total;
}


int main()
{
    struct Produit list_produit[4];
    int n = 4;
    int index = 0;
    int code = 4;

    create(&list_produit[index], "Carte Mere", 1, 1014201, 69.99, 7);
    affichage(&list_produit[index++]);
    create(&list_produit[index], "Processeur", 2, 1014202, 102.2, 8);
    affichage(&list_produit[index++]);
    create(&list_produit[index], "Barrete Memoire", 3, 1014203, 25, 52);
    affichage(&list_produit[index++]);

    build(&list_produit[index], index + 1);
    affichage(&list_produit[index++]);
    

    double total = commande(list_produit, n, code);
    printf("total = %.2lf\n", total);

    
}