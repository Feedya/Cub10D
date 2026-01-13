#include "../../../head.h"

void    free_game(t_game *game)
{
    int i;

    i = 0;
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
        while (i < 4)
        {
            //free(game->wall_images[i].image);
            //game->wall_images[i].image = NULL;
            free(game->wall_images[i].direction);
            game->wall_images[i].direction = NULL;
            i++;
        }
        free(game);
        game = NULL;
    }
}