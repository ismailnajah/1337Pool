/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:14:53 by inajah            #+#    #+#             */
/*   Updated: 2024/07/10 18:53:57 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_tail_error(char *prog_name, char *av, int error)
{
	if (error == ILLEGAL_OFFSET)
	{
		ft_error(basename(prog_name));
		ft_error(": ");
		ft_error("illegal offset -- ");
		ft_error(av);
		ft_error("\n");
	}
	else if (error == ENOENT)
	{
		ft_error(basename(prog_name));
		ft_error(": ");
		ft_error(av);
		ft_error(": ");
		ft_error(strerror(error));
	}
	return (0);
}

int	ft_get_offset(int *offset, char **av)
{
	int	i;

	*offset = 0;
	i = 2; // we handled the -c before calling this function
	while (av[1][i])
	{
		if (av[1][i] < '0' || '9' < av[1][i])
		{
			*offset = -1;
			return (ft_tail_error(av[0], av[1] + 2, ILLEGAL_OFFSET)); 
		}
		*offset = *offset * 10 + (av[1][i] - '0');
		i++;
	}
	return (1);
}

int	ft_tail_read(int nbytes)
{
	char	text[30000];
	char	c;
	int		i;
	int		offset;

	i = 0;
	while (read(STDIN, &c, 1))
	{
		if (c != EOF)
		{
			text[i] = c;
			i++;
		}
		else
			break;
	}
	text[i] = '\0';
	offset = 0;
	if (nbytes)
		offset = ft_strlen(text) - nbytes;
	if (offset < 0)
		offset = 0;
	ft_putstr(text + offset);
	return (0);
}

int	ft_filelen(char *path)
{
	int		len;
	int		fd;
	char	c;

	len = 0;
	fd = open(path, O_RDONLY);
	while (read(fd, &c, 1))
		len++;
	close(fd);
	return (len);
}

int	ft_tail_file(char *path, int nbytes)
{
	int 	fd;
	char	*buffer;
	int		file_len;
	int		offset;
	
	file_len = 0;
	fd = open(path, O_DIRECTORY);
	if (fd < 0)
	{
		fd = open(path, O_RDONLY);
		if (fd < 0)
			return (ENOENT);
		ft_putstr("==> ");
		ft_putstr(path);
		ft_putstr(" <==\n");
		file_len = ft_filelen(path);
		buffer = malloc((file_len + 1) * sizeof(char));
		read(fd, buffer, sizeof(buffer) - 1);
		offset = file_len - nbytes;
		if (offset < 0)
			offset = 0;
		ft_putstr(buffer + offset);
		free(buffer);
	}
	return 0;
}

int	ft_tail_files(int ac, char **av, int offset)
{
	int i;
	int err;
	int total_err;

	i = 1;
	total_err = 0;
	if (offset >= 0)
		i = 2;
	while (i < ac)
	{
		err = ft_tail_file(av[i], offset);
		if (err)
		{
			ft_tail_error(av[0], av[i], err);
			total_err++;
		}
		ft_putstr("\n");
		i++;
	}
	return (total_err);
}
