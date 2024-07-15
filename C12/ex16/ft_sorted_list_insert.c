/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:21:11 by inajah            #+#    #+#             */
/*   Updated: 2024/07/15 21:12:22 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_elem(void *data)
{
	t_list	*node;

	node = malloc(sizeof(struct s_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*node;
	t_list	*prev;
	t_list	*elem;

	elem = ft_elem(data);
	node = *begin_list;
	if (!node)
	{
		*begin_list = elem;
		return ;
	}
	prev = NULL;
	while (node)
	{
		if ((*cmp)(node->data, elem->data) >= 0)
			break ;
		prev = node;
		node = node->next;
	}
	elem->next = node;
	if (!prev)
		*begin_list = elem;
	else
		prev->next = elem;
}
