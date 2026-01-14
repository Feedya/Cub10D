#include "../../../head.h"

void    free_game(t_game *game)
{
    if (game != NULL)
    {
        if (game->map != NULL)
            free_double_char(game->map);
        if (game->ceiling_floor != NULL)
        {
            if (game->ceiling_floor->ceiling.RGB != NULL)
            {
                free(game->ceiling_floor->ceiling.RGB);
                game->ceiling_floor->ceiling.RGB = NULL;
            }
            if (game->ceiling_floor->floor.RGB != NULL)
            {
                free(game->ceiling_floor->floor.RGB);
                game->ceiling_floor->floor.RGB = NULL;
            }
            free(game->ceiling_floor);
            game->ceiling_floor = NULL;
        }
        if (game->player_info != NULL)
        {
            free(game->player_info);
            game->player_info = NULL;
        }
        if (game->mlx != NULL)
        {
            free(game->mlx);
            game->mlx = NULL;
        }
        if (game->wall_texture != NULL)
        {
            if (game->wall_texture->ea != NULL)
            {
                free(game->wall_texture->ea);
                game->wall_texture->ea = NULL;
            }
            if (game->wall_texture->no != NULL)
            {
                free(game->wall_texture->no);
                game->wall_texture->no = NULL;
            }
            if (game->wall_texture->so != NULL)
            {
                free(game->wall_texture->so);
                game->wall_texture->so = NULL;
            }
            if (game->wall_texture->we != NULL)
            {
                free(game->wall_texture->we);
                game->wall_texture->we = NULL;
            }
            free(game->wall_texture);
            game->wall_texture = NULL;
        }
        free(game);
        game = NULL;
    }
}