/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:38:41 by inajah            #+#    #+#             */
/*   Updated: 2024/07/15 09:59:53 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next;

	while (begin_list)
	{
		next = begin_list->next;
		(*free_fct)(begin_list->data);
		free(begin_list);
		begin_list = next;
	}
}
