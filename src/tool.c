/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:48:25 by pauljull          #+#    #+#             */
/*   Updated: 2019/05/27 15:52:34 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

unsigned int		nb_digit_uoxbigx(unsigned long nb, t_plist *list)
{
	int				n_dig;

	n_dig = 0;
	if (list->flag & O_FLAG)
		n_dig = nb_digit_base_unsigned(nb, "01234567");
	else if (list->flag & U_FLAG)
		n_dig = nb_digit_base_unsigned(nb, "0123456789");
	else if ((list->flag & X_FLAG) || (list->flag & BIGX_FLAG))
		n_dig = nb_digit_base_unsigned(nb, "0123456789abcdef");
	return (n_dig);
}

unsigned long		nb_digit(long n)
{
	unsigned long	tmp;
	unsigned long	value;

	value = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		tmp = -(n);
		value += 1;
	}
	else
		tmp = n;
	while (tmp)
	{
		value += 1;
		tmp /= 10;
	}
	return (value);
}
