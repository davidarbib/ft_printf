/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:00:46 by darbib            #+#    #+#             */
/*   Updated: 2019/12/23 17:30:35 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"

int		c_convert(t_buf *buf, t_conv *conv, va_list args)
{
	char filler;

	filler = ' ';
	if (conv->lmc < 1)
		conv->lmc = 1;
	if (conv->flags & ZERO)
		filler = '0';
	if (!(conv->flags & MINUS))
		fill_buffer(buf, conv->lmc - 1, filler);
	buf->s[buf->i++] = (char)va_arg(args, int);
	check_full(buf);
	filler = ' ';
	if (conv->flags & MINUS)
		fill_buffer(buf, conv->lmc - 1, filler);
	return (1);
}
