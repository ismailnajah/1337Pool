/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:58:38 by inajah            #+#    #+#             */
/*   Updated: 2024/07/16 15:01:48 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*node;

	elem = ft_create_elem(data);
	node = *begin_list;
	if (!node)
	{
		*begin_list = elem;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = elem;
}
