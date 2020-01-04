/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:44:57 by darbib            #+#    #+#             */
/*   Updated: 2019/12/22 18:11:13 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPRINTF_H
# define FT_SPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "ft_printf.h"

# define BUFOUT_SIZE	100000000

int		ft_sprintf(char *buf_out, const char *format, ...);
void	scheck_full(t_buf *buf);
void	sbuf_flush(t_buf *buf);
void	sinit_buf(t_buf *buf);
void 	sfill_buffer(t_buf *buf, size_t nb, char c);

#endif
