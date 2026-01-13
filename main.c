#include "head.h"

char    *create_good_filename(char *argv)
{

    if (check_filename(argv) == 1)
    {
            exit (1);
    }
    return (argv);
}

int main(int argc, char **argv)
{
    char *filename;
    t_game *game;

    if (argc == 2)
    {
        filename = create_good_filename(argv[1]);
        char *file = read_file(filename);
        if (check_everything(file) == 1)//on check ici
            return (1);
        char **map = take_map_from_file(file);
        if (map == NULL)
            return (1);
        game = create_game_struct_and_fill(map, file);
        free(file);
        if (parsing(game) == 1)//on check ici
        {
            free_game(game);
            return (1);
        }
        if (init_image(game) == 1)
        {
            free_game(game);
            return (1);
        }
        game_loop(game);
    }
    else
        printf("filename\n");
    return (0);
}