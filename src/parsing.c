/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:34:24 by pauljull          #+#    #+#             */
/*   Updated: 2019/05/29 18:16:10 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "../include/ft_printf.h"

int			is_size(int flag)
{
	int mask;

	mask = MINL_FLAG;
	while (mask != SHARP_FLAG)
	{
		if (mask & flag)
			return (0);
		mask <<= 1;
	}
	return (1);
}

int			set_option(t_plist *list, const char *restrict format)
{
	if (!is_size(list->flag))
		return (0);
	if (*format == 'L')
		list->flag += MAJL_FLAG;
	else if (*format == 'l')
	{
		if (*(format + 1) == 'l')
			list->flag += MINLL_FLAG;
		else
			list->flag += MINL_FLAG;
	}
	else if (*format == 'h')
	{
		if (*(format + 1) == 'h')
			list->flag += HH_FLAG;
		else
			list->flag += H_FLAG;
	}
	return (1);
}

int			check_step_parse(const char *restrict format, int i, int step)
{
	if (step == 1 && ((format[i] < '1' || format[i] > '9') && format[i] != '.'
	&& format[i] != 'l' && format[i] != 'L' && format[i] != 'h')
	&& !is_conv(format[i]))
		return (0);
	if (step == 2 && (format[i] != 'l' && format[i] != 'L' && format[i] != 'h')
	&& !is_conv(format[i]))
		return (0);
	if (step == 3 && !is_conv(format[i]))
		return (0);
	return (1);
}

void		correct_parse(t_plist *list)
{
	while (list)
	{
		if (list->flag & ZERO_FLAG)
			if (list->precision != -1 || list->flag & MINUS_FLAG)
				list->flag -= ZERO_FLAG;
		if (list->flag & SPACE_FLAG)
			if (list->flag & PLUS_FLAG)
				list->flag -= SPACE_FLAG;
		if (list->flag & MINLL_FLAG)
			list->flag = list->flag - MINLL_FLAG + MINL_FLAG;
		list = list->next;
	}
}

int			parsing(const char *restrict format, t_plist **list_ptr, int *count)
{
	int		i;
	t_plist	*list;

	i = 0;
	list = *list_ptr;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			if (!(convert_flag(format, &list, &i)))
				return (0);
			*count -= 1;
		}
		*count += 1;
		i += 1;
	}
	correct_parse(list);
	*list_ptr = list;
	return (1);
}
