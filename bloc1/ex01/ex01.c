#include <stdio.h>

int main() {
    int x, y, produit = 0;

    printf("Entrez deux entiers réels: \n");
    scanf("%d", &x);
    printf("x = %d\n", x);

    scanf("%d", &y);
    printf("y = %d\n", y);

    produit = x * y;
    
    if (produit > 0) {
        printf("produit positif : %d\n", produit);
    }
    else if (produit < 0) {
        printf("produit négatif : %d\n", produit);
    }
    else {
        printf("produit nul : %d\n", produit);
    }
}