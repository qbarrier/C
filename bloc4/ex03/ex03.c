#include <stdio.h>
#include <string.h>


// COMPILATION :
// gcc -Wall -o ex03.o -c ex03.c | gcc -o ex03 ex03.o


int compter_mots(const char *s)
{

    int nb_mots = 0;
    int index = 0;
    int len = strlen(s);

    while (index < len && (s[index] == ' ' || s[index] == '\n' || s[index] == '\t'))
    {
        index++;
    }
    while (len > index && (s[len] == ' ' || s[index] == '\n' || s[index] == '\t'))
    {
        len--;
    }
    while (index < len )
    {
        if(s[index] != ' ' && s[index] != '\n' && s[index] != '\t')
        {
            printf("s[%d] = %c\n", index, s[index]);
            nb_mots++;
            while(index < len && s[index] != ' ' && s[index] != '\n' && s[index] != '\t')
            {
                index++;
            }
        }
        else
        {
            index++;
        }
    }
    return nb_mots;
}

int main()
{
    char str[100];
    char *revstr;
    int nb_mots = 0;

    fgets(str, sizeof(str), stdin);
    printf("Vous avez entre %lld caracteres\n", strlen(str));
    printf("str = %s\n", str);


    nb_mots = compter_mots(str);
    printf("nb_mots str = %d\n", nb_mots);

    revstr = strrev(str);
    printf("revstr = %s\n", revstr);


    nb_mots = compter_mots(revstr);
    printf("nb_mots revstr = %d\n", nb_mots);


    nb_mots = compter_mots("\nazer\t  \t \n ttt\n\nnnn\n\tt  ");
    printf("nb_mots revstr = %d\n", nb_mots);


}