/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:15:57 by inajah            #+#    #+#             */
/*   Updated: 2024/07/13 20:23:30 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_print_int_as_hex(int n, int mode)
{
	char	out[9];
	int		i;
	char	*hex_sym;

	hex_sym = "0123456789abcdef";
	i = 0;
	while (i < 7 + mode)
		out[i++] = '0';
	out[i] = '\0';
	i--;
	while (n > 0)
	{
		out[i] = hex_sym[(unsigned int) n % 16];
		i--;
		n /= 16;
	}
	ft_putstr(out);
}

void	ft_print_spaces(int i, int padding)
{
	while (i < LINE_SIZE)
	{
		if (padding && i == (LINE_SIZE - 1) / 2)
			ft_putchar(' ');
		ft_putstr("  ");
		if (i != LINE_SIZE - 1)
			ft_putchar(' ');
		i++;
	}
}

void	ft_print_str_as_hex(char *str, int size, int padding)
{
	int		i;
	char	*hex_sym;

	i = 0;
	hex_sym = "0123456789abcdef";
	if (padding)
		ft_putchar(' ');
	while (i < LINE_SIZE && i < size)
	{
		ft_putchar(hex_sym[((unsigned char) str[i]) / 16]);
		ft_putchar(hex_sym[((unsigned char) str[i]) % 16]);
		if (padding && i == (LINE_SIZE - 1) / 2)
			ft_putchar(' ');
		if (i != LINE_SIZE - 1)
			ft_putchar(' ');
		i++;
	}
	ft_print_spaces(i, padding);
}

void	ft_print_non_printable(char *str, int size)
{
	int	i;

	ft_putchar('|');
	i = 0;
	while (i < size)
	{
		if (' ' <= str[i] && str[i] <= '~')
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('|');
}

void	ft_print_line(char *buffer, int row, int mode, int last)
{
	int		size;

	size = LINE_SIZE;
	if (last)
		size = last;
	ft_print_int_as_hex(row, mode);
	ft_putchar(' ');
	ft_print_str_as_hex(buffer, size, mode);
	if (mode)
	{
		ft_putstr("  ");
		ft_print_non_printable(buffer, size);
	}
	ft_putchar('\n');
}
