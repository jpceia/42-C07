/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 01:43:29 by jceia             #+#    #+#             */
/*   Updated: 2020/12/08 07:11:34 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_isspace(char c);
int		ft_base_size(char *base);
int		ft_chartoi_base(char c, char *base);

int		ft_atoi_base(char *str, char *base)
{
	int index;
	int base_size;
	int sign;
	int nb;

	base_size = ft_base_size(base);
	if (base_size < 2)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
		sign = *(str++) == '-' ? -sign : sign;
	nb = 0;
	while (*str)
	{
		index = ft_chartoi_base(*str, base);
		if (index < 0)
			break ;
		nb = nb * base_size + index;
		str++;
	}
	return (sign * nb);
}

int		ft_nb_digits(int nb, char *base)
{
	int	base_size;
	int	nb_digits;

	base_size = ft_base_size(base);
	if (base_size < 2)
		return (0);
	if (nb == 0)
		return (1);
	nb_digits = 0;
	while (nb != 0)
	{
		nb /= base_size;
		nb_digits++;
	}
	return (nb_digits);
}

char	*ft_itoa_base(int nb, char *base)
{
	int		signal;
	int		len;
	char	*digits;
	int		base_size;

	base_size = ft_base_size(base);
	if (base_size < 2)
		return (0);
	len = ft_nb_digits(nb, base) + 1;
	if (nb < 0)
		len++;
	digits = malloc(sizeof(*digits) * len);
	digits[--len] = 0;
	if (nb < 0)
		digits[0] = '-';
	if (nb == 0)
		digits[0] = base[0];
	signal = nb > 0 ? 1 : -1;
	while (nb != 0)
	{
		digits[--len] = base[signal * (nb % base_size)];
		nb /= base_size;
	}
	return (digits);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*str;

	if (!nbr || ft_base_size(base_from) < 2 || ft_base_size(base_to) < 2)
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	str = ft_itoa_base(nb, base_to);
	return (str);
}
