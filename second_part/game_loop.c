#include "../head.h"

int close_window(t_game *game)
{
        destroy_all_images(game);
        destroy_mlx(game->mlx);
        free_game(game);
        exit (0);
}

//image->addr = mlx_get_data_addr(image->image, &image->bits_per_pixel, &image->line_length, &image->endian);    



void    my_mlx_pixel_put(t_game *game, int collumns, int collumn_start, int color)
{
    char    *dst;
    t_image *img;

    img = &(game->background);
    // 1. On vérifie qu'on ne dessine pas en dehors de l'image (crash assuré sinon)
    if (collumns < 0 || collumns >= WINDOW_LARGEUR || collumn_start < 0 || collumn_start >= WINDOW_LONGUEUR)
        return ;

    // 2. On calcule l'adresse exacte du pixel (collumns, collumn_start) dans la mémoire
    // adresse = début + (collumn_start * longueur_ligne) + (collumns * nb_octets_par_pixel)
    dst = img->addr + (collumn_start * img->line_length + collumns * (img->bits_per_pixel / 8));

    // 3. On écrit la couleur à cette adresse
    *(unsigned int*)dst = color;
}

int raycasting_loop(t_game *game)
{
    int i;

    i = 0;
    create_background_img(game);
    while (i != WINDOW_LARGEUR)
    {
        //mettre bonne valeur a mon rayon
        put_ray_values(game, i);

        dda_algo(game);
        if (game->ray.side == 0)
            game->ray.perp_wall_dist = (game->ray.sideDistX - game->ray.deltaDistX);
        else
            game->ray.perp_wall_dist = (game->ray.sideDistY - game->ray.deltaDistY);

        //on calcule l endroit precis ou le rayon il touche
        double wallX;
        if (game->ray.side == 0)
            wallX = game->player_info->position.f_y + game->ray.perp_wall_dist * game->ray.rayDirY;
        else
            wallX = game->player_info->position.f_x + game->ray.perp_wall_dist * game->ray.rayDirX;
        wallX -= floor(wallX);

        //que avec des couleurs
        /*int line_height = (int)(WINDOW_LONGUEUR/ game->ray.perp_wall_dist);
        int draw_start = -line_height / 2 + WINDOW_LONGUEUR/ 2;
        if (draw_start < 0)
            draw_start = 0;
        int draw_end = line_height / 2 + WINDOW_LONGUEUR / 2;
        if (draw_end >= WINDOW_LONGUEUR)
            draw_end = WINDOW_LONGUEUR - 1;

        // DESSIN
        int color = (game->ray.side == 0) ? 0xFF0000 : 0xAA0000;
        int y = draw_start;
        while (y < draw_end)
        {
            my_mlx_pixel_put(game, i, y, color);
            y++;
        }*/
        i++;
    }
    // Une fois la boucle finie, on affiche l'image d'un coup
    mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->background.image, 0, 0);
    return (0);
}
    


int game_loop(t_game *game)
{
    //tout les hook pour les touches
    mlx_hook(game->mlx->win, 2, 1L<<0, key_press, game);
    mlx_hook(game->mlx->win, 17, 0, close_window, game);
    //dessiner le ciel et le sol
    //faut pas la verifier elle ne retourne pas de messages d erreurs
    mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->background.image, 0, 0);
    raycasting_loop(game);
    mlx_loop_hook(game->mlx->mlx, raycasting_loop, game);
    mlx_loop(game->mlx->mlx);
    return (0);
}