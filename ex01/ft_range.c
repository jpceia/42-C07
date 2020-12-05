
#include <stdlib.h>

int	*ft_range(int max, int min)
{
	int	*rng;
	int	index;

	if (max <= min)
		return (0);
	rng = (int*)malloc(sizeof(int) * (max - min));
	index = min;
	while (index < max)
	{
		res[index] = min + index;
		index++;
	}
	return (rng);
}
