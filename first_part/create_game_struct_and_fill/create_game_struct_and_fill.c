#include "../../head.h"

int fill_ceiling_floor(t_game *game, char *file)
{
    char *ceiling;
    char *floor;

    ceiling = take_string_after_needle(file, "C");
    if (ceiling == NULL)
        return (1);
    game->ceiling_floor->ceiling.RGB = ceiling;
    floor = take_string_after_needle(file, "F");
    if (floor == NULL)
        return (1);
    game->ceiling_floor->floor.RGB = floor;
    return (0);
}

t_game *create_game_struct_and_fill(char **map, char *file)
{
    t_game *game;

    game = malloc_game(map);
    if (game == NULL)
    {
        free(file);
        return (NULL);
    }
    if (fill_wall_texture(game, file) == 1)
    {
        free(file);
        free_game(game);
        return (NULL);
    }
    if (fill_ceiling_floor(game, file) == 1)
    {
        free(file);
        free_game(game);
        return (NULL);
    }
    return (game);
}