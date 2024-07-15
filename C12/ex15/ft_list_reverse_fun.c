/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:39:41 by inajah            #+#    #+#             */
/*   Updated: 2024/07/15 20:09:06 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

t_list	*ft_get_elem_at(t_list *begin_list, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (begin_list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		list_len;
	t_list	*elem;
	t_list	*node;
	void	*tmp;

	list_len = ft_size(begin_list);
	node = begin_list;
	i = 0;
	while (i < list_len / 2)
	{
		elem = ft_get_elem_at(begin_list, list_len - 1 - i);
		tmp = node->data;
		node->data = elem->data;
		elem->data = tmp;
		node = node->next;
		i++;
	}
}
