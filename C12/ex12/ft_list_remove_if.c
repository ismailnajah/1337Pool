/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:35:38 by inajah            #+#    #+#             */
/*   Updated: 2024/07/15 12:54:36 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void
		(*free_fct)(void *))
{
	t_list	*curr;
	t_list	*next;
	t_list	*prev;

	curr = *begin_list;
	prev = NULL;
	while (curr)
	{
		next = curr->next;
		if ((*cmp)(curr->data, data_ref) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				*begin_list = curr->next;
			(*free_fct)(curr->data);
			free(curr);
		}
		else
			prev = curr;
		curr = next; 
	}
}

