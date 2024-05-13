#include "libft.h"

void	ft_striteri(char *str, void (*fx)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		(*fx)(i, &str[i]);
		i++;
	}
	str[i] = '\0';
}
