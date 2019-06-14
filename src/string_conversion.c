/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:19:47 by darbib            #+#    #+#             */
/*   Updated: 2019/05/27 15:53:14 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static char	*create_model(int precision, char *str, int len)
{
	char	*model_s;

	if (precision != -1)
	{
		if (precision > len)
			precision = len;
		model_s = ft_strsub(str, 0, precision);
	}
	else
		model_s = ft_strdup(str);
	return (model_s);
}

int			string_conversion(t_plist *list, va_list arg)
{
	int		vlc;
	char	*tmp_s;
	char	*model_s;
	int		i;

	tmp_s = (char *)va_arg(arg, char *);
	if (!tmp_s)
		tmp_s = "(null)";
	i = ft_strlen(tmp_s);
	model_s = create_model(list->precision, tmp_s, i);
	vlc = higher_value(0, list->width, ft_strlen(model_s));
	if (!(list->tab = ft_strnew(vlc)))
		return (0);
	space_filling(list->tab, vlc);
	if (list->flag & MINUS_FLAG)
		ft_strcpy(list->tab, model_s);
	else
		ft_strcpy(list->tab + vlc - ft_strlen(model_s), model_s);
	free(model_s);
	list->vlc = vlc;
	return (1);
}
