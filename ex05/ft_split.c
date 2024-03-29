/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 05:06:55 by jceia             #+#    #+#             */
/*   Updated: 2020/12/08 09:18:31 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_contains(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int		ft_count_words(char *str, char *sep_chars)
{
	int count;
	int prev_space;

	count = 0;
	prev_space = 1;
	while (*str)
	{
		if (ft_contains(*str, sep_chars))
			prev_space = 1;
		else if (prev_space)
		{
			count++;
			prev_space = 0;
		}
		str++;
	}
	return (count);
}

char	*ft_strndup(char *str, int n)
{
	char	*res;
	int		size;

	size = 0;
	while (str[size])
		size++;
	size = n < size ? n : size;
	res = malloc(size + 1);
	res[size] = 0;
	while (size--)
		res[size] = str[size];
	return (res);
}

char	**ft_split_core(char **str_list, char *str, char *charset)
{
	int		index;
	int		prev_space;
	char	*str_cpy;

	prev_space = 1;
	index = 0;
	str_cpy = str;
	while (*str)
	{
		if (ft_contains(*str, charset))
		{
			if (!prev_space)
				str_list[index++] = ft_strndup(str_cpy, str - str_cpy);
			prev_space = 1;
		}
		else if (prev_space)
		{
			str_cpy = str;
			prev_space = 0;
		}
		str++;
	}
	if (!prev_space)
		str_list[index++] = ft_strndup(str_cpy, str - str_cpy);
	return (str_list);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	**str_list;

	size = ft_count_words(str, charset);
	str_list = malloc(sizeof(*str_list) * (size + 1));
	if (str_list == NULL)
		return (NULL);
	str_list[size] = 0;
	str_list = ft_split_core(str_list, str, charset);
	return (str_list);
}
