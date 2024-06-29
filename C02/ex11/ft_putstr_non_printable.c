/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:03:45 by inajah            #+#    #+#             */
/*   Updated: 2024/06/29 20:21:37 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar_as_hex(unsigned char c)
{
	int	n;

	n = c;
	write(1, "\\", 1);
	if (c < 16)
	{
		write(1, "0", 1);
		write(1, &"0123456789abcdef"[n], 1);
	}
	else
	{
		write(1, &"0123456789abcdef"[n / 16], 1);
		write(1, &"0123456789abcdef"[n % 16], 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (' ' <= str[i] && str[i] <= '~')
		{
			write(1, str + i, 1);
		}
		else
		{
			ft_putchar_as_hex(str[i]);
		}
		i++;
	}
}
