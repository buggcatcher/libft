#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = ft_strlen(dst);
	if (size <= z)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && z + 1 < size)
	{
		dst[z] = src[i];
		z++;
		i++;
	}
	dst[z] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
