#include "../../head.h"

char    *malloc_file(char *filename)
{
    int fd;
    char *buffer;
    int i;
    int c;
    int bytes;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        printf("On a pas reussis a ouvrir le fichier\n");
        printf("open a bader. Dans malloc_file\n");
        return (NULL);
    }
    i = 0;
    c = 100;
    buffer = ft_calloc(sizeof(char), c + 1);
    if (buffer == NULL)
        return (NULL);
    while ((bytes = read(fd, &buffer[i], 1)) > 0)
    {
        i++;
        if (i == c)
        {
            c = c * 2;
            buffer = ft_realloc(buffer, sizeof(char) * (c + 1), sizeof(char) * (c / 2));
            if (buffer == NULL)
            {    
                close(fd);
                return (NULL);
            }
        }
    }
    if (bytes == -1)
    {
        close(fd);
        printf("eeeeeeeerreur de read -1\n");
        free(buffer);
        return (NULL);
    }
    close(fd);
    buffer[i] = '\0';
    return (buffer);
}

char    *read_file(char *filename)
{
    char *file;

    file = malloc_file(filename);
    if (file == NULL)
        return (NULL);
    return (file);
}