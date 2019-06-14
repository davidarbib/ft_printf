/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 21:28:52 by pauljull          #+#    #+#             */
/*   Updated: 2019/01/02 20:41:46 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	c_buff;
	unsigned char	*dst_buff;
	unsigned char	*src_buff;

	index = 0;
	c_buff = (unsigned char)c;
	dst_buff = (unsigned char *)dst;
	src_buff = (unsigned char *)src;
	while (index < n)
	{
		if (((unsigned char *)src)[index] == c_buff)
		{
			((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
			return (&((unsigned char *)dst)[index + 1]);
		}
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index += 1;
	}
	return (NULL);
}
