#include "../../head.h"

char    *take_string(char *file)
{
    char *str;
    int i;
    int taille;

    taille = 0;
    i = 0;
    while (file[i] != '\0' && file[i] != '\n')
    {
        if (file[i] == ' ')
            i++;
        else if (file[i] != ' ' && file[i] != '\0' && file[i] != '\n')
        {
            i++;
            taille++;
        }
    }
    str = malloc(sizeof(char) * (taille + 1));
    if (str == NULL)
        return (NULL);
    i = 0;
    taille = 0;
    while (file[i] != '\0' && file[i] != '\n')
    {
        if (file[i] == ' ')
            i++;
        else if (file[i] != ' ' && file[i] != '\0' && file[i] != '\n')
        {
            str[taille] = file[i];
            taille++;
            i++;
        }
    }
    str[taille] = '\0';
    return (str);
}

//cette fonction vas prendre la string jusqu au \n
//elle va renvoyer se qui suit apres le needle qu on lui envoie
char    *take_string_after_needle(char *file, char *needle)
{
    int i;
    char *str;

    i = 0;
    while (file[i] != '\0')
    {
        if (str_compare(&file[i], needle, ft_strlen(needle)) == 1)
        {
            str = take_string(&file[i] + ft_strlen(needle));
            if (str == NULL)
            {
                printf("take string after needle, malloc a bader\n");
                return (NULL);
            }
            return (str);
        }
        i++;
    }
    printf("on a pas trouver la string rechercher\n");
    printf("dans take string after needle\n");
    return (NULL);
}