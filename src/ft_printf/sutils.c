/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:27:42 by darbib            #+#    #+#             */
/*   Updated: 2019/12/23 11:52:59 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sprintf.h"

void 		sfill_buffer(t_buf *buf, size_t nb, char c)
{
	while (nb > 0)
	{
		buf->s[buf->i++] = c;
		scheck_full(buf);
		nb--;
	}
	(void)nb;
}
