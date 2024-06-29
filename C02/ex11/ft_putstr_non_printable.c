/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:03:45 by inajah            #+#    #+#             */
/*   Updated: 2024/06/29 17:37:45 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_int_as_hex(int n)
{
	if (n < 16)
	{
		write(1, &"0123456789abcdef"[n], 1);
		return ;
	}
	ft_print_int_as_hex(n / 16);
	ft_print_int_as_hex(n % 16);
}

void	ft_print_char_as_hex(char c)
{
	if (c < 16)
		write (1, "0", 1);
	ft_print_int_as_hex((int) c);
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
			write(1, "\\", 1);
			ft_print_char_as_hex(str[i]);
		}
		i++;
	}
	write(1, "\n", 1);
}
