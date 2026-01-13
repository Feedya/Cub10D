#include "../../head.h"

//fonctionne avec un char * plus simple je pourrai le faire en void mais on ne 
//ft_realloc
//cette fonction prend l anciene taille du pointeur et la nouvelle a mallocer
//la old et la new size sont en bits donc quand on veut utiliser realloc
// on devrai faire "sizeof(char) * nouvelle_taille" et la meme chose pour la old_size
//et ce realloc va remplir la taille restante avec des 0 si il y a plus rien a copier
//--------------------------------------------------------------------------------------------
void *ft_realloc(void *ptr, size_t new_size, size_t old_size)
{
    void    *new_ptr;
    size_t i;
    char *src;
    char *dest;

    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
    {
        printf("gpt ma (m'a) dit de mettre ERREUR DANS REALLOC\n");
        free(ptr);
        return (NULL);
    }
    src = (char *)ptr;
    dest = (char *)new_ptr;
    i = 0;
    while (i != new_size && i != old_size)
    {
        dest[i] = src[i];
        i++;
    }
    while (i != new_size)
    {
        dest[i] = '\0';
        i++;
    }
    free(ptr);
    return (new_ptr);
}



//ft_calloc 
//--------------------------------------------------------------------------------------------
void	ft_putzero(char *str, int taille)
{
	int	i;

	i = 0;
	while (i != taille)
	{
		str[i] = 0;
		i++;
	}
}

//cette fonction renvoie un void* donc elle peut mallocer
//n importe quelle variable
//pour le type il faut mettre sizeof(qqc)
void    *ft_calloc(size_t type, size_t taille)
{
	void	*ptr;

	ptr = malloc(type * taille);
	if (ptr == NULL)
		return (NULL);
	ft_putzero((char*)ptr, taille * type);
	return (ptr);
}

