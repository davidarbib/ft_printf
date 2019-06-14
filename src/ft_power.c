/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 09:08:00 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/11 09:08:07 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	power(int multiplier, int multiplicateur)
{
	int	i;
	int	result;

	i = 1;
	result = multiplier;
	if (multiplicateur == 0)
		return (1);
	while (i < multiplicateur)
	{
		result *= multiplier;
		i += 1;
	}
	return (result);
}
