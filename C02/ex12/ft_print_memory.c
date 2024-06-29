/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:48:47 by inajah            #+#    #+#             */
/*   Updated: 2024/06/29 14:06:37 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
void	encode_long_as_hex_buff(long long n, char *buffer, unsigned int *index)
{
	if (n < 16)
	{
		buffer[*index] = "0123456789abcdef"[n];
		*index = *index - 1;
		return ;
	}
	encode_long_as_hex_buff(n % 16, buffer, index);
	encode_long_as_hex_buff(n / 16, buffer, index);
}

void	print_formated_addr(void *addr)
{
	long long addr_cast;
	unsigned int	i;
	char	buffer[16];

	addr_cast = (long long) addr;
	i = 0;
	while (i < 16)
	{
		buffer[i] = '0';
		i++;
	}
	i--;
	encode_long_as_hex_buff(addr_cast, buffer, &i);
	i = 0;
	while (i < 16)
	{
		write(1, buffer + i, 1);
		i++;
	}
}

void	print_str_as_hex(char *str, unsigned int size)
{
	char	buffer[2];
	unsigned int	i;
	unsigned int index;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			buffer[0] = '0';
			buffer[1] = '0';
			index = 1;
			encode_long_as_hex_buff((long) str[i], buffer, &index);
			printf(" ---------- %.2s ---------- ", buffer);
			write(1, buffer, 2);
		}
		else
		{
			write(1, "  ", 2);
		}
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	print_str_non_printable(char *str, unsigned int size)
{	
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (' ' <= str[i] && str[i] <= '~')
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i;
	unsigned int print_size;

	i = 0;
	while (i < size){
		print_formated_addr(addr + i);
		write(1, ": ", 2);
		print_size = 16;
		if (size - i < 16)
			print_size = size - i + 1;//include the '\0' in printing
		print_str_as_hex((char*) addr + i, print_size);
		write(1, " ", 1);
		print_str_non_printable((char*) addr + i, print_size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
