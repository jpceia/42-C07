/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 03:38:33 by jceia             #+#    #+#             */
/*   Updated: 2020/12/08 09:12:30 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;

	if (range == NULL)
		return (-1);
	if (min < max)
	{
		*range = malloc(sizeof(**range) * (max - min));
		if (*range == NULL)
			return (-1);
		index = 0;
		while (min + index < max)
		{
			(*range)[index] = min + index;
			index++;
		}
		return (index);
	}
	*range = 0;
	return (0);
}
