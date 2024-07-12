/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:29:50 by inajah            #+#    #+#             */
/*   Updated: 2024/07/12 10:37:39 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	main(int ac, char **av)
{
	int	err;

	if (ac == 1)
		return (ft_hexdump_read(STDIN, 0));

	if (ac == 2)
	{
		if (av[1][0] == '-' && av[1][1] == 'C')
		{
			if (ac > 2)
			{
				// here make ft_hexdump_files 
				err = ft_hexdump_file(av[2], 1);
				if (err)
					return (ft_hexdump_error(av[0], av[1], err));
			}
			else
				return (ft_hexdump_read(STDIN, 1));
		}
		else
		{
			err = ft_hexdump_file(av[1], 0);
			if (err)
				return (ft_hexdump_error(av[0], av[1], err));
		}
	}
	return (0);
}
