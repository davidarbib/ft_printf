/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 21:58:48 by darbib            #+#    #+#             */
/*   Updated: 2019/12/19 17:39:39 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"
#include "libft.h"
#include <unistd.h>

extern char	*g_buf_out;

void	sbuf_flush(t_buf *buf)
{
	ft_strlcat(g_buf_out, buf->s, BUFOUT_SIZE);
	ft_bzero(buf->s, BUF_SIZE);
	buf->count += buf->i;
	buf->i = 0;
}

void	scheck_full(t_buf *buf)
{
	if (buf->i == BUF_SIZE)
		sbuf_flush(buf);
}

void	sinit_buf(t_buf *buf)
{
	ft_bzero(buf->s, BUF_SIZE);
	ft_bzero(g_buf_out, BUFOUT_SIZE); 
	buf->count = 0;
	buf->i = 0;
}
