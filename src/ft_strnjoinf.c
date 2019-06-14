/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:05:07 by darbib            #+#    #+#             */
/*   Updated: 2019/05/24 13:50:30 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		s_management(char **new_str, char *s1, char *s2, long n)
{
	if (s1 == NULL)
	{
		if (!(*new_str = ft_strndup(s2, (size_t)n)))
			return (-1);
		return (1);
	}
	else if (s2 == NULL)
	{
		if (!(*new_str = ft_strndup(s1, (size_t)n)))
			return (-1);
		return (2);
	}
	return (0);
}

char			*ft_strnjoinf(char *s1, char *s2, int flag, long n)
{
	char	*new_str;
	int		len_s1;
	int		len_s2;

	if (s_management(&new_str, s1, s2, n) != 0)
		return (new_str);
	len_s1 = ft_strlen(s1);
	if (!(new_str = (char *)malloc(sizeof(char) * (len_s1 + n + 1))))
		return (NULL);
	ft_strncpy(new_str, s1, len_s1);
	ft_strncpy(new_str + len_s1, s2, n);
	new_str[len_s1 + n] = 0;
	if (flag == 1 || flag == 3)
		free(s1);
	if (flag == 2 || flag == 3)
		free(s2);
	return (new_str);
}
