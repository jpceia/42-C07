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

char	*empty_heap_string(void)
{
	char	*s;

	s = malloc(1);
	*s = 0;
	return (s);
}

int		strings_size(int size, char **strs)
{
	int	i;
	int j;
	int ss_size;

	i = 0;
	ss_size = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		ss_size += j;
		i++;
	}
	return (ss_size);
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
		return (empty_heap_string());
	res_size = strings_size(size, strs) + ft_strlen(sep) * (size - 1) + 1;
	result = malloc(res_size);
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
