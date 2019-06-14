/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:56:41 by pauljull          #+#    #+#             */
/*   Updated: 2019/05/28 22:20:33 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "../include/ft_printf.h"
#include <stdio.h>

int					tab_gen(t_plist *list, va_list arg)
{
	if (list->flag & D_FLAG || list->flag & I_FLAG)
		return (integer_d_i(list, arg));
	if (list->flag & O_FLAG || list->flag & U_FLAG
			|| list->flag & X_FLAG || list->flag & BIGX_FLAG)
		return (unsigned_u_o_x_bigx(list, arg));
	if (list->flag & C_FLAG)
		return (char_conversion(list, arg));
	if (list->flag & S_FLAG)
		return (string_conversion(list, arg));
	if (list->flag & P_FLAG)
		return (p_conversion(list, arg));
	if (list->flag & PCT_FLAG)
		return (percent_conversion(list));

	return (1);
}

int					fill_list(t_plist *list, va_list arg_list)
{
	while (list)
	{
		if (!tab_gen(list, arg_list))
			return (0);
		list = list->next;
	}
	return (1);
}

void				free_list(t_plist *list)
{
	t_plist			*tmp;

	tmp = NULL;
	while (list)
	{
		list->width = 0;
		list->precision = 0;
		list->flag = 0;
		ft_strdel(&(list->tab));
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

int					ft_printf(const char *restrict format, ...)
{
	t_plist			*list;
	va_list			arg_list;
	unsigned long	ret;
	int				count;

	list = NULL;
	ret = 0;
	count = 0;
	va_start(arg_list, format);
	if (!format)
		return (-1);
	if (!(parsing(format, &list, &count)))
		return (-1);
	if (!fill_list(list, arg_list))
		return (-1);
	va_end(arg_list);
	ret = print_final(list, (const char *)format);
	free_list(list);
	return (ret);

}
