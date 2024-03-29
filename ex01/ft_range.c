/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 03:29:07 by jceia             #+#    #+#             */
/*   Updated: 2020/12/06 23:45:59 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*rng;
	int	index;

	if (max <= min)
		return (0);
	rng = malloc(sizeof(*rng) * (max - min));
	index = 0;
	while (min + index < max)
	{
		rng[index] = min + index;
		index++;
	}
	return (rng);
}
