/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:35:39 by inajah            #+#    #+#             */
/*   Updated: 2024/07/14 16:48:05 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int			i;
	t_list	*head;
	t_list	*node;

	i = 0;
	head = NULL;
	while (i < size)
	{
		node = malloc(sizeof(struct s_list));
		if(!node)
			return (head);
		node->data = strs[i];
		node->next = head;
		head = node;
		i++;
	}
	return (head);
}
