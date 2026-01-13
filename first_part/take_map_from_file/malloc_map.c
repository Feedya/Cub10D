#include "../../head.h"

//cette fonction compte 
int count_big_taille_map(char *str, int i)
{
    int counter;

    counter = 0;
    while (str[i] != '\0')
	{
        if (str[i] == '\n')
            counter++;
        i++;
	}
    if (str[i] == '\0')
        counter++;
    return (counter);
}

void    malloc_small_parts_map(char *str, int i, char **map)
{
    int counter;
    int d;

    counter = 0;
    d = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            map[d] = malloc(sizeof(char) * (counter + 1));
            if (map[d] == NULL)
            {
                free_double_char(map);
                free(str);
                exit (1);
            }
            counter = 0;
            d++;
            i++;
        }
        else
        {
            i++;
            counter++;
        }
    }
    if (counter > 0)
    {
        map[d] = malloc(sizeof(char) * (counter + 1));
        if (map[d] == NULL)
        {
            free_double_char(map);
            free(str);
            exit (1);
        }
    }
}

//N,S,E,W 
char    **malloc_big_parts_map(char *str, int i)
{
	char	**map;
	int	counter;

	counter = count_big_taille_map(str, i);
	map = malloc(sizeof(char*) * (counter + 1));
    if (map == NULL)
        return (NULL);
    return (map);
}

char	**malloc_map(char *str, int index)
{
	char	**map;

	map = malloc_big_parts_map(str, index);
	if (map == NULL)
    {
        free(str);
        return (NULL);
    }
    malloc_small_parts_map(str, index, map);
	return (map);
}
