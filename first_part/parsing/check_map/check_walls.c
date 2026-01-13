#include "../../../head.h"

//cette fonction va verifier si le haut et le bas sont que des 0
int check_up_and_down(char **map)
{
    int i;
    int c;

    c = 0;
    i = 0;
    while (map[0][i] == '1' || map[0][i] == ' ')
        i++;
    if (map[0][i] != '\0')
    {
        printf("la map n est pas fermer en haut\n");
        return (1);
    }
    i = 0;  
    while (map[c] != NULL)
        c++;
    c--;
    while (map[c][i] == '1' || map[c][i] == ' ')
        i++;
    if (map[c][i] != '\0')
    {
        printf("la map n est pas fermer en bas\n");
        return (1);
    }
    return (0);
}

int check_right_left(char **map)
{
    int i;
    int c;

    i = 0;
    while (map[i] != NULL && (map[i][0] == '1' || map[i][0] == ' '))
        i++;
    if (map[i] != NULL)
    {
        printf("le mut a gauche n est pas fermer\n");
        return (1);
    }
    i = 0;
    c = 0;
    while (map[i] != NULL)
    {
        c = ft_strlen(map[i]) - 1;
        if (map[i][c] != '1' && map[i][c] != ' ')
        {
            printf("le mur a droite n est pas fermer\n");
            return (1);
        }
        i++;
    }
    return (0);
}

int check_if_closed(char **map)
{
    if (check_up_and_down(map) == 1)
        return (1);
    if (check_right_left(map) == 1)
        return (1);
    return (0);
}