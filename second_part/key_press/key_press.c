#include "../../head.h"

// fleches du haut
// 119
// fleches a gauche
// 97
// fleches a droite
// 100
// fleches du bas
// 115
// escape
// 65307

void    move_up(t_game *game)
{
    double next_x;
    double next_y;

    next_x = game->player_info->position.f_x + game->player_info->view.dir_x * MOVE_SPEED;
    next_y = game->player_info->position.f_y + game->player_info->view.dir_y * MOVE_SPEED;
    if (game->map[(int)game->player_info->position.f_y][(int)next_x] != '1')
        game->player_info->position.f_x = next_x;
    if (game->map[(int)next_y][(int)game->player_info->position.f_x] != '1')
        game->player_info->position.f_y = next_y;
}

void    move_down(t_game *game)
{
    double next_x;
    double next_y;

    next_x = game->player_info->position.f_x - game->player_info->view.dir_x * MOVE_SPEED;
    next_y = game->player_info->position.f_y - game->player_info->view.dir_y * MOVE_SPEED;
    if (game->map[(int)game->player_info->position.f_y][(int)next_x] != '1')
        game->player_info->position.f_x = next_x;
    if (game->map[(int)next_y][(int)game->player_info->position.f_x] != '1')
        game->player_info->position.f_y = next_y;
}

void    move_droite(t_game *game)
{
    double next_x;
    double next_y;

    next_x = game->player_info->position.f_x + game->player_info->view.plane_x * MOVE_SPEED;
    next_y = game->player_info->position.f_y + game->player_info->view.plane_y * MOVE_SPEED;
    if (game->map[(int)game->player_info->position.f_y][(int)next_x] != '1')
        game->player_info->position.f_x = next_x;
    if (game->map[(int)next_y][(int)game->player_info->position.f_x] != '1')
        game->player_info->position.f_y = next_y;
}

void    move_gauche(t_game *game)
{
    double next_x;
    double next_y;

    next_x = game->player_info->position.f_x - game->player_info->view.plane_x * MOVE_SPEED;
    next_y = game->player_info->position.f_y - game->player_info->view.plane_y * MOVE_SPEED;
    if (game->map[(int)game->player_info->position.f_y][(int)next_x] != '1')
        game->player_info->position.f_x = next_x;
    if (game->map[(int)next_y][(int)game->player_info->position.f_x] != '1')
        game->player_info->position.f_y = next_y;
}

void    rotate_droite(t_game *game)
{
    double  oldDirX;
    double  oldPlaneX;

    // 1. Rotation du vecteur Direction
    oldDirX = game->player_info->view.dir_x;
    game->player_info->view.dir_x = game->player_info->view.dir_x * cos(ROT_SPEED) - game->player_info->view.dir_y * sin(ROT_SPEED);
    game->player_info->view.dir_y = oldDirX * sin(ROT_SPEED) + game->player_info->view.dir_y * cos(ROT_SPEED);

    // 2. Rotation du vecteur Plane (indispensable pour que le FOV suive !)
    oldPlaneX = game->player_info->view.plane_x;
    game->player_info->view.plane_x = game->player_info->view.plane_x * cos(ROT_SPEED) - game->player_info->view.plane_y * sin(ROT_SPEED);
    game->player_info->view.plane_y = oldPlaneX * sin(ROT_SPEED) + game->player_info->view.plane_y * cos(ROT_SPEED);
}

void    rotate_gauche(t_game *game)
{
    double  oldDirX;
    double  oldPlaneX;

    // 1. Rotation du vecteur Direction
    oldDirX = game->player_info->view.dir_x;
    game->player_info->view.dir_x = game->player_info->view.dir_x * cos(-ROT_SPEED) - game->player_info->view.dir_y * sin(-ROT_SPEED);
    game->player_info->view.dir_y = oldDirX * sin(-ROT_SPEED) + game->player_info->view.dir_y * cos(-ROT_SPEED);

    // 2. Rotation du vecteur Plane (indispensable pour que le FOV suive !)
    oldPlaneX = game->player_info->view.plane_x;
    game->player_info->view.plane_x = game->player_info->view.plane_x * cos(-ROT_SPEED) - game->player_info->view.plane_y * sin(-ROT_SPEED);
    game->player_info->view.plane_y = oldPlaneX * sin(-ROT_SPEED) + game->player_info->view.plane_y * cos(-ROT_SPEED);
}

int    key_press(int keycode, t_game *game)
{
    (void)game;
    printf("%d\n", keycode);
    if (keycode == 119)
    {
        move_up(game);
    }
    else if (keycode == 97)
    {
        move_gauche(game);
    }
    else if (keycode == 100)
    {
        move_droite(game);
    }
    else if (keycode == 115)
    {
        move_down(game);
    }
    else if (keycode == 101)//E
    {
        rotate_droite(game);
    }
    else if (keycode == 113)//q
    {
        rotate_gauche(game);
    }
    else if (keycode == 65307)
    {
        destroy_all_images(game);
        destroy_mlx(game->mlx);
        free_game(game);
        exit (0);
    }
    //e 101
    //q 113
    printf("keycode : %d\n", keycode);
    return (0);
}