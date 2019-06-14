/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:00:07 by pauljull          #+#    #+#             */
/*   Updated: 2019/05/28 22:16:58 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int				bypass_flag(const char *format)
{
	int			i;

	i = 0;
	while (!is_conv(format[i]))
		i += 1;
	return (i);
}

static char		*substitute(t_plist *list, t_pfinal *dt, char **format)
{
	dt->s_res = ft_join(dt->s_res, dt->ps_f, (dt->count - (*format - dt->ps_f)
				+ dt->len), *format - dt->ps_f);
	dt->s_res = ft_join(dt->s_res, list->tab, dt->count + dt->len, list->vlc);
	dt->len += list->vlc;
	*format += 1;
	*format += bypass_flag(*format);
	dt->ps_f = (char *)(*format + 1);
	return (dt->s_res);
}

static void		init_print(t_pfinal *dt)
{
	dt->count = 0;
	dt->len = 0;
	dt->s_res = NULL;
}

long			print_final(t_plist *list, const char *format)
{
	t_pfinal	*dt;

	if (!(dt = (t_pfinal *)malloc(sizeof(t_pfinal))))
		return (-1);
	dt->ps_f = (char *)format;
	init_print(dt);
	while (*format)
	{
		if (*format == '%')
		{
			dt->s_res = substitute(list, dt, (char **)&format);
			list = list->next;
		}
		else
			dt->count += 1;
		format++;
	}
	dt->s_res = ft_join(dt->s_res, dt->ps_f, (dt->count - (format - dt->ps_f))
						+ dt->len, format - dt->ps_f);
	write(1, dt->s_res, dt->count + dt->len);
	return (dt->count + dt->len);
}
