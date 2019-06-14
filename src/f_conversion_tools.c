/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conversion_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:44:05 by darbib            #+#    #+#             */
/*   Updated: 2019/05/27 16:08:57 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>

/*
** add loop
** returns 1 if theres a empty char at beginning of string
*/

static int			operate(char *res, char *src, int len)
{
	int				i;
	int				tmp;
	unsigned int	ret;

	i = len;
	ret = 0;
	while (--i > 1)
	{
		if (src[i])
		{
			tmp = src[i] - '0' + res[i] - '0' + ret;
			ret = tmp / 10;
			res[i] = (tmp % 10) + '0';
		}
	}
	if (ret)
	{
		res[0] = '1';
		return (0);
	}
	return (1);
}

/*
** align strings to compute add
** with the above static
** left drift the result string if theres no
** carry at left
*/

char				*add_str(char *s1, char *s2)
{
	char			*s_res;
	char			*p_s;
	int				top_size;
	int				bot_size;
	int				i;

	top_size = ft_strlen(s1);
	bot_size = ft_strlen(s2);
	p_s = s1;
	if (bot_size > top_size)
	{
		i = top_size;
		top_size = bot_size;
		bot_size = i;
		p_s = s2;
	}
	if (!(s_res = ft_strnew(top_size)))
		return (NULL);
	ft_strcpy(s_res, p_s);
	p_s = (p_s == s1) ? s2 : s1;
	operate(s_res, p_s, bot_size);
	return (s_res);
}

static int			operate_addm(char *res, char *src, int len, int diff)
{
	int				i;
	int				tmp;
	unsigned int	ret;

	i = len;
	ret = 0;
	while (--i > -1)
	{
		if (src[i])
		{
			tmp = src[i] - '0' + res[i + diff] - '0' + ret;
			ret = tmp / 10;
			res[i + diff] = (tmp % 10) + '0';
		}
	}
	if (ret)
	{
		res[0] = '1';
		return (0);
	}
	return (1);
}

static void			ft_swap(int *a, int *b)
{
	int				tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

char				*add_str_mult(char *s1, char *s2)
{
	char			*s_res;
	char			*p_s;
	int				top_size;
	int				bot_size;

	top_size = ft_strlen(s1);
	bot_size = ft_strlen(s2);
	p_s = s1;
	if (bot_size > top_size)
	{
		ft_swap(&top_size, &bot_size);
		p_s = s2;
	}
	if (!(s_res = ft_strnew(top_size)))
		return (NULL);
	ft_strcpy(s_res + 1, p_s);
	p_s = (p_s == s1) ? s2 : s1;
	if (operate_addm(s_res, p_s, bot_size, top_size - bot_size + 1))
	{
		ft_memmove(s_res, s_res + 1, top_size);
		s_res[top_size] = 0;
	}
	return (s_res);
}
