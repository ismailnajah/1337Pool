/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:58:38 by inajah            #+#    #+#             */
/*   Updated: 2024/07/14 16:30:43 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*node;

	elem = malloc(sizeof(struct s_list));
	if (!elem)
		return ;
	elem->data = data;
	elem->next = NULL;
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
