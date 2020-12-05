
#include <stdlib.h>

int	ft_ultimate_range(int **range, int max, int min)
{
	int	index;

	if (min < max)
	{
		*range = (int*)malloc(sizeof(int) * (max - min));
		index = 0;
		while (index < max)
		{
			*range[index] = min + index;
			index++;
		}
		return (index);
	}
	*range = 0;
	return (0);

}
