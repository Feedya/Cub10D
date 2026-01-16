#include "../../head.h"


void    put_player_information(t_player_view *view, t_player_position *player, char **map)
{
    int i;
    int c;

    c = 0;
    i = 0;
    while (map[i] != NULL)
    {
        c = 0;
        while (map[i][c] != '\0')
        {
            if (map[i][c] == 'N')
            {
                //position
                player->x = c;
                player->y = i;
                player->f_x = c + 0.5f;
                player->f_y = i + 0.5f;
                //view
                view->dir_x = 0;
                view->dir_y = -1;
                view->plane_x = 0.66f;
                view->plane_y = 0;
                //map
                map[i][c] = 'P';//pttr mettre 0 faut voir apres
                return ;
            }
            else if (map[i][c] == 'W')
            {
                //position
                player->x = c;
                player->y = i;
                player->f_x = c + 0.5f;
                player->f_y = i + 0.5f;
                //view
                view->dir_x = -1;
                view->dir_y = 0;
                view->plane_x = 0;
                view->plane_y = -0.66f;
                //map
                map[i][c] = 'P';
                return ;
            }
            else if (map[i][c] == 'S')
            {
                //position
                player->x = c;
                player->y = i;
                player->f_x = c + 0.5f;
                player->f_y = i + 0.5f;
                //view
                view->dir_x = 0;
                view->dir_y = 1;
                view->plane_x = -0.66f;
                view->plane_y = 0;
                //map
                map[i][c] = 'P';
                return ;
            }
            else if (map[i][c] == 'E')
            {
                //position
                player->x = c;
                player->y = i;
                player->f_x = c + 0.5f;
                player->f_y = i + 0.5f;
                //view
                view->dir_x = 1;
                view->dir_y = 0;
                view->plane_x = 0;
                view->plane_y = 0.66f;  
                //map
                map[i][c] = 'P';
                return ;
            }
            c++;
        }
        i++;
    }
    printf("ON A PAS TROUVER DE SPAWN POINTS\n");
    printf("put_player_information.c\n");
    return ;
}