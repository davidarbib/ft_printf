/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:33:58 by pauljull          #+#    #+#             */
/*   Updated: 2019/04/23 17:42:35 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../include/ft_printf.h"
#include <stdio.h>

long				power(long nb, unsigned long pow)
{
	long			res;

	res = nb;
	if (pow == 0)
		return (1);
	pow -= 1;
	while (pow > 0)
	{
		res *= nb;
		pow -= 1;
	}
	return (res);
}

int					base_validity(char *base)
{
	char			*tmp;

	if (!base)
		return (0);
	if (ft_strlen(base) == 1)
		return (0);
	while (*base)
	{
		if (*(base + 1))
			tmp = base + 1;
		while (*tmp)
		{
			if (*base == *tmp)
				return (0);
			tmp += 1;
		}
		base += 1;
	}
	return (1);
}

long				nb_digit_base(long nb, char *base)
{
	long			base_len;
	long			count;

	count = 0;
	if (nb < 0)
		count += 1;
	base_len = ft_strlen(base);
	while (nb)
	{
		nb /= base_len;
		count += 1;
	}
	return (count);
}

char				*ft_itoa_base(long nb, char *base)
{
	char			*str;
	long			dig;
	unsigned long	base_len;
	long			i;

	if (!base_validity(base))
		return (NULL);
	dig = nb_digit_base(nb, base);
	base_len = ft_strlen(base);
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (dig + 1))))
		return (NULL);
	str[dig] = 0;
	if (nb < 0)
		str[i++] = '-';
	while (i < dig)
	{
		str[i] = (nb > 0 ? base[(nb / power(base_len, dig - i - 1))]
		: base[-(nb / power(base_len, dig - i - 1))]);
		nb -= ((nb / power(base_len, dig - i - 1)))
		* power(base_len, dig - i - 1);
		i += 1;
	}
	return (str);
}
