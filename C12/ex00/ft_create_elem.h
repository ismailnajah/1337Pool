/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:19:11 by inajah            #+#    #+#             */
/*   Updated: 2024/07/14 15:24:19 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = malloc(sizeof(struct s_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}
