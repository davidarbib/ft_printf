/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:47:08 by darbib            #+#    #+#             */
/*   Updated: 2019/12/19 17:27:38 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"
#include "libft.h"
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

char		*g_buf_out;

int			ft_sprintf(char *buf_out, const char *format, ...)
{
	va_list args;
	t_buf	buf;
	t_conv	conv;
	
	g_buf_out = buf_out;
	if (!format || !*format)
		return (0);
	va_start(args, format);
	sinit_buf(&buf);
	while (*format)
	{
		if (*format != '%')
			buf.s[buf.i++] = *(format++);
		else
		{
			sbuf_flush(&buf);
			conv_parse(&format, args, &conv);
			if ((conv_make(&format, args, &conv, &buf)) < 0)
				return (-1);
		}
		scheck_full(&buf);
	}
	sbuf_flush(&buf);
	va_end(args);
	return (buf.count);
}
