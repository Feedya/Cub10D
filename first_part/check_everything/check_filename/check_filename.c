#include "../../../head.h"

void check_filename(char *filename)
{
    char *ending;
    int i;
    int d;

    ending = create_string(".cub");
    i = ft_strlen(filename);
    i--;
    d = 3;
    while (filename[i] == ' ')
        i--;
    while (i >= 0 && d >= 0 && filename[i] == ending[d])
    {
        i--;
        d--;
    }
    free(ending);
    if (d < 0)
        return ;
    printf("le filename doit finire avec .cub\n");
    exit(0);
}
