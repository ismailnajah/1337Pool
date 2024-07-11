/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:42:25 by inajah            #+#    #+#             */
/*   Updated: 2024/07/11 09:51:02 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_tail_parse_arg(int ac, char **av, int *nbytes, int *p_shift)
{
	*nbytes = 0;
	*p_shift = 0;
	if (av[1][2])
		return (ft_get_nbytes(av, nbytes, *p_shift));
	else if(ac > 2)
	{
		*p_shift = 1;
		return (ft_get_nbytes(av, nbytes, *p_shift));
	}
	else
	{
		ft_error(basename(av[0]));
		ft_error(": ");
		ft_error("option requires an argument -- ");
		write(STDERR, av[1] + 1, 1);
		ft_error("\n");
		ft_error("usage: ");
		ft_error(basename(av[0]));
		ft_error(" [ -c # ] [file ...]\n");
		return (0);
	}
}

int main(int ac, char **av)
{
	int	success;
	int	nbytes;
	int p_shift;

	if (ac == 1)
		return (ft_tail_read(0));
	if (av[1][1])
	{
		if (av[1][0] == '-' && av[1][1] == 'c')
		{
			//TODO: handle space between -c and the value of the nbytes
			success = ft_tail_parse_arg(ac, av, &nbytes, &p_shift);
			if (!success)
				return (1);
			if (ac == 2)
				return (ft_tail_read(nbytes));
			return (ft_tail_files(ac, av, nbytes, p_shift));
		}
	}
	if ((av[1][0] == '-' && av[1][1] == '\0') || av[1][0] != '-')
		return (ft_tail_files(ac, av, -1, 0));
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
