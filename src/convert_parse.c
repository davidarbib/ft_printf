/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:55:16 by pauljull          #+#    #+#             */
/*   Updated: 2019/05/29 15:50:21 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

void		convert_option(const char *restrict format, t_plist *list,
			int *i_ptr)
{
	int i;

	i = *i_ptr;
	while (format[i] == '0' || format[i] == '-' || format[i] == '+'
	|| format[i] == '#' || format[i] == ' ')
	{
		if (format[i] == '#' && !(list->flag & SHARP_FLAG))
			list->flag += SHARP_FLAG;
		if (format[i] == '0' && !(list->flag & ZERO_FLAG))
			list->flag += ZERO_FLAG;
		if (format[i] == ' ' && !(list->flag & SPACE_FLAG))
			list->flag += SPACE_FLAG;
		if (format[i] == '+' && !(list->flag & PLUS_FLAG))
			list->flag += PLUS_FLAG;
		if (format[i] == '-' && !(list->flag & MINUS_FLAG))
			list->flag += MINUS_FLAG;
		i += 1;
	}
	*i_ptr = i;
}

void		convert_lmc_width(const char *restrict format,
							t_plist *list, int *i_ptr)
{
	int i;

	i = *i_ptr;
	if (seek_conversion(format + i, 's'))
		list->width = -1;
	if (format[i] >= '1' && format[i] <= '9')
		list->width = ft_atoi(&format[i]);
	while (format[i] >= '0' && format[i] <= '9')
		i += 1;
	if (format[i] == '.')
	{
		i += 1;
		if (format[i] >= '1' && format[i] <= '9')
			list->precision = ft_atoi(&format[i]);
	}
	else
		list->precision = -1;
	while (format[i] >= '0' && format[i] <= '9')
		i += 1;
	*i_ptr = i;
}

int			convert_size(const char *restrict format, t_plist *list,
			int *i_ptr)
{
	int i;

	i = *i_ptr;
	if (format[i] == 'L')
		if (!set_option(list, &format[i++]))
			return (0);
	if (format[i] == 'l')
		if (!set_option(list, &format[i++]))
			return (0);
	if (format[i] == 'h')
		if (!set_option(list, &format[i++]))
			return (0);
	if ((list->flag & MINLL_FLAG) || (list->flag & HH_FLAG))
		i += 1;
	*i_ptr = i;
	return (1);
}

void		convert_type(const char *restrict format, t_plist *list,
			int i)
{
	if (format[i] == 'c')
		list->flag += C_FLAG;
	else if (format[i] == 's')
		list->flag += S_FLAG;
	else if (format[i] == 'p')
		list->flag += P_FLAG;
	else if (format[i] == 'd')
		list->flag += D_FLAG;
	else if (format[i] == 'i')
		list->flag += I_FLAG;
	else if (format[i] == 'o')
		list->flag += O_FLAG;
	else if (format[i] == 'u')
		list->flag += U_FLAG;
	else if (format[i] == 'x')
		list->flag += X_FLAG;
	else if (format[i] == 'X')
		list->flag += BIGX_FLAG;
	else if (format[i] == 'f')
		list->flag += F_FLAG;
	else if (format[i] == '%')
		list->flag += PCT_FLAG;
}

int			convert_flag(const char *restrict format,
			t_plist **list_ptr, int *i_ptr)
{
	int		i;
	t_plist	*list;
	t_plist	*head;

	i = *i_ptr + 1;
	list = ft_list_push_back(*list_ptr, 0, 0, 0);
	head = list;
	while (list->next)
		list = list->next;
	convert_option(format, list, &i);
	if (!(check_step_parse(format, i, 1)))
		return (0);
	convert_lmc_width(format, list, &i);
	if (!(check_step_parse(format, i, 2)))
		return (0);
	if (!convert_size(format, list, &i))
		return (0);
	if (!(check_step_parse(format, i, 3)))
		return (0);
	convert_type(format, list, i);
	*i_ptr = i;
	*list_ptr = head;
	return (1);
}
