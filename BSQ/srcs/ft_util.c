/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:41:36 by inajah            #+#    #+#             */
/*   Updated: 2024/07/18 11:11:21 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	result *= sign;
	return (result);
}

int	print_error(int return_code)
{
	write(2, "map error\n", 10);
	return (return_code);
}

int	ft_is_printable(char c)
{
	return (' ' <= c && c <= '~');
}

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (-1);
	}
	fd = open(path, O_RDONLY);
	return (fd);
}
