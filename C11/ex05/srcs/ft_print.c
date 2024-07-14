/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:19:36 by inajah            #+#    #+#             */
/*   Updated: 2024/07/14 15:05:07 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_do_op.h"

void	ft_putnbr(int nb)
{
	long long	n;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n < 10)
		write(1, &"0123456789"[n], 1);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

void	ft_error(char *str)
{
	ft_putstr("Stop : ");
	ft_putstr(str);
}
