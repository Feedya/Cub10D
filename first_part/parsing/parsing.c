#include "../../head.h"

t_game *parsing(char *file)
{
    char **new_map;
    t_game *game;

    char **map = take_map_from_file(file);
    if (map == NULL)
        return (NULL);
    game = create_game_struct_and_fill(map, file);
     //check les texture de mur
    if (check_texture(file) == 1)
			return (NULL);
    //checker les couleurs du toit et du sol
	if (check_ceiling_and_floor(file) == 1)
    	return (NULL);
    new_map = check_map(game->map);
    if (new_map == NULL)
    {
        printf("malloc a bader ou\n");
        printf("la map n est pas bonne\n");
        return (NULL);
    }
    free_double_char(game->map);
    game->map = new_map;
    if (fill_rgb(
        &game->ceiling_floor->ceiling,
        &game->ceiling_floor->floor) == 1)
    {
        printf("malloc a bader dans fill rgb\n");
        printf("parsing\n");
        return (NULL);
    }
    if (check_RGB(game->ceiling_floor->ceiling,
                game->ceiling_floor->floor) == 1)
    {
        printf("probleme dans RGB de ceiling soit floor\n");
        return (NULL);
    }
    put_player_information(&(game->player_info->view), &(game->player_info->position), game->map);
    return (game);
}