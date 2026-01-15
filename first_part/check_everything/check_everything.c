#include "../../head.h"

//checkeur avant de recheck dans la structure game
//on check les textures
int check_everything(char *file)
{
    //check les texture de mur
    if (check_texture(file) == 1)
			return (1);
    //checker les couleurs du toit et du sol
	if (check_ceiling_and_floor(file) == 1)
    	return (1);
    return (0);
}