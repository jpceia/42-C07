/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 06:48:41 by jceia             #+#    #+#             */
/*   Updated: 2020/12/08 06:48:45 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char c)
{
	return (c == ' '
			|| c == '\f'
			|| c == '\n'
			|| c == '\r'
			|| c == '\t'
			|| c == '\v');
}

int		ft_base_size(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		ft_chartoi_base(char c, char *base)
{
	int index;

	index = 0;
	while (base[index])
	{
		if (c == base[index])
			return (index);
		index++;
	}
	return (-1);
}
