#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = (void *)malloc(size * nmemb);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (size * nmemb));
	return (array);
}
