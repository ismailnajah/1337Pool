/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:32:56 by inajah            #+#    #+#             */
/*   Updated: 2024/06/27 20:13:13 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	put_number(int number)
{
	if (number < 10)
	{
		write(1, &"0123456789"[number], 1);
	}
	else
	{
		put_number(number / 10);
		write(1, &"0123456789"[number % 10], 1);
	}
}

void	print_number(int number)
{
	if (number < 10)
	{
		write(1, "0", 1);
		write(1, &"0123456789"[number], 1);
	}
	else
	{
		put_number(number);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			print_number(a);
			write(1, " ", 1);
			print_number(b);
			if (a != 98)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
