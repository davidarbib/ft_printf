/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:04:08 by pauljull          #+#    #+#             */
/*   Updated: 2019/06/12 14:48:08 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int					integer_d_i(t_plist *list, va_list arg)
{
	long			nb;
	unsigned int	vlc;

	nb = tab_integer(list, arg);
	vlc = vlc_process_di(nb, list);
	if (!(list->tab = (char *)malloc(sizeof(char) * (vlc + 1))))
		return (0);
	list->tab[vlc] = 0;
	space_filling(list->tab, vlc);
	if (list->flag & MINUS_FLAG)
		ft_strcpy(list->tab, ft_itoa_di(nb, list));
	else
		ft_str_rev_cpy(list->tab, ft_itoa_di(nb, list));
	list->vlc = vlc;
	return (1);
}

int					unsigned_u_o_x_bigx(t_plist *list, va_list arg)
{
	unsigned long	nb;
	unsigned int	vlc;

	nb = tab_unsigned(list, arg);
	if (list->flag & H_FLAG)
		nb = (unsigned short)nb;
	if (list->flag & HH_FLAG)
		nb = (unsigned char)nb;
	vlc = vlc_process_uoxbigx(nb, list);
	if (!(list->tab = (char *)malloc(sizeof(char) * (vlc + 1))))
		return (0);
	list->tab[vlc] = 0;
	space_filling(list->tab, vlc);
	if (list->flag & MINUS_FLAG)
		ft_strcpy(list->tab, ft_itoa_uoxbigx(nb, list));
	else
		ft_str_rev_cpy(list->tab, ft_itoa_uoxbigx(nb, list));
	list->vlc = vlc;
	return (1);
}
