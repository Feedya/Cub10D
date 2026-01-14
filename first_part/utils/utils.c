#include "../../head.h"

int ft_strlen(char *str)
{
		int i;

		i = 0;
		while (str[i] != '\0')
				i++;
		return (i);
}

//vas creer une string et renvoyer NULL si malloc n a pas marcher
char    *create_string(char *str)
{
		int i;
		char *new_str;

		i = ft_strlen(str);
		new_str = malloc(sizeof(char) * (i + 1));
		if (new_str == NULL)
				return (NULL);
		i = 0;
		while (str[i] != '\0')
		{
				new_str[i] = str[i];
				i++;
		}
		new_str[i] = '\0';
		return (new_str);
}

//renvoie 1 si on trouve et 0 si on trouve pas
int str_compare(char *str, char *needle, int taille)
{
    int i;

    i = 0;
    if (taille == 0)
        return (0);
    while (i != taille && str[i] == needle[i] && needle[i] != '\0')
    {
        i++;
    }
    if (i == taille)
        return (1);
    return (0);
}

//cette focntion va free le double pointer char **map
//faut lui donner la taille de se double pointeur
void    free_double_char_size(char **map, int size)
{
    int i;

    i = 0;
		while (i != size)
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
		map = NULL;
}

//cette fonction va sauter les espaces
//et mettre l index apres les espaces
//faut lui faire passer l adresse de l index
void jump_spaces(char *str, int *index)
{
    int i;

    i = *index;
    while (str[i] == ' ')
        i++;
    *index = i;
}

void    exit_mit_text(char *str, int number)
{
    printf("%s\n", str);
    exit (number);
}

//cette fonction
//free un char **
//il doit se terminer avec un NULL
void    free_double_char(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

int ft_atoi(char *str)
{
    int nombre;
    int sign;
    int i;

    nombre = 0;
    i = 0;
    sign = 1;
    while (str[i] == ' ')
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0')
    {
        nombre = nombre * 10;
        nombre = nombre + (str[i] - 48);
        i++;
    }
    return (nombre * sign);
}

//si les deux string sont pareille ca renvoie 1
//sinon 0
int comparer_string(char *str, char *str_two)
{
    int i;

    i = 0;
    while (str[i] == str_two[i] && str[i] != '\0' && str_two[i] != '\0')
    {
        i++;
    }
    if (str[i] == '\0' && str_two[i] == '\0')
        return (1);
    return (0);
}