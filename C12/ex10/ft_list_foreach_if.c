/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:58:44 by inajah            #+#    #+#             */
/*   Updated: 2024/07/15 11:15:29 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list	*node;

	node = begin_list;
	while (node)
	{
		if ((*cmp)(node->data, data_ref) == 0)
			(*f)(node->data);
		node = node->next;
	}
}
