#include "../../head.h"

int parsing(t_game *game)
{
    char **new_map;

    new_map = check_map(game->map);
    if (new_map == NULL)
    {
        printf("malloc a bader ou\n");
        printf("la map n est pas bonne\n");
        return (1);
    }
    free_double_char(game->map);
    game->map = new_map;
    if (fill_rgb(
        &game->ceiling_floor->ceiling,
        &game->ceiling_floor->floor) == 1)
    {
        printf("malloc a bader dans fill rgb\n");
        printf("parsing\n");
        return (1);
    }
    if (check_RGB(game->ceiling_floor->ceiling,
                game->ceiling_floor->floor) == 1)
    {
        printf("probleme dans RGB de ceiling soit floor\n");
        return (1);
    }
    put_player_information(&(game->player_info->view), &(game->player_info->position), game->map);
    return (0);
}