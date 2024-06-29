/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:48:47 by inajah            #+#    #+#             */
/*   Updated: 2024/06/29 12:16:06 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	encode_addr_as_hex_buff(long long addr, char *buffer, unsigned int *index)
{
	if (addr < 16)
	{
		buffer[*index] = "0123456789abcdef"[addr];
		(*index)--;
		return ;
	}
	encode_addr_as_hex_buff(addr / 16, buffer, index);
	encode_addr_as_hex_buff(addr % 16, buffer, index);
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
	encode_addr_as_hex_buff(addr_cast, buffer, &i);
	i = 0;
	while (i < 16)
	{
		write(1, buffer + i, 1);
		i++;
	}
	write(1, ": ", 2);
	write(1,"\n", 1);
}


void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size){
		print_formated_addr(addr+i);
		i+=16;
	}
	return (addr);
}
