#include "../../../head.h"

//elle va check si pour chaque direction de mur on a une texture si
//on a pas elle renvoie 1
int check_texture(char *file)
{
    int i;
    int counter;
    int found[4];

    found[0] = 0;
    found[1] = 0;
    found[2] = 0;
    found[3] = 0;
    counter = 0;
    i = 0;
    while (file[i] != '\0')
    {
        if (str_compare(&file[i], "NO", 2) == 1 && found[0] == 0)
        {
            counter++;
            found[0] = 1;
        }
        if (str_compare(&file[i], "WE", 2) == 1 && found[1] == 0)
        {
            counter++;
            found[1] = 1;
        }
        if (str_compare(&file[i], "EA", 2) == 1 && found[2] == 0)
        { 
            counter++;
            found[2] = 1;
        }
        if (str_compare(&file[i], "SO", 2) == 1 && found[3] == 0)
        {
            counter++;
            found[3] = 1;
        }
        i++;
    }
    if (counter == 4)
        return (0);
    printf("pas de tecture pour un coter de mur\n");
    printf("AAAAHHHHHHHHHHHHH...........\n");
    printf("guguggaga texture mur check_texture.c\n");
    return (1);
}