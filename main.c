#include "head.h"

int main(int argc, char **argv)
{
    t_game *game;

    if (argc == 2)
    {
        check_filename(argv[1]);
        char *file = read_file(argv[1]);
        if (file == NULL)
            return (1);
        game = parsing(file);
        if (game == NULL)
        {
            free(file);
            free_game(game);
            return (1);
        }
        free(file);
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