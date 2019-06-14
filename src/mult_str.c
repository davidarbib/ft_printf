/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:12:27 by darbib            #+#    #+#             */
/*   Updated: 2019/05/27 15:56:17 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdlib.h>

/*
** create a new str :
** appends correct number of zeros to the new computed str
** and add with older
** all ingredients are freed after that
*/

static char			*add_lines(char *s1, char *s2, int nb_0)
{
	char			*s_res;
	char			*s_tmp;
	int				len;

	len = ft_strlen(s2);
	if (!(s_tmp = ft_strnew(len + nb_0)))
		return (NULL);
	ft_strcpy(s_tmp, s2);
	free(s2);
	nb_0++;
	while (--nb_0)
		s_tmp[len - 1 + nb_0] = '0';
	s_res = add_str_mult(s_tmp, s1);
	free(s1);
	free(s_tmp);
	return (s_res);
}

/*
** create a new str
** replace the dot on float
** ingredient is freed
*/

static char			*add_dot(char *s, int mtslen, unsigned int dotpos)
{
	char			*s_res;
	int				i;
	int				len;
	int				dot;

	len = ft_strlen(s);
	if (!(s_res = ft_strnew(len + 1)))
		return (NULL);
	s_res[len - (mtslen - dotpos) + 1] = '.';
	dot = 0;
	i = 0;
	while ((i - dot) < len)
	{
		if (s_res[i] != '.')
			s_res[i] = s[i - dot];
		else
			dot = 1;
		i++;
	}
	free(s);
	return (s_res);
}

/*
** remove the dot of float string and copy to the returned fresh string
** place dot index in dotpos argument
*/

static char			*rm_dot(char *m, int len, unsigned int *dotpos)
{
	char			*s_nodot;
	int				i;
	int				dot;

	s_nodot = ft_strnew(len - 1);
	i = 0;
	dot = 0;
	while (m[i + dot])
	{
		if (m[i + dot] == '.')
		{
			*dotpos = i;
			dot = 1;
		}
		s_nodot[i] = m[i + dot];
		i++;
	}
	free(m);
	return (s_nodot);
}

/*
** create a new str :
** multiply the mantissa with one digit of exponent
*/

static char			*operate_mult(char *m, unsigned int dig, int len)
{
	char			*res;
	unsigned int	tmp;
	unsigned int	ret;
	int				i;

	i = len + 1;
	if (!(res = ft_strnew(i)))
		return (NULL);
	ret = 0;
	while (--i > 0)
	{
		tmp = (m[i - 1] - '0') * dig + ret;
		ret = tmp / 10;
		res[i] = (tmp % 10) + '0';
	}
	if (ret)
	{
		res[0] = ret + '0';
		return (res);
	}
	ft_memmove(res, res + 1, len + 1);
	return (res);
}

/*
** return a fresh string containing
** the product of mantissa m by exponent e
** the computing is done without the dot
** which is replaced on the end of process
*/

char				*mult_str(char *m, unsigned long e)
{
	char			*s_res;
	char			*s_tmp;
	unsigned int	dotpos;
	unsigned int	nb_0;
	int				len;

	len = ft_strlen(m);
	s_res = ft_strdup("0");
	m = rm_dot(m, len, &dotpos);
	nb_0 = 0;
	while (e >= 1)
	{
		s_tmp = operate_mult(m, (unsigned int)(e % 10), len - 1);
		s_res = add_lines(s_res, s_tmp, nb_0);
		e /= 10;
		nb_0++;
	}
	s_res = add_dot(s_res, len, dotpos);
	return (s_res);
}
