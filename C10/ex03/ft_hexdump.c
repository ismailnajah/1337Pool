/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:48:44 by inajah            #+#    #+#             */
/*   Updated: 2024/07/13 20:23:13 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_print_star(void)
{
	ft_putstr("*\n");
	return (1);
}

int	ft_hexdump_error(char *prog_name, char *path, int err)
{
	if (err == ENOENT)
	{
		ft_error(basename(prog_name));
		ft_error(": ");
		ft_error(path);
		ft_error(": ");
		ft_error(strerror(err));
		ft_error("\n");
		ft_error(basename(prog_name));
		ft_error(": ");
		ft_error(path);
		ft_error(": ");
		ft_error(strerror(EBADF));
		ft_error("\n");
	}
	else
	{
		ft_error(basename(prog_name));
		ft_error(": ");
		ft_error(path);
		ft_error(": ");
		ft_error(strerror(err));
		ft_error("\n");
	}
	return (FAILURE);
}

int	ft_hexdump_read(int fd, t_stream *s, int mode)
{
	static char	previous[17];
	static int	star_printed;
	char		c;

	while (read(fd, &c, 1))
	{
		s->buffer[s->cursor] = c;
		s->buffer[s->cursor + 1] = '\0';
		if (s->cursor > 0 && (s->cursor + 1) % LINE_SIZE == 0)
		{
			if (!ft_bytecmp(s->buffer, previous, LINE_SIZE))
			{
				ft_print_line(s->buffer, s->row, mode, LINE_SIZE);
				ft_bytecpy(previous, s->buffer, LINE_SIZE);
				star_printed = 0;
			}
			else if (!star_printed)
				star_printed = ft_print_star();
			s->row += LINE_SIZE;
		}
		s->cursor = (s->cursor + 1) % LINE_SIZE;
	}
	return (0);
}

int	ft_hexdump_file(char **av, t_stream *s, int mode)
{
	int		fd;
	char	*path;

	path = av[s->index];
	fd = open(path, O_DIRECTORY);
	if (fd < 0)
	{
		fd = open(path, O_RDONLY);
		if (fd < 1)
		{
			return (ft_hexdump_error(av[0], path, errno));
		}
		ft_hexdump_read(fd, s, mode);
		close(fd);
	}
	else
	{
		close(fd);
		return (ft_hexdump_error(av[0], path, EISDIR));
	}
	return (0);
}

int	ft_hexdump_files(int ac, char **av, t_stream *s, int mode)
{
	int	total_err;

	total_err = 0;
	while (s->index < ac)
	{
		total_err += ft_hexdump_file(av, s, mode);
		s->index++;
	}
	if (s->cursor % LINE_SIZE != 0)
		ft_print_line(s->buffer, s->row, mode, s->cursor % LINE_SIZE);
	if (s->row > 0)
	{
		ft_print_int_as_hex(s->row + (s->cursor % LINE_SIZE), mode);
		ft_putchar('\n');
	}
	return (total_err);
}
