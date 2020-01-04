/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:26:40 by darbib            #+#    #+#             */
/*   Updated: 2020/01/04 15:30:23 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

void	buf_flush(t_buf *buf)
{
	write(STDOUT, buf->s, buf->i);
	ft_bzero(buf->s, BUF_SIZE);
	buf->count += buf->i;
	buf->i = 0;
}

void	check_full(t_buf *buf)
{
	if (buf->i == BUF_SIZE)
		buf_flush(buf);
}

void	init_buf(t_buf *buf)
{
	ft_bzero(buf->s, BUF_SIZE);
	buf->count = 0;
	buf->i = 0;
}

void	write_into(t_buf *buf, char **str)
{
	char *p_str;

	p_str = *str;
	while (*p_str)
	{
		buf->s[(buf->i)++] = *p_str++;
		check_full(buf);
	}
	free(*str);
	*str = NULL;
}
