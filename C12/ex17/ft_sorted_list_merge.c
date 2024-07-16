/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:43:41 by inajah            #+#    #+#             */
/*   Updated: 2024/07/16 09:30:23 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_update_head(t_list **head1, t_list *head2)
{
	*head1 = head2;
	return ;
}

void	ft_list_relink(t_list **head, t_list **node1,
		t_list **node2, t_list **prev)
{
	t_list	*tmp;

	tmp = (*node2)->next;
	if (!(*prev))
	{
		(*node2)->next = *node1;
		*head = *node2;
	}
	else
	{
		(*prev)->next = *node2;
		(*node2)->next = *node1;
	}
	*prev = *node1;
	*node1 = *node2;
	*node2 = tmp;
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	t_list	*node1;
	t_list	*node2;
	t_list	*prev;

	if (!(*begin_list1))
		return (ft_list_update_head(begin_list1, begin_list2));
	node1 = *begin_list1;
	node2 = begin_list2;
	prev = NULL;
	while (node1 && node2)
	{
		if ((*cmp)(node1->data, node2->data) >= 0)
			ft_list_relink(begin_list1, &node1, &node2, &prev);
		else
		{
			prev = node1;
			node1 = node1->next;
		}
	}
	if (node2)
		prev->next = node2;
}
