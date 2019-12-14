/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:01:05 by darbib            #+#    #+#             */
/*   Updated: 2019/12/13 16:38:34 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

# define LOWERHEX	"0123456789abcdef"
# define UPPERHEX	"0123456789ABCDEF"
# define BUF_SIZE	101
# define STDOUT		1

# define CONV_S		"cspdiuxX"
# define CONV_NB	8
# define OPTS_TRUE	".-0+#* "
# define OPTS_MY	"-0"
# define OPTIONS_NB	2
# define ZERO		2
# define MINUS		1

/*
** buffer to print
*/

typedef struct	s_buf
{
	size_t	count;
	size_t	i;
	char	s[BUF_SIZE];
}				t_buf;

/*
** conversion data
** have 2 possible options flags
*/

typedef struct	s_conv
{
	int		lmc;	
	int		prec;
	char	*size;
	int		flags : OPTIONS_NB;
}				t_conv;


int		ft_printf(const char *format, ...);
int		is_my_option(char c);
char	is_true_option(char c);
void	init_buf(t_buf *buf);
void	buf_flush(t_buf *buf);
void 	conv_parse(const char **format, va_list args, t_conv *current_conv);
int		atoi_spe(const char **str);
int		c_convert(t_buf *buf, t_conv *conv, va_list args); 
int		s_convert(t_buf *buf, t_conv *conv, va_list args); 
int		p_convert(t_buf *buf, t_conv *conv, va_list args); 
int		d_convert(t_buf *buf, t_conv *conv, va_list args); 
int		i_convert(t_buf *buf, t_conv *conv, va_list args); 
int		u_convert(t_buf *buf, t_conv *conv, va_list args); 
int		x_convert(t_buf *buf, t_conv *conv, va_list args); 
int		bigx_convert(t_buf *buf, t_conv *conv, va_list args); 
#endif
