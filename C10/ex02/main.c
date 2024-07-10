/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:42:25 by inajah            #+#    #+#             */
/*   Updated: 2024/07/10 15:50:31 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int main(int ac, char **av)
{
	int	err;
	int	offset;

	if (ac == 1)
	{
		ft_tail_read();
		return (0);
	}
	err = ft_get_offset(&offset, av[1]);
	return (0);
}
