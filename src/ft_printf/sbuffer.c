/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 21:58:48 by darbib            #+#    #+#             */
/*   Updated: 2019/12/10 11:26:52 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"
#include "libft.h"
#include <unistd.h>

void	sbuf_flush(t_buf *buf, char *buf_out)
{
	ft_strlcat(buf_out, buf->s, BUFOUT_SIZE);
	ft_bzero(buf->s, BUF_SIZE);
	buf->count += buf->i;
	buf->i = 0;
}

void	sinit_buf(t_buf *buf, char *buf_out)
{
	ft_bzero(buf->s, BUF_SIZE);
	ft_bzero(buf_out, BUFOUT_SIZE); 
	buf->count = 0;
	buf->i = 0;
}
