/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:24:01 by pauljull          #+#    #+#             */
/*   Updated: 2019/06/14 16:11:09 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "../include/ft_printf.h"
#include "../libft/libft.h"

long				tab_integer(t_plist *list, va_list arg)
{
	long			nb;

	if (list->flag & MINL_FLAG)
		nb = va_arg(arg, long);
	else
		nb = va_arg(arg, int);
	return (nb);
}

unsigned long		vlc_process_di(long nb, t_plist *list)
{
	long	vlc;

	vlc = higher_value(list->precision, list->width, nb_digit(nb));
	if (!nb && !list->precision && !list->width)
		vlc = 0;
	if (vlc == (long)nb_digit(nb) || vlc == list->precision)
		if (((list->flag & PLUS_FLAG) && nb >= 0)
		|| ((list->flag & SPACE_FLAG) && nb >= 0))
			vlc += 1;
	if (vlc == list->precision && nb < 0)
		vlc += 1;
	return (vlc);
}

int					count_length_di(t_plist *list, long nb)
{
	unsigned int	count;

	count = nb_digit(nb);
	if (nb == 0 && (list->precision == 0))
		return (0);
	if (list->precision > (int)count)
		count = list->precision;
	if ((list->precision == (int)count) && (nb < 0))
		count += 1;
	if (list->flag & PLUS_FLAG && nb >= 0)
		count += 1;
	if (list->flag & SPACE_FLAG && nb >= 0)
		count += 1;
	if ((list->flag & ZERO_FLAG) && list->width > count)
		count = list->width;
	return (count);
}

char				*ft_itoa_di(long nb, t_plist *list)
{
	char			*str;
	int				count;
	unsigned int	i;

	i = 0;
	count = count_length_di(list, nb);
	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	zero_filling(str, count);
	str[count] = 0;
	if (nb < 0)
		str[0] = '-';
	if (nb >= 0 && (list->flag & PLUS_FLAG))
		str[0] = '+';
	if (list->flag & SPACE_FLAG && nb >= 0)
		str[0] = ' ';
	while (count > 0 && str[count - 1] == '0')
	{
		str[count - 1] = '0' + ((nb % 10 > 0) ? nb % 10 : -(nb % 10));
		nb /= 10;
		count -= 1;
	}
	return (str);
}
