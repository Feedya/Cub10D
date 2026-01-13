#include  "../../../head.h"

char    **malloc_new_map(int longest_line, int taille_map)
{
    char **new_map;
    int i;

    new_map = malloc(sizeof(char *) * (taille_map + 1));
    if (new_map == NULL)
        return (NULL);
    i = 0;
    while (i != taille_map)
    {
        new_map[i] = malloc(sizeof(char) * (longest_line + 1));
        if (new_map == NULL)
        {
            free_double_char_size(new_map, i);
            return (NULL);
        }
        i++;
    }
    return (new_map);
}

char    **create_new_map(char **map, int longest_line, int taille_map)
{
    char **new_map;
    int i;
    int c;

    new_map = malloc_new_map(longest_line, taille_map);
    if (new_map == NULL)
        return (NULL);
    i = 0;
    while (i != taille_map)
    {
        c = 0;
        while (map[i][c] != '\0')
        {
            if (map[i][c] == ' ')
            {
                new_map[i][c] = '1';
                c++;
            }
            else
            {
                new_map[i][c] = map[i][c];
                c++;
            }
        }
        while (c < longest_line)
        {
            new_map[i][c] = '1';
            c++;
        }
        new_map[i][c] = '\0';
        i++;
    }
    new_map[i] = NULL;
    return (new_map);
}

char    **create_good_map(char **map)
{
    char **new_map;
    int longest_line_lenght;
    int taille_of_tab;

    longest_line_lenght = find_longest_line(map);
    taille_of_tab = count_taille_of_double_char(map);
    new_map = create_new_map(map, longest_line_lenght, taille_of_tab);
    if (new_map == NULL)
        return (NULL);
    return (new_map);
}
