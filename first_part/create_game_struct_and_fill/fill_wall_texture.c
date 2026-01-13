#include "../../head.h"

int fill_wall_texture(t_game *game, char *file)
{
    char *ea;
    char *no;
    char *so;
    char *we;

    ea = take_string_after_needle(file, "EA");
    if (ea == NULL)
        return (1);
    game->wall_texture->ea = ea;
    no = take_string_after_needle(file, "NO");
    if (no == NULL)
        return (1);
    game->wall_texture->no = no;
    so = take_string_after_needle(file, "SO");
    if (so == NULL)
        return (1);
    game->wall_texture->so = so;
    we = take_string_after_needle(file, "WE");
    if (we == NULL)
        return (1);
    game->wall_texture->we = we;
    return (0);
}