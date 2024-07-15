/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:59:13 by inajah            #+#    #+#             */
/*   Updated: 2024/07/15 10:10:02 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*node;

	i = 0;
	node = begin_list;
	while (i < nbr)
	{
		if (node)
			node = node->next;
		else
			return (NULL);
		i++;
	}
	return (node);
}
