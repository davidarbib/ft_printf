/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:20:38 by darbib            #+#    #+#             */
/*   Updated: 2019/12/13 16:38:32 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
** on lit le format, 
** on deverse son contenu dans buffer
** si buffer plein ou % rencontre on flush le buffer
** si % rencontre on continue a lire le format 
** et on parse les options, LMC, precision
** jusqua arriver a un char non option ou chiffre
*/

int			ft_printf(const char *format, ...)
{
	va_list args;
	t_buf	buf;
	t_conv	conv;
	
	if (!format || !*format)
		return (0);
	va_start(args, format);
	init_buf(&buf);
	while (*format)
	{
		if (*format != '%')
			buf.s[buf.i++] = *(format++);
		else
		{
			buf_flush(&buf);
			conv_parse(&format, args, &conv);
/*
			if ((conv_make(&format, args, &conv, &buf)) < 0)
				return (-1);
*/
		}
		if (buf.i == BUF_SIZE)
			buf_flush(&buf);
	}
	buf_flush(&buf);
	va_end(args);
	return (buf.count);
}
