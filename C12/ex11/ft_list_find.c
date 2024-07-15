/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:31:42 by inajah            #+#    #+#             */
/*   Updated: 2024/07/15 11:35:17 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_fine(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*node;

	node = begin_list;
	while (node)
	{
		if ((*cmp)(node->data, data_ref) == 0)
			break ;
		node = node->next;
	}
	return (node);
}
