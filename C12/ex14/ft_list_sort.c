/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:56:32 by inajah            #+#    #+#             */
/*   Updated: 2024/07/15 20:19:24 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_list.h"

void	ft_swap(t_list **begin_list, t_list *prev, t_list *curr, t_list *next)
{
	if (!prev)
	{
		curr->next = next->next;
		next->next = curr;
		*begin_list = next;
	}
	else
	{
		prev->next = next;
		curr->next = next->next;
		next->next = curr;
	}
}

int	_ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		swaps;
	t_list	*curr;
	t_list	*next;
	t_list	*prev;

	swaps = 0;
	prev = NULL;
	curr = *begin_list;
	while (curr->next)
	{
		next = curr->next;
		if ((*cmp)(curr->data, next->data) > 0)
		{
			ft_swap(begin_list, prev, curr, next);
			swaps++;
			prev = next;
		}
		else
		{
			prev = curr;
			curr = next;
		}
	}
	return (swaps);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int	swaps;

	if (!(*begin_list))
		return ;
	swaps = 1;
	while (swaps)
		swaps = _ft_list_sort(begin_list, cmp);
}
