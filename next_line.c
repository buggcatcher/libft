#include "libft.h"

char	    *ft_reader(int fd, char *selection);
void	    *ft_calloc_bzero(size_t nmemb, size_t size);
static char *extract_from_buffer(char **mtx);
char        *ft_substr(char const *s, unsigned int start, size_t len);
static char *read_and_assemble(char **mtx, int fd);
char        *next_line(int fd);


static char *fd_reader(int fd)
{
    size_t  char_read;
    char    *buffer;

    buffer = ft_calloc_bzero(sizeof(char), BUFFER_SIZE + 1);
    if(!buffer)
        return (NULL);
    char_read = read(fd, buffer, BUFFER_SIZE);
    if (char_read == 0)
    {
        free(buffer);
        return (NULL);
    }
    else if (char_read == -1)
    {
        perror("Error reading from file descriptor\n");
        free(buffer);
        return (NULL);
    }
    return (buffer);
}
 
static char *extract_from_buffer(char **mtx)
{
    char    *line;
    char    *char_left;
    int     x;

    x = 0;
    if (!mtx || !*mtx)
        return NULL;
    while((*mtx)[x] != '\n' && (*mtx)[x] != '\0')
        x++;
    if ((*mtx)[x] == '\n')
    {
        line = ft_substr(*mtx, 0, x + 1);
        if(!line)
            return(NULL);
        char_left = ft_substr(*mtx, x + 1, ft_strlen(*mtx) - (x + 1));
        if (!char_left)
        {
            free(line);
            return(NULL);
        }
        free(*mtx);
        *mtx = char_left;
        return(line);
    }
    return(NULL);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *new;
    size_t strlen;
    size_t end;

    if (!s)
        return (0);
    strlen = ft_strlen(s);
    end = 0;
    if (start <= strlen)
        end = strlen - start;
    if (start > strlen)
        return (ft_calloc_bzero(1, sizeof(char)));
    if (end > len)
        end = len;
    new = (char *)ft_calloc_bzero(end + 1, sizeof(char));
    if (!new)
        return (0);
    ft_strlcpy(new, s + start, end + 1);
    return (new);
}

static char *read_and_assemble(char **mtx, int fd)
{
    char    *read_line;
    char    *tmp;
    char    *line;

    line = extract_from_buffer(mtx);
    if (line)
        return (line);
    read_line = fd_reader(fd);
    if (!read_line)
    {
        line = ft_strdup(*mtx);
        free(*mtx);
        *mtx = NULL;
        if (*line)
            return(line);
        free (line);
        return(NULL);
    }
    tmp = ft_strjoin(*mtx, read_line);
    free(*mtx);
    free(read_line);
    *mtx = tmp;
    return(read_and_assemble(mtx, fd));
}
 
char *next_line(int fd)
{
    static char *buffer;

    if (read(fd, NULL, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
    {
        free(buffer);
        buffer = NULL;
        return(NULL);
    }
    if (!buffer)
        buffer = ft_strdup("");
    return (read_and_assemble(&buffer, fd));
}
