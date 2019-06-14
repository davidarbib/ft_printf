/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:57:08 by pauljull          #+#    #+#             */
/*   Updated: 2018/12/07 10:48:46 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*new;
	t_list	*buff;

	buff = NULL;
	new = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		buff = f(lst);
		ft_lst_push_back(&new, buff->content, buff->content_size);
		free(buff);
		lst = lst->next;
	}
	return (new);
}
