/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:25:55 by darbib            #+#    #+#             */
/*   Updated: 2019/12/09 16:29:07 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void init_conv(t_conv *conv)
{
	conv->lmc = -1;
	conv->prec = -1;
	conv->flags = 0;
}

void conv_parse(const char **format, va_list args, t_conv *current_conv)
{
	int option;

	init_conv(current_conv);
	while (*(++*format))
	{
		if (!is_true_option(**format) && !ft_isdigit(**format))
			break;
		if ((option = is_my_option(**format)) > -1)
			current_conv->flags += 1 << option;
		if (ft_isdigit(**format))
			current_conv->lmc = atoi_spe(format);
		if (**format == '*')
			current_conv->lmc = va_arg(args, int);
		if (**format == '.' && ft_isdigit(*(*format + 1)))
		{
			(*format)++;
			current_conv->prec = atoi_spe(format);
		}
		if (**format == '.' && *(*format + 1) == '*')
		{
			current_conv->prec = va_arg(args, int);
			(*format)++;
		}
	}
}
