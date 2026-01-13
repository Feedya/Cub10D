#include "../../../head.h"

int	check_if_three_RGB(char *str)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			while (str[i] <= '9' && str[i] >= '0')
			{
				i++;
			}
			counter++;
		}
		else
			i++;
	}
	if (counter != 3)
	{
		printf("Nique ta mere\n");
        printf("trop de rgb\n");
		return (1);
	}
	return (0);
}

int check_ceiling_and_floor(char *file)
{
		int i;
		int tab[2];

		tab[0] = 0;
		tab[1] = 0;
		i = 0;
		while (file[i] != '\0')
		{
				if (file[i] == 'F' && tab[0] == 0)
				{
						tab[0] = 1;
						if (check_if_three_RGB(&file[i]) == 1)
								return (1);
				}
				if (file[i] == 'C' && tab[1] == 0)
				{
						tab[1] = 1;
						if (check_if_three_RGB(&file[i]) == 1)
							return (1);
				}
				i++;
		}
		if (tab[0] == 0 || tab[1] == 0)
		{
			printf("Il manque le ceiling sois le sol sale con de merde\n");
			return (1);
		}
		return (0);
}
