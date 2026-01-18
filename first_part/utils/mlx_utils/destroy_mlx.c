#include "../../../head.h"

void    destroy_all_images(t_game *game)
{
    int i;

    i = 0;
    if (game != NULL)
    {
        while (i != 4)
        {
            if (game->wall_images[i].image != NULL)
            {
                mlx_destroy_image(game->mlx->mlx, game->wall_images[i].image);
            }
            i++;
        }
    }
    if (game->background.image != NULL)
        mlx_destroy_image(game->mlx->mlx, game->background.image);
}

void    destroy_mlx(t_mlx *mlx_struct)
{
    if (mlx_struct != NULL)
    {
        if (mlx_struct->win != NULL)
            mlx_destroy_window(mlx_struct->mlx, mlx_struct->win);
        if (mlx_struct->mlx != NULL)
        {
            mlx_destroy_display(mlx_struct->mlx);
            free(mlx_struct->mlx);
            mlx_struct->mlx = NULL;
        }
    }
}