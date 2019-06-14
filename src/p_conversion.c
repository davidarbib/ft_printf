/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:05:58 by darbib            #+#    #+#             */
/*   Updated: 2019/05/27 15:53:44 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int					p_conversion(t_plist *list, va_list arg)
{
	int				n_dig;
	unsigned long	nb;
	char			*p_tab;
	char			*s_hex;

	nb = (unsigned long)va_arg(arg, unsigned long);
	if (!nb && !list->precision)
		n_dig = 0;
	else
		n_dig = nb_digit_base_unsigned(nb, "0123456789abcdef");
	list->vlc = higher_value(0, list->width, n_dig + 2);
	if (!(list->tab = ft_strnew(list->vlc)))
		return (0);
	space_filling(list->tab, list->vlc);
	if (list->flag & MINUS_FLAG)
		p_tab = list->tab;
	else
		p_tab = list->tab + list->vlc - (n_dig + 2);
	ft_strcpy(p_tab, "0x");
	if (!(s_hex = ft_itoa_base_unsigned(nb, "0123456789abcdef")))
		return (0);
	if (n_dig)
		ft_strcpy(p_tab + 2, s_hex);
	free(s_hex);
	return (1);
}
