/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:27:15 by darbib            #+#    #+#             */
/*   Updated: 2019/05/28 16:56:35 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			percent_conversion(t_plist *list)
{
	if (list->flag & MINUS_FLAG && list->flag & ZERO_FLAG)
		list->flag -= ZERO_FLAG;
	list->vlc = higher_value(0, list->width, 1);
	if (!(list->tab = ft_strnew(list->vlc)))
		return (0);
	if (list->flag & ZERO_FLAG)
		zero_filling(list->tab, list->vlc);
	else
		space_filling(list->tab, list->vlc);
	if (list->flag & MINUS_FLAG)
		ft_strcpy(list->tab, "%");
	else
		ft_strcpy(list->tab + list->vlc - 1, "%");
	return (1);
}
