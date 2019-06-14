/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:18:12 by pauljull          #+#    #+#             */
/*   Updated: 2018/11/26 17:00:51 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	n_index;
	char	*h_buff;
	char	*n_buff;

	index = 0;
	n_index = 0;
	h_buff = (char *)haystack;
	n_buff = (char *)needle;
	if (*n_buff == '\0')
		return (h_buff);
	while (index < len && *h_buff)
	{
		while (h_buff[n_index] == n_buff[n_index] &&
			(index + n_index) < len && n_buff[n_index] != 0)
			n_index += 1;
		if (n_buff[n_index] == 0)
			return (h_buff);
		n_index = 0;
		h_buff += 1;
		index += 1;
	}
	return (NULL);
}
