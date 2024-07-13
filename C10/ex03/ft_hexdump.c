/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:48:44 by inajah            #+#    #+#             */
/*   Updated: 2024/07/13 11:12:44 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"


void	ft_print_int_as_hex(int index)
{
	char	out[8];
	int		i;
	char	*hex_sym;

	hex_sym = "0123456789abcdef";
	i = 0;
	while (i < 7)
		out[i++] = '0';
	out[i] = '\0';
	i--;
	while (index > 0)
	{
		out[i] = hex_sym[(unsigned int) index % 16];
		i--;
		index /= 16;
	}
	ft_putstr(out);
}

void	ft_print_str_as_hex(char *str, int padding)
{
	int		i;
	char	*hex_sym;

	i = 0;
	hex_sym = "0123456789abcdef";
	if (padding)
		ft_putchar(' ');
	while(i < LINE_SIZE && str[i])
	{
		ft_putchar(hex_sym[((unsigned char) str[i]) / 16]);
		ft_putchar(hex_sym[((unsigned char) str[i]) % 16]);
		if (padding && i == (LINE_SIZE - 1) / 2)
			ft_putchar(' ');
		if (i != LINE_SIZE - 1)
			ft_putchar(' ');
		i++;
	}
	while (i < LINE_SIZE)
	{
		if (padding && i == (LINE_SIZE - 1) / 2)
			ft_putchar(' ');
		ft_putstr("  ");
		if (i != LINE_SIZE - 1)
			ft_putchar(' ');
		i++;
	}
}

void	ft_print_non_printable(char *str)
{
	int	i;

	ft_putchar('|');
	i = 0;
	while(i < LINE_SIZE && str[i])
	{
		if (' ' <= str[i] && str[i] <= '~')
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('|');
}

void	ft_print_line(char *buffer, int row, int mode)
{
	char	*str;

	ft_print_int_as_hex(row);
	ft_putchar(' ');
	str = buffer + row;
	ft_print_str_as_hex(str, mode);
	if (mode)
	{
		ft_putstr("  ");
		ft_print_non_printable(str);
	}
	ft_putchar('\n');
}

void	debug(char *str)
{
	ft_putstr("debug: ");
	ft_putstr(str);
	ft_putstr("\n");
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
	{	ft_error(basename(prog_name));
		ft_error(": ");
		ft_error(path);
		ft_error(": ");
		ft_error(strerror(err));
		ft_error("\n");
	}
	return (FAILURE);
}

int	ft_hexdump_read(int fd, int mode)
{
	static int	row;
	static char	previous[17];
	static int	star_printed;
	static char	current[30000];
	char		c;
	int			index;

	index = 0;
	while (read(fd, &c, 1))
	{
		current[index] = c;
		current[index + 1] = '\0';
		if (index > 0 && (index + 1) % LINE_SIZE  == 0)
		{
			if (ft_strcmp(current + row, previous) != 0)
			{
				ft_print_line(current, row, mode);
				star_printed = 0;
				ft_strcpy(previous, current + row );
			}
			else if(!star_printed)
			{
				star_printed = 1;
				ft_putstr("*\n");
			}
			row += LINE_SIZE;
		}
		index++;
	}
	if (index % LINE_SIZE != 0)
		ft_print_line(current, row, mode);
	ft_print_int_as_hex(row + (index % LINE_SIZE));
	ft_putchar('\n');
	return (0);
}

int	ft_hexdump_file(char **av, int file_index, int mode)
{
	int		fd;
	char	*path = av[file_index];

	fd = open(path, O_DIRECTORY);
	if (fd < 0)
	{
		fd = open(path, O_RDONLY);
		if (fd < 1)
		{
			return (ft_hexdump_error(av[0], path, errno));
		}
		ft_hexdump_read(fd, mode);
		close(fd);
	}
	else
	{
		close(fd);
		return (ft_hexdump_error(av[0], path, EISDIR));
	}
	return (0);
}

int	ft_hexdump_files(int ac, char **av, int index, int mode)
{
	int total_err;

	total_err = 0;
	while (index < ac)
	{
		//row shoud be outside ft_hexdump_file 
		total_err += ft_hexdump_file(av, index, mode);
		index++;	
	}
	return (total_err);
}
