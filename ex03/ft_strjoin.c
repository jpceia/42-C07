/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 03:42:08 by jceia             #+#    #+#             */
/*   Updated: 2020/12/05 04:01:07 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*freeable_empty_string(void)
{
	char	*s;

	s = malloc(1);
	*s = 0;
	return (s);
}

int		strings_size(int size, char **strs)
{
	int	i;
	int	j;
	int	total_size;

	i = 0;
	total_size = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		total_size += j;
		i++;
	}
	return (total_size);
}

int		ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		j;
	int		res_size;

	if (size == 0)
		return (freeable_empty_string());
	res_size = strings_size(size, strs) + ft_strlen(sep) * (size - 1);
	result = malloc(res_size + 1);
	i = 0;
	res_size = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[res_size++] = strs[i][j++];
		i++;
		if (i == size)
			continue;
		j = 0;
		while (sep[j])
			result[res_size++] = sep[j++];
	}
	result[res_size] = '\0';
	return (result);
}
