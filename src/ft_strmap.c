/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:34:12 by pauljull          #+#    #+#             */
/*   Updated: 2018/12/22 15:09:44 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (s != NULL)
	{
		if (!(str = ft_strdup(s)))
			return (NULL);
	}
	else
		return (NULL);
	while (str[i] != 0)
	{
		str[i] = f(str[i]);
		i += 1;
	}
	return (str);
}
