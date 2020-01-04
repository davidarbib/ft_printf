/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 21:34:29 by darbib            #+#    #+#             */
/*   Updated: 2020/01/04 15:22:31 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		s_convert(t_buf *buf, t_conv *conv, va_list args)
{
	char	filler;
	char	*str;
	char	*substr;
	size_t	len;

	filler = ' ';
	if (conv->lmc < 1)
		conv->lmc = 0;
	if (conv->flags & ZERO)
		filler = '0';
	str = va_arg(args, char *);
	if (!str)
		str = "";
	len = ft_strlen(str);
	if (conv->prec < 0 || conv->prec < (signed int)len)
		conv->prec = len;
	if (!(conv->flags & MINUS) && conv->lmc > (signed int)len)
		fill_buffer(buf, conv->lmc - len, filler);
	check_full(buf);
	substr = ft_substr(str, 0, conv->prec);
	write_into(buf, &substr);
	filler = ' ';
	if (conv->flags & MINUS && conv->lmc > (signed int)len)
		fill_buffer(buf, conv->lmc - len, filler);
	return (1);
}
