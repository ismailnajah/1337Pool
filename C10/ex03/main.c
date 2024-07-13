/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:29:50 by inajah            #+#    #+#             */
/*   Updated: 2024/07/13 11:06:40 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	main(int ac, char **av)
{
	int	err;

	if (ac == 1)
		return (ft_hexdump_read(STDIN, 0));
	else
	{
		if (av[1][0] == '-' && av[1][1] == 'C')
		{
			if (ac > 2)
			{
				err = ft_hexdump_files(ac, av, 2, 1);
				if (err)
					return (FAILURE);
			}
			else
				return (ft_hexdump_read(STDIN, 1));
		}
		else
		{
			err = ft_hexdump_files(ac, av, 1, 0);
			if (err)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}
