#include "../../../head.h"

//cette fonction va verifier si le charactere
//est sois un nombre sois un start du charactere
//ou un ESPACE
//et que ca soit pas un \0 ou un \n
//elle va renvoyer 1 si c est un charactere de la map
int	is_character_of_map(char c)
{
	if (((c <= '9' && c >= '0') || c == ' '
					|| c == 'N' || c == 'S' || c == 'E' || c == 'W')
					&& c != '\0' && c != '\n')
		return (1);
	return (0);
}

int count_taille_of_double_char(char **map)
{
    int i;

    i = 0;
    while (map[i] != NULL)
        i++;
    return (i);
}

int find_longest_line(char **map)
{
    int i;
    int biggest;
    int last_biggest;

    i = 0;
    biggest = 0;
    last_biggest = 0;
    while (map[i] != NULL)
    {
        biggest = ft_strlen(map[i]);
        if (biggest > last_biggest)
            last_biggest = biggest;
        i++;
    }
    return (last_biggest);
}