/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 08:42:11 by pauljull          #+#    #+#             */
/*   Updated: 2019/01/02 15:55:31 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void	ft_print_lst(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		write(1, lst->content, lst->content_size);
		lst = lst->next;
	}
}
