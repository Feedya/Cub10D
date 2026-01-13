#include "../../../head.h"

//cette fonction va verifier qu on a que des charactere
//permis dans notre map
int check_charactere_map(char **map)
{
    int i;
    int c;
    int spawn_counter;

    spawn_counter = 0;
    c = 0;
    i = 0;
    while (map[i] != NULL)
    {
        c = 0;
        while (map[i][c] != '\0')
        {
            if (map[i][c] == 'N' || map[i][c] == 'S' || map[i][c] == 'E' || map[i][c] == 'W')
                spawn_counter++;
            if (is_character_of_map(map[i][c]) == 0)
            {
                printf("Charactere non tolerer dans la map\n");
                return (1);
            }
            c++;
        }
        i++;
    }
    if (spawn_counter == 0 || spawn_counter > 1)
    {
        printf("Trop de spawn ou pas assez sale gros con\n");
        return (1);
    }
    return (0);
}