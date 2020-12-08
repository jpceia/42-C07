/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 03:42:08 by jceia             #+#    #+#             */
/*   Updated: 2020/12/08 09:16:13 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*freeable_empty_string(void)
{
	char	*str;

	str = malloc(1);
	*str = 0;
	return (str);
}

int		ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strcat(char *dest, char *src)
{
	int	n;
	int index;

	n = ft_strlen(dest);
	index = 0;
	while (src[index])
	{
		dest[n + index] = src[index];
		index++;
	}
	dest[n + index] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		index;
	int		res_size;

	if (size == 0)
		return (freeable_empty_string());
	res_size = ft_strlen(sep) * (size - 1);
	index = 0;
	while (index < size)
		res_size += ft_strlen(strs[index++]);
	result = malloc(res_size + 1);
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	index = 0;
	while (index < size - 1)
	{
		ft_strcat(result, strs[index]);
		ft_strcat(result, sep);
		index++;
	}
	ft_strcat(result, strs[index]);
	return (result);
}
