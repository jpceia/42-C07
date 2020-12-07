/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 03:38:33 by jceia             #+#    #+#             */
/*   Updated: 2020/12/05 03:41:24 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;

	range = malloc(sizeof(*range));
	if (min < max)
	{
		*range = malloc(sizeof(**range) * (max - min));
		index = 0;
		while (min + index < max)
		{
			*range[index] = min + index;
			index++;
		}
		return (index);
	}
	*range = 0;
	return (0);
}
