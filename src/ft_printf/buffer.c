/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:26:40 by darbib            #+#    #+#             */
/*   Updated: 2019/12/09 16:28:12 by darbib           ###   ########.fr       */
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

void	init_buf(t_buf *buf)
{
	ft_bzero(buf->s, BUF_SIZE);
	buf->count = 0;
	buf->i = 0;
}
