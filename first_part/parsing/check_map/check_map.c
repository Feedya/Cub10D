#include "../../../head.h"

char **check_map(char **map)
{
    char **new_map;

    new_map = create_good_map(map);
    if (new_map == NULL)
        return (NULL);
    if (check_if_closed(new_map) == 1)
    {
        free(new_map);
        printf("la map n est pas fermer\n");
        return (NULL);
    }
    if (check_charactere_map(new_map) == 1)
    {
        free(new_map);
        printf("Charactere non permis dans map\n");
        return (NULL);
    }
    return (new_map);
}
