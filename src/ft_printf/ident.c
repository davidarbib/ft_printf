/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ident.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:18:24 by darbib            #+#    #+#             */
/*   Updated: 2019/12/09 16:40:40 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		is_my_option(char c)
{
	char	*s;
	char	*p_s;

	s = OPTS_MY;
	if ((p_s = ft_strchr(s, c)))
		return (p_s - s);
	return (-1);
}

char	is_true_option(char c)
{
	if (ft_strchr(OPTS_TRUE, c))
		return (1);
	return (0);
}
