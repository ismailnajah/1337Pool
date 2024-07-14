/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:29:50 by inajah            #+#    #+#             */
/*   Updated: 2024/07/14 11:59:44 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_hexdump_in(t_stream *s, int mode)
{
	ft_hexdump_read(STDIN, s, mode);
	if (s->cursor % LINE_SIZE != 0)
		ft_print_line(s->buffer, s->row, mode, s->cursor % LINE_SIZE);
	ft_print_int_as_hex(s->row + s->cursor % LINE_SIZE, mode);
	ft_putchar('\n');
}

void	ft_hexdump_usage(char *prog_name)
{
	ft_error("usage: ");
	ft_error(prog_name);
	ft_error(" [-C] [file ...]\n");
}

int	ft_hexdump_illegal(char *prog_name, char *av)
{
	char	option;

	option = av[1];
	if (option == 'C')
		option = av[2];
	ft_error(prog_name);
	ft_error(": ");
	ft_error("illegal option -- ");
	write(STDERR, &option, 1);
	ft_error("\n");
	ft_hexdump_usage(prog_name);
	return (FAILURE);
}

int	main(int ac, char **av)
{
	int			err;
	t_stream	stream;

	stream.index = 1;
	stream.row = 0;
	stream.cursor = 0;
	err = 0;
	if (ac == 1)
		ft_hexdump_in(&stream, 0);
	else
	{
		if (av[1][0] == '-' && av[1][1] == 'C' && !av[1][2])
		{
			if (ac > 2)
			{
				stream.index = 2;
				err = ft_hexdump_files(ac, av, &stream, 1);
			}
			else
				ft_hexdump_in(&stream, 1);
		}
		else if (av[1][0] == '-')
			return (ft_hexdump_illegal(basename(av[0]), av[1]));
		else
			err = ft_hexdump_files(ac, av, &stream, 0);
	}
	return (err != 0);
}
