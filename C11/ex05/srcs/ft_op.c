/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:19:23 by inajah            #+#    #+#             */
/*   Updated: 2024/07/14 15:05:17 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_do_op.h"

int	add(int a, int b)
{
	ft_putnbr(a + b);
	return (0);
}

int	sub(int a, int b)
{
	ft_putnbr(a - b);
	return (0);
}

int	mul(int a, int b)
{
	ft_putnbr(a * b);
	return (0);
}

int	div(int a, int b)
{
	if (b == 0)
	{
		ft_error("division by zero");
		return (1);
	}
	ft_putnbr(a / b);
	return (0);
}

int	mod(int a, int b)
{
	if (b == 0)
	{
		ft_error("modulo by zero");
		return (1);
	}
	ft_putnbr(a % b);
	return (0);
}
