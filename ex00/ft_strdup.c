
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	unsigned int	index;
	char		*dest;

	index = 0;
	while (src[index])
		index++;
	dest = (char*)malloc(sizeof(char) * (index + 1));
	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
