/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:47:08 by darbib            #+#    #+#             */
/*   Updated: 2019/12/10 11:28:37 by darbib           ###   ########.fr       */
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

int			ft_sprintf(char *buf_out, const char *format, ...)
{
	va_list args;
	t_buf	buf;
	t_conv	conv;
	
	if (!format || !*format)
		return (0);
	va_start(args, format);
	sinit_buf(&buf, buf_out);
	while (*format)
	{
		if (*format != '%')
			buf.s[buf.i++] = *(format++);
		else
		{
			sbuf_flush(&buf, buf_out);
			conv_parse(&format, args, &conv);
/*
			if ((conv_make(**format, args, &buf)) < 0)
				return (-1);
*/
		}
		if (buf.i == BUF_SIZE)
			sbuf_flush(&buf, buf_out);
	}
	sbuf_flush(&buf, buf_out);
	va_end(args);
	return (buf.count);
}

int main()
{
	//printf(NULL);
	//ft_printf("hi i love coding and you ?");
	//ft_printf("%10.0dun test\n");
	char *str2 = calloc(BUFOUT_SIZE, sizeof(char));

	printf("ret : %d\n", sprintf(str2, "cestuntest\n"));
	printf("ret : %d\n", sprintf(str2, "ok\n"));
	printf("%s\n", str2);
	return (0);
}
