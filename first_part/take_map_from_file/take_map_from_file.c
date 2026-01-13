#include "../../head.h"

//cette fonction va renvoyer l index du premier nombre de la map
//elle va sauter toute les lignes blnches et toute les lignes qui
//ne commence pas par un nombre
int	find_start_of_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			jump_spaces(str, &i);
		if (str[i] < '0' || str[i] > '9')
		{
			while (str[i] != '\n' && str[i] != '\0')
				i++;
			if (str[i] == '\n')
				i++;
		}
		if (str[i] == '1' || str[i] == '0')
			return (i);
	}
	return (-1); 
}

char	**create_map(char *str, int index)
{
	char	**map;
	map = malloc_map(str, index);
    if (map == NULL)
    {
        printf("malloc n a pas fonctionner dans create_map\n");
        return (NULL);
    }
    fill_map(str, index, map);
    return (map);
}

//cette fonction va renvoyer un char **map
//qui aura la carte stoquer dans le fichier
//si probleme de malloc elle va free le char *file
char    **take_map_from_file(char *file)
{
    int start_map_index;
	char **map;
    start_map_index = find_start_of_map(file);
    printf("%d\n", start_map_index);
    if (start_map_index < 0)
	{
        free(file);
		printf("PROBLEME PROBLEME PROBLEME PROBLEME PROBLEME PROBLEME\n");
		printf("AU SECOURS AU SECOURS AU SECOURS AU SECOURS AU SECOURA\n");
		printf("SOS SOS SOS SOS SOS SOS SOS SOS SOS SOS SOS SOS SOS SOS\n");
		return (NULL);
	}
	map = create_map(file, start_map_index);
    if (map == NULL)
    {
        printf("map est NULL dans take map from file\n");
        free(file);
        return (NULL);
    }
	return (map);
}