/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:42:25 by inajah            #+#    #+#             */
/*   Updated: 2024/07/10 20:49:43 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int main(int ac, char **av)
{
	int	success;
	int	offset;

	if (ac == 1)
		return (ft_tail_read(0));
	if (av[1][1])
	{
		if (av[1][0] == '-' && av[1][1] == 'c')
		{
			//TODO: handle space between -c and the value of the offset
			success = ft_get_offset(&offset, av);
			if (!success)
				return (1);
			if (ac == 2)
				return (ft_tail_read(offset));
			return (ft_tail_files(ac, av, offset));
		}
	}
	if ((av[1][0] == '-' && av[1][1] == '\0') || av[1][0] != '-')
		return (ft_tail_files(ac, av, -1));
	if (av[1][0] == '-' && av[1][1] != 'c')
	{
		ft_error(basename(av[0]));
		ft_error(": ");
		ft_error("illegal option -- ");
		write(STDERR, av[1] + 1, 1);
		ft_error("\n");
		return (1);
	}
}
