/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:25:55 by darbib            #+#    #+#             */
/*   Updated: 2020/01/04 15:17:51 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	(*g_convert[128])(t_buf*, t_conv*, va_list);

static void		init_conv(t_conv *conv)
{
	conv->lmc = -1;
	conv->prec = -1;
	conv->size = "default";
	conv->flags = 0;
}

static void		init_g_convert()
{
	g_convert[(int)'c'] = c_convert; 
	g_convert[(int)'s'] = s_convert; 
/*
	g_convert[(int)'p'] = p_convert; 
	g_convert[(int)'d'] = d_convert; 
	g_convert[(int)'i'] = i_convert; 
	g_convert[(int)'u'] = u_convert; 
	g_convert[(int)'x'] = x_convert; 
	g_convert[(int)'X'] = bigx_convert; 
	g_convert[(int)'%'] = pct_convert; 
*/
}

/*
** managing sizes
*/

static char		*conv_size(const char **format)
{
	if (**format == 'l' && *(*format + 1) == 'l')
	{
		*format += 2;
		return ("larger");
	}
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		*format += 2;
		return ("shorter");
	}
	if (**format == 'l')
	{
		(*format)++;
		return ("large");
	}
	if (**format == 'h')
	{
		(*format)++;
		return ("short");
	}
	return ("default");
}

/*
** conversion input parsing to fill conversion state
*/

void			conv_parse(const char **format, va_list args, t_conv *conv)
{
	int option;

	init_conv(conv);
	while (*(++*format))
	{
		if (!is_true_option(**format) && !ft_isdigit(**format))
			break;
		if ((option = is_my_option(**format)) > -1)
			conv->flags += 1 << option;
		if (ft_isdigit(**format))
			conv->lmc = atoi_spe(format);
		if (**format == '*')
			conv->lmc = va_arg(args, int);
		if (**format == '.' && ft_isdigit(*(*format + 1)))
		{
			(*format)++;
			conv->prec = atoi_spe(format);
		}
		if (**format == '.' && *(*format + 1) == '*')
		{
			conv->prec = va_arg(args, int);
			(*format)++;
		}
	}
	conv->size = conv_size(format);
}

/*
** if the conversion flag exists and is managed by current version
** of printf, the adequate processing function is called
** priority of minus over zero option flag is implemented here 
*/

int				conv_make(const char **format, va_list args, t_conv *conv,
				t_buf *buf) 
{
	init_g_convert();
	if (conv->flags == 3)
		conv->flags = 1;
	if (ft_strchr(CONV_S, **format))
	{
		if (g_convert[(int)**format](buf, conv, args) == -1)
			return (-1);
	}
	/*
	else
		no_convert(buf, conv, **format);
	*/
	(*format)++;
	return (0);
}
