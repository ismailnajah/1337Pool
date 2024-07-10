/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:57:19 by inajah            #+#    #+#             */
/*   Updated: 2024/07/10 10:36:00 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	ft_cat_error(char *prog_name, char *path, int err)
{
	ft_error(basename(prog_name));
	ft_error(": ");
	ft_error(path);
	ft_error(": ");
	ft_error(strerror(err));
	ft_error("\n");
	return (1);
}

int	ft_cat_read_input(void)
{
	char	buffer;

	while (read(STDIN, &buffer, 1))
		ft_putchar(buffer);
	return (0);
}

void	ft_display_file(int fd)
{
	char	buffer;

	while (read(fd, &buffer, 1))
		ft_putchar(buffer);
}

int	ft_cat_display_file(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd < 0)
	{
		fd = open(path, O_RDONLY);
		if (fd < 0)
			return (errno);
		ft_display_file(fd);
		close(fd);
	}
	else
	{
		close(fd);
		return (EISDIR);
	}
	return (0);
}

int	ft_cat_display_files(int ac, char **av)
{
	int	i;
	int	err;
	int	total_err;

	i = 1;
	total_err = 0;
	while (i < ac)
	{
		err = ft_cat_display_file(av[i]);
		if (err)
		{
			ft_cat_error(av[0], av[i], err);
			total_err += 1;
		}
		i++;
	}
	return (total_err);
}
