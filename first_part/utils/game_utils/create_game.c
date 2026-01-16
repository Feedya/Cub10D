#include "../../../head.h"

t_game *malloc_empty_game()
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (game == NULL)
        return (NULL);
    game->ceiling_floor = NULL;
    game->player_info = NULL;
    game->mlx = NULL;
    game->map = NULL;
        
    game->mlx = malloc(sizeof(t_mlx));
    if (game->mlx == NULL)
    {
        free_game(game);
        return (NULL);
    }
    game->player_info = malloc(sizeof(t_player_info));
    if (game->player_info == NULL)
    {
        free_game(game);
        return (NULL);
    }
    game->ceiling_floor = malloc(sizeof(t_ceiling_floor));
    if (game->ceiling_floor == NULL)
    {
        free_game(game);
        return (NULL);
    }
    game->wall_texture = malloc(sizeof(t_texture));
    if (game->wall_texture == NULL)
    {
        free_game(game);
        return (NULL);
    }

    int i = 0;
    while (i  != 4)
    {
        game->wall_images[i].addr = NULL;
        game->wall_images[i].image = NULL;
        game->wall_images[i].bits_per_pixel = 0;
        game->wall_images[i].line_length = 0;
        game->wall_images[i].endian = 0;
        game->wall_images[i].width = 0;
        game->wall_images[i].height = 0;
        i++;
    }
    return (game);
}