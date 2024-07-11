/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:14:53 by inajah            #+#    #+#             */
/*   Updated: 2024/07/11 10:54:18 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_tail_error(char *prog_name, char *av, int error)
{
	if (error == I_OFFSET)
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

int	ft_get_nbytes(char **av, int *nbytes, int p_shift)
{
	int		i;
	int		av_i;
	char	*arg_value;

	*nbytes = 0;
	i = 2;
	av_i = 1;
	if (p_shift == 1)
	{
		i = 0;
		av_i = 2;
	}
	while (av[av_i][i])
	{
		if (av[av_i][i] < '0' || '9' < av[av_i][i])
		{
			*nbytes = -1;
			arg_value = av[av_i] + 2 * (1 - p_shift);
			return (ft_tail_error(av[0], arg_value, I_OFFSET));
		}
		*nbytes = *nbytes * 10 + (av[av_i][i] - '0');
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
			text[i++] = c;
		else
			break ;
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

void	ft_print_buffer(char *buffer, t_file meta, int nbytes, int nbfiles)
{
	int			offset;
	static int	counter;

	if (counter > 0)
		ft_putstr("\n");
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
	counter++;
}

int	ft_tail_files(int ac, char **av, int nbytes, int p_shift)
{
	char	buffer[30000];
	t_file	meta;
	int		total_err;
	int		err;
	int		i;

	i = 1 + p_shift;
	total_err = 0;
	if (nbytes >= 0)
		i += 1;
	while (i < ac)
	{
		err = ft_read_file(av[i], buffer, &meta.len);
		if (err)
		{
			ft_tail_error(av[0], av[i++], err);
			total_err++;
		}
		else
		{
			meta.path = av[i++];
			ft_print_buffer(buffer, meta, nbytes, ac - (2 + 1 * p_shift));
		}
	}
	return (total_err);
}
