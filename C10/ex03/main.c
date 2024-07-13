/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:29:50 by inajah            #+#    #+#             */
/*   Updated: 2024/07/13 14:54:33 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	main(int ac, char **av)
{
	int	err;
	t_stream stream;

	stream.index = 1;
	stream.row = 0;
	stream.cursor= 0;

	if (ac == 1)
	{
		ft_hexdump_read(STDIN, &stream, 0);
		ft_print_int_as_hex(stream.row + stream.index % LINE_SIZE);
		ft_putchar('\n');
	}
	else
	{
		if (av[1][0] == '-' && av[1][1] == 'C')
		{
			if (ac > 2)
			{
				stream.index = 2;
				err = ft_hexdump_files(ac, av, &stream, 1);
				if (err)
					return (FAILURE);
			}
			else
				return (ft_hexdump_read(STDIN, &stream, 1));
		}
		else
		{
			err = ft_hexdump_files(ac, av, &stream, 0);
			if (err)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}
