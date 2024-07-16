/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:18:31 by inajah            #+#    #+#             */
/*   Updated: 2024/07/16 17:15:30 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_putchar(char c)
{
	write(STDOUT, &c, 1);
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

void	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(STDERR, str + i, 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int	ft_read_file(char *path, char *buffer, int *file_len)
{
	int		fd;
	char	c;

	*file_len = 0;
	fd = open(path, O_DIRECTORY);
	if (fd < 0)
	{
		fd = open(path, O_RDONLY);
		if (fd < 0)
			return (errno);
		while (read(fd, &c, 1))
		{
			buffer[*file_len] = c;
			(*file_len)++;
		}
	}
//	buffer[*file_len] = '\0';
	return (0);
}
