#include "../../head.h"

void    fill_map(char *str, int i, char **map)
{
		int c;
		int d;

		c = 0;
		d = 0;
		while (str[i] != '\0')
		{
			 if (str[i] == '\n')
			 {
						map[d][c] = '\0';
						d++;
						c = 0;
						i++;
			 }
			 else
			 {
						map[d][c] = str[i];
						i++;
						c++;
			 }
		}
        if (str[i] == '\0' && c > 0)
        {
            map[d][c] = '\0';
            d++;
        }
		map[d] = NULL;
}