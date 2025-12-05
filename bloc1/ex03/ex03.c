#include <stdio.h>
#include <string.h>

int ft_dictcmp(char *str, char **dictionnaire, int n)
{
    int index = 0;
    while (index < n && dictionnaire[index] != NULL)
    {
        printf("dictionnaire[%d] = %s\n", index, dictionnaire[index]);
        if (strcmp(str, dictionnaire[index]) == 0)
        {
            return index;
        }
        index++;
    }
    return -1;
}



int main() {
    char *prenom = "alfred";

    //dictionnaire de 10 prenoms dans l'ordre alphabetique :
    char *dictionnaire[10] = {"Abel", "Achille", "Adam", "Adrien", "Alain", "Alexandre", "Alfred", "Alice", "Allan", "Arthur"};
    int n = 10;
    int res = 0;

    if ((res = ft_dictcmp(prenom, dictionnaire, n)) != -1)
    {
        printf("\nLe prénom '%s' est dans le dictionnaire à l'index dictionnaire[%d] : %s\n", prenom, res, dictionnaire[res]);
    }
    else
    {
        printf("\nLe prénom '%s' n'est pas dans le dictionnaire\n", prenom);
    }
}