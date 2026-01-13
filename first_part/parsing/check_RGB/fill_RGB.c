#include "../../../head.h"

int *take_rgb(void *objet)
{
    t_floor *floor;
    int i;
    int *tab;
    int c;

    c = 0;
    tab = malloc(sizeof(int) * (3));
    if (tab == NULL)
        return (NULL);
    floor = (t_floor *)objet;
    i = 0;
    while (floor->RGB[i] != '\0')
    {
        if (floor->RGB[i] <= '9' && floor->RGB[i] >= '0')
        {
            int nombre = ft_atoi(&floor->RGB[i]);
            tab[c] = nombre;
            c++;  
            while (floor->RGB[i] <= '9' && floor->RGB[i] >= '0')
                i++;
        }
        else
            i++;
    }
    return (tab);
}

//cette fonction va remplir les int RGB dans les structures ceiling
//et floor
//elle se trouve dans parsing/check_RGB/fill_RGB
int fill_rgb(t_ceiling *ceiling, t_floor *floor)
{
    int *tab;

    tab = take_rgb(floor);
    if (tab == NULL)
        return (1);
    floor->R = tab[0];
    floor->G = tab[1];
    floor->B = tab[2];
    //printf("%d %d %d\n", floor->R, floor->G, floor->B);
    free(tab);
    tab = take_rgb(ceiling);
    if (tab == NULL)
        return (1);
    ceiling->R = tab[0];
    ceiling->G = tab[1];
    ceiling->B = tab[2];
    //printf("%d %d %d\n", ceiling->R, ceiling->G, ceiling->B);
    free(tab);
    return (0);
}