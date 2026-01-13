#include "../head.h"

void    put_case_where_is_player(t_ray *ray, t_game *game)
{
    ray->mapX = (int)game->player_info->position.f_x;
    ray->mapY = (int)game->player_info->position.f_y;
}

//cetet fonction va mettre la direction de nos  rayon combien de X on passe pour chaque Y
//ou on peut penser a l envers combien de y on passe pour chaque X
void    put_ray_dir(t_ray *ray, t_game *game, double cameraX)
{
    ray->rayDirX = game->player_info->view.dir_x + game->player_info->view.plane_x * cameraX;
    ray->rayDirY = game->player_info->view.dir_y + game->player_info->view.plane_y * cameraX;
}

void    put_delta_dist(t_ray *ray)
{
    ray->deltaDistX = (ray->rayDirX == 0) ? 1e30 : fabs(1 / ray->rayDirX);
    ray->deltaDistY = (ray->rayDirY == 0) ? 1e30 : fabs(1 / ray->rayDirY);
}

int put_ray_values(t_game *game, int column)
{
    t_ray *ray = &(game->ray);

    double cameraX = 2 * column / (double)WINDOW_LARGEUR - 1;

    put_ray_dir(ray, game, cameraX);

    put_case_where_is_player(ray, game);

    put_delta_dist(ray);

    //on va a gauche
    if (ray->rayDirX < 0)
    {
        ray->stepX = -1;
        ray->sideDistX = (game->player_info->position.f_x - ray->mapX) * ray->deltaDistX;
    }
    else
    {
        //on va a droite
        ray->stepX = 1;
        //ray->sideDistX = (game->player_info->position.f_x - ray->mapX) * ray->deltaDistX;
        //ray->sideDistX = ray->sideDistX * -1;
        ray->sideDistX = (ray->mapX + 1.0 - game->player_info->position.f_x) * ray->deltaDistX;
    }
    if (ray->rayDirY < 0)
    {
        //on va en haut
        ray->stepY = -1;
        ray->sideDistY = (game->player_info->position.f_y - ray->mapY) * ray->deltaDistY;
    }
    else
    {
        //on va en bas
        ray->stepY = 1;
        ray->sideDistY = (ray->mapY + 1.0 - game->player_info->position.f_y) * ray->deltaDistY;
    }
    return (0);
}