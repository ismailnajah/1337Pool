/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:00:46 by inajah            #+#    #+#             */
/*   Updated: 2024/07/09 17:34:11 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_error(char *msg)
{
	int i;

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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	char	buffer[1024];
	if (ac < 2)
		return (ft_error("File name missing.\n"));
	if (ac > 2)
		return (ft_error("Too many arguments.\n"));
	
	int	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("Cannot read file."));
	read(fd, buffer, sizeof(buffer));
	ft_putstr(buffer);	
	close(fd);
	return (0);
}
