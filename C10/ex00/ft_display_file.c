/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:00:46 by inajah            #+#    #+#             */
/*   Updated: 2024/07/10 08:30:57 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(2, msg + i, 1);
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnstr(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	char	buffer;
	int		fd;

	if (ac < 2)
		return (ft_error("File name missing.\n"));
	if (ac > 2)
		return (ft_error("Too many arguments.\n"));
	fd = open(av[1], O_DIRECTORY);
	if (fd < 0)
	{
		fd = open(av[1], O_RDONLY);
		if(fd < 0)
			return (ft_error("Cannot read file.\n"));
		while (read(fd, &buffer, 1))
			ft_putchar(buffer);
		close(fd);
	}
	return (1);
}
