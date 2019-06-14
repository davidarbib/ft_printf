/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:56:55 by pauljull          #+#    #+#             */
/*   Updated: 2019/04/23 16:57:06 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_str_rev_cpy(char *s1, char *s2)
{
	int			i;
	int			s1_len;
	int			s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	if (s2_len > s1_len)
		return ;
	if (!s1 || !s2)
		return ;
	while (s2[i])
	{
		s1[s1_len - s2_len + i] = s2[i];
		i += 1;
	}
}
