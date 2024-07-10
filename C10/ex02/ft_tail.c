/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:14:53 by inajah            #+#    #+#             */
/*   Updated: 2024/07/10 17:47:13 by inajah           ###   ########.fr       */
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

int	ft_tail_files(int ac, char **av, int offset)
{
	int i;

	i = 1;
	if (offset >= 0)
		i = 2;
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
