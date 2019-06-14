/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:50:18 by darbib            #+#    #+#             */
/*   Updated: 2019/05/24 12:06:07 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	unsigned int	index;
	char			*str;
	size_t			len;

	index = 0;
	len = ft_strlen(s);
	if (n > len)
		n = len;
	if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (index < n)
	{
		str[index] = s[index];
		index += 1;
	}
	str[index] = 0;
	return (str);
}
