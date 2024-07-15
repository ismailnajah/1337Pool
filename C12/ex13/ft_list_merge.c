/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:39:07 by inajah            #+#    #+#             */
/*   Updated: 2024/07/15 13:43:00 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*node;

	if (!(*begin_list1))
		*begin_list1 = begin_list2;
	else
	{
		node = *begin_list1;
		while (node->next)
			node = node->next;
		node->next = begin_list2;
	}
}
