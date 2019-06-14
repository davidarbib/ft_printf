/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:51:34 by darbib            #+#    #+#             */
/*   Updated: 2019/05/25 22:23:56 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

static int		s_management(char **new_str, char *s1, char *s2, long n2)
{
	if (s1 == NULL)
	{
		if (!(*new_str = ft_strndup(s2, (size_t)n2)))
			return (-1);
		return (1);
	}
	return (0);
}

char			*ft_join(char *s1, char *s2, long n1, long n2)
{
	char	*new_str;

	if (s_management(&new_str, s1, s2, n2) != 0)
		return (new_str);
	if (!(new_str = (char *)malloc(sizeof(char) * (n1 + n2 + 1))))
		return (NULL);
	ft_memmove(new_str, s1, n1);
	ft_memmove(new_str + n1, s2, n2);
	new_str[n1 + n2] = 0;
	free(s1);
	return (new_str);
}
