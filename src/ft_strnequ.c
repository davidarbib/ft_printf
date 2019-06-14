/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:34:33 by pauljull          #+#    #+#             */
/*   Updated: 2018/11/15 10:50:45 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (s1 == NULL && s2 == NULL)
		return (1);
	if ((s1 == NULL || s2 == NULL) && (s1 != s2))
		return (0);
	while (s1[index] != 0 && s2[index] != 0 && index < n)
	{
		if (s1[index] != s2[index])
			return (0);
		index += 1;
	}
	if (s1[index] == s2[index] || index == n)
		return (1);
	return (0);
}
