/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:47:11 by pauljull          #+#    #+#             */
/*   Updated: 2018/12/04 22:14:28 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		print_bit(char c)
{
	char	index;

	index = 7;
	while (index >= 0)
	{
		if (n_bit_value(c, index) == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		index -= 1;
	}
}
