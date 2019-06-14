/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:30:14 by darbib            #+#    #+#             */
/*   Updated: 2019/05/27 16:11:34 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdlib.h>
#include "../libft/libft.h"

/*
** %c conversion main function
** feed the flag node with char filled tab
** return 1 if success 0 else
*/

int			char_conversion(t_plist *list, va_list arg)
{
	int		vlc;
	char	c;

	vlc = higher_value(0, list->width, 1);
	if (!(list->tab = ft_strnew(vlc)))
		return (0);
	space_filling(list->tab, vlc);
	c = (char)va_arg(arg, int);
	if (list->flag & MINUS_FLAG)
		list->tab[0] = c;
	else
		list->tab[vlc - 1] = c;
	list->vlc = vlc;
	return (1);
}
