#include "../../../head.h"

int check_RGB(t_ceiling ceiling, t_floor floor)
{
    if (ceiling.R < 0 || ceiling.R > 255)
        return (1);
    if (ceiling.G < 0 || ceiling.G > 255)
        return (1);
    if (ceiling.B < 0 || ceiling.B > 255)
        return (1);
    if (floor.R < 0 || floor.R > 255)
        return (1);
    if (floor.G < 0 || floor.G > 255)
        return (1);
    if (floor.B < 0 || floor.B > 255)
        return (1);
    return (0);
}