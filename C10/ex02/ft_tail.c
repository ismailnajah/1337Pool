/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:14:53 by inajah            #+#    #+#             */
/*   Updated: 2024/07/10 20:44:55 by inajah           ###   ########.fr       */
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
	else
	{
		ft_error(basename(prog_name));
		ft_error(": ");
		ft_error(av);
		ft_error(": ");
		ft_error(strerror(error));
		ft_error("\n");
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


int	ft_read_file(char *path, char *buffer, int *file_len)
{
	int 	fd;
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
		buffer[*file_len] = '\0';	
	}
	return 0;
}

void	ft_print_buffer(char *buffer, t_file meta, int nbytes, int nbfiles)
{
	int	offset;

	if (nbfiles > 1)
	{
		ft_putstr("==> ");
		ft_putstr(meta.path);
		ft_putstr(" <==\n");
	}
	offset = meta.len - nbytes;
	if (offset < 0)
		offset = 0;
	ft_putstr(buffer + offset);
}

int	ft_tail_files(int ac, char **av, int nbytes)
{
	char	buffer[30000];
	t_file	meta;
	int		total_err;
	int		err;
	int		i;

	i = 1;
	total_err = 0;
	if (nbytes >= 0)
		i = 2;
	while (i < ac)
	{
		err = ft_read_file(av[i], buffer, &meta.len);
		if (err)
		{
			ft_tail_error(av[0], av[i], err);
			total_err++;
		}
		else
		{
			meta.path = av[i];
			if (i != 2)
				ft_putstr("\n");
			ft_print_buffer(buffer, meta, nbytes, ac - 2);
		}
		i++;
	}
	return (total_err);
}
