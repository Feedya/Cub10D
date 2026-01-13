#include "../../../head.h"

char **check_map(char **map)
{
    char **new_map;

    if (check_if_closed(map) == 1)
    {
        printf("la map n est pas fermer\n");
        return (NULL);
    }
    if (check_charactere_map(map) == 1)
    {
        printf("Charactere non permis dans map\n");
        return (NULL);
    }
    new_map = create_good_map(map);
    if (new_map == NULL)
        return (NULL);
    return (new_map);
}
