/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 09:52:32 by pauljull          #+#    #+#             */
/*   Updated: 2019/06/13 14:01:02 by darbib           ###   ########.fr       */
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

unsigned long		tab_unsigned(t_plist *list, va_list arg)
{
	unsigned long	nb;

	if (list->flag & MINL_FLAG)
		nb = va_arg(arg, unsigned long);
	else if (list->flag & H_FLAG)
		nb = va_arg(arg, unsigned int);
	else if (list->flag & HH_FLAG)
		nb = va_arg(arg, unsigned int);
	else
		nb = va_arg(arg, unsigned int);
	return (nb);
}

int					vlc_process_uoxbigx(unsigned long nb, t_plist *list)
{
	unsigned int				vlc;
	unsigned int				n_dig;

	n_dig = nb_digit_uoxbigx(nb, list);
	if (!list->precision && !nb)
		n_dig = 0;
	if (((list->flag & X_FLAG) || (list->flag & BIGX_FLAG))
	&& (list->flag & SHARP_FLAG) && nb > 0)
		n_dig += 2;
	vlc = higher_value(list->precision, list->width, n_dig);
	if ((list->flag & O_FLAG) && (vlc == n_dig)
	&& (list->flag & SHARP_FLAG) && nb > 0)
		vlc += 1;
	return (vlc);
}

int					count_length_uoxbigx(unsigned long nb, t_plist *list)
{
	unsigned int				res;
	int							vlc;

	res = nb_digit_uoxbigx(nb, list);
	if (((list->flag & X_FLAG) || (list->flag & BIGX_FLAG))
	&& (list->flag & SHARP_FLAG) && nb > 0)
		res += 2;
	vlc = higher_value(list->width, list->precision, res);
	if (nb == 0 && (list->precision == 0))
		return (0);
	if ((list->flag & ZERO_FLAG) && vlc == (int)list->width)
		return (list->width);
	if (list->precision > (int)res)
		res = list->precision;
	else if ((list->flag & O_FLAG) && (list->flag & SHARP_FLAG) && nb > 0)
		res += 1;
	return (res);
}

void				ft_copy_ouxbigx(t_plist *list, unsigned long nb,
					char *str, unsigned int count)
{
	if ((list->flag & O_FLAG) && (list->flag & SHARP_FLAG)
	&& ((nb_digit_uoxbigx(nb, list) + 1) == count))
		*(str++) = '0';
	else if ((list->flag & X_FLAG) && (list->flag & SHARP_FLAG) && nb > 0)
	{
		ft_strcpy(str, "0x");
		str += 2;
	}
	else if (((list->flag & BIGX_FLAG)) && (list->flag & SHARP_FLAG) && nb > 0)
	{
		ft_strcpy(str, "0X");
		str += 2;
	}
	if (list->flag & O_FLAG)
		ft_str_rev_cpy(str, ft_itoa_base_unsigned(nb, "01234567"));
	if (list->flag & U_FLAG)
		ft_str_rev_cpy(str, ft_itoa_base_unsigned(nb, "0123456789"));
	if (list->flag & X_FLAG)
		ft_str_rev_cpy(str, ft_itoa_base_unsigned(nb, "0123456789abcdef"));
	if (list->flag & BIGX_FLAG)
		ft_str_rev_cpy(str, ft_itoa_base_unsigned(nb, "0123456789ABCDEF"));
}

char				*ft_itoa_uoxbigx(unsigned long nb, t_plist *list)
{
	char			*str;
	char			*head;
	unsigned int	len;
	unsigned int	count;

	if (!list->precision && list->flag & O_FLAG)
		list->precision = -1;
	len = nb_digit_uoxbigx(nb, list);
	count = count_length_uoxbigx(nb, list);
	if (!(str = ft_strnew(count)))
		return (NULL);
	head = str;
	zero_filling(str, count);
	str[count] = 0;
	//if (list->precision > (int)len)
	//	str += list->precision - len;
	ft_copy_ouxbigx(list, nb, str, count);
	return (head);
}
