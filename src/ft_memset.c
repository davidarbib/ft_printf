/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:49:41 by pauljull          #+#    #+#             */
/*   Updated: 2019/01/02 20:31:56 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s_buff;
	unsigned char	c_buff;

	s_buff = (unsigned char*)b;
	c_buff = (unsigned char)c;
	while (len-- > 0)
		*(s_buff++) = c_buff;
	return (b);
}
