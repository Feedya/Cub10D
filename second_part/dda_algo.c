#include "../head.h"

int dda_algo(t_game *game)
{
    int hit;
    t_ray *ray;

    ray = &(game->ray);
    hit = 0;
    while (hit == 0)
    {
        if (ray->sideDistX < ray->sideDistY)
        {
            ray->sideDistX += ray->deltaDistX;
            ray->mapX += ray->stepX;
            ray->side = 0;
        }
        else
        {   
            ray->sideDistY += ray->deltaDistY;
            ray->mapY += ray->stepY;
            ray->side = 1;
        }
        if (game->map[ray->mapY][ray->mapX] == '1')
            hit = 1;
    }
    return (0);
}
