#include "../../head.h"

int fill_game(t_game *game, char *file)
{
    char **map = take_map_from_file(file);
    if (map == NULL)
        return (1);
    game->map = map;

    if (fill_wall_texture(game, file) == 1)
    {
        free(file);
        free_game(game);
        return (1);
    }
    if (fill_ceiling_floor(game, file) == 1)
    {
        free(file);
        free_game(game);
        return (1);
    }
    //on remplis les rgb
    if (fill_rgb(
        &game->ceiling_floor->ceiling,
        &game->ceiling_floor->floor) == 1)
    {
        printf("malloc a bader dans fill rgb\n");
        printf("parsing\n");
        return (1);
    }
    //on met les informations du player ou est ce qu il se trouve
    put_player_information(&(game->player_info->view), &(game->player_info->position), game->map);
    return (0);
}

bool check_game(t_game *game)
{
    char **new_map;

    new_map = check_map(game->map);
    if (new_map == NULL)
    {
        printf("malloc a bader ou\n");
        printf("la map n est pas bonne\n");
        return (false);
    }
    free_double_char(game->map);
    game->map = new_map;
    if (check_RGB(game->ceiling_floor->ceiling,
                game->ceiling_floor->floor) == 1)
    {
        printf("probleme dans RGB de ceiling soit floor\n");
        return (false);
    }
    return (true);
}

t_game *parsing(char *file)
{
    t_game *game;

    //des check avant la creation de la  structure t_game
    //check les texture de mur
    if (check_texture(file) == 1)
			return (NULL);
    //checker les couleurs du toit et du sol
	if (check_ceiling_and_floor(file) == 1)
    	return (NULL);
    game = malloc_empty_game();
    if (game == NULL)
    {
        printf("probleme de malloc dans malloc_empty_game\n");
        free(file);
        return (NULL);
    }
    if (fill_game(game, file) == 1)
    {
        printf("probleme fans fill_game avec malloc\n");
        free(file);
        free_game(game);
        return (NULL);
    }
    if (check_game(game) == false)
    {
        printf("probleme dans le check_game\n");
        return (NULL);
    }

    return (game);
}