#include "../../head.h"

//IMAGES DE MURS
//------------------------------------------------------------------------------
//mlx_init pour mlx
//mlx_new_window pour la window
//mlx_new_image pour les images (murs)
int init_mlx(t_mlx *mlx_struct)
{
    mlx_struct->mlx = mlx_init();
    if (mlx_struct->mlx == NULL)
    {
        printf("la fonction mlx init a bader\n");
        printf("dans init_mlx\n");
        return (1);
    }
    mlx_struct->win =    mlx_new_window(mlx_struct->mlx,
        WINDOW_LONGUEUR, WINDOW_LARGEUR, "hihipipi");
    if (mlx_struct->win == NULL)
    {
        mlx_destroy_display(mlx_struct->mlx);
        free(mlx_struct->mlx);
        printf("mlx_new_window a bader\n");
        printf("dans mlx_init\n");
        return (1);
    }
    return (0);
}

//cette fonction va open l image et et remplir les truques de la structure 
int open_image(char *cardinal_points, t_image *image, t_mlx *mlx, int dir)
{
    //la fonction mlx_xpm_file_to_image va remplir toute seule lewidht et le height
    image->image = mlx_xpm_file_to_image(mlx->mlx, cardinal_points, &image->width, &image->height);
    if (image->image == NULL)
    {
        printf("mlx_xpm_file_to_image a bader\n");
        printf("cause possible path pas bien ou ne se finit pas par .xpm\n");
        printf("dans open_image\n");
        return (1);
    }
    //pas besoin de faire des verifications sauf si image est NULL mais on verifie avant
    image->addr = mlx_get_data_addr(image->image, &image->bits_per_pixel, &image->line_length, &image->endian);    
    if (image->addr == NULL)
    {
        printf("la fonction mlx_get_data_addr a bader\n");
        return (1);
    }
    image->direction = dir;
    return (0);
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//BACKGROUND CIEL ET LE SOL

int create_background_img(t_game *game)
{
    int i;
    int c;
    int color;
    char *pixel;

    i = 0;
    c = 0;
    color = 0;
    game->background.image = mlx_new_image(game->mlx->mlx, WINDOW_LARGEUR, WINDOW_LONGUEUR);
    if (game->background.image == NULL)
    {
        printf("mlx_new_img a bader dans create_background_img\n");
        return (1);
    }
    game->background.addr = mlx_get_data_addr(game->background.image, &game->background.bits_per_pixel,
        &game->background.line_length, &game->background.endian);
    if (game->background.addr == NULL)
    {
        printf("mlx_get_data_addr a bader dans create_background_img\n");
        return (1);
    }
    while (i < WINDOW_LONGUEUR)
    {
        if (i < WINDOW_LONGUEUR / 2)
            color = (game->ceiling_floor->ceiling.R << 16 | game->ceiling_floor->ceiling.G << 8 | game->ceiling_floor->ceiling.B);
        else
            color = (game->ceiling_floor->floor.R << 16 | game->ceiling_floor->floor.G << 8 | game->ceiling_floor->floor.B);
        c = 0;
        while (c < WINDOW_LARGEUR)
        {
            pixel = game->background.addr + (i * game->background.line_length + c * (game->background.bits_per_pixel / 8));
            *(unsigned int *)pixel = color;
            c++;
        }
        i++; 
    }
    return (0);
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//cette fonction va creer les pointeurs void *mlx et win
//et creer toute les images et remplir les truques qu il faut avec
int init_image(t_game *game)
{
    int i;
    char *paths[4];

    i = 0;
    paths[0] = game->wall_texture->ea;
    paths[1] = game->wall_texture->no;
    paths[2] = game->wall_texture->so;
    paths[3] = game->wall_texture->we;

    if (init_mlx(game->mlx) == 1)
    {
        destroy_mlx(game->mlx);
        return (1);
    }

    while (i != 4)
    {
        if (open_image(paths[i], &(game->wall_images[i]), game->mlx, i) == 1)
        {
            destroy_all_images(game);
            destroy_mlx(game->mlx);
            return (1);
        }
        i++;
    }
    if (create_background_img(game) == 1)
    {
        destroy_all_images(game);
        destroy_mlx(game->mlx);
        return (1);
    }
    return (0);
}