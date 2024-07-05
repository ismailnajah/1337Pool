/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:07:52 by inajah            #+#    #+#             */
/*   Updated: 2024/07/05 09:14:42 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_BUFF_SIZE 34

int	ft_isvalid_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

char	*ft_putnbr_base_buff(long long nbr, char *b_sym, int b_size, char *buff)
{
	int	cursor;
	int	i;

	cursor = 0;
	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i = 1;
		buff[cursor++] = '-';
	}
	while (nbr >= b_size)
	{
		buff[cursor++] = b_sym[nbr % b_size];
		nbr = nbr / b_size;
	}
	buff[cursor] = b_sym[nbr % b_size];
	while (i < cursor)
	{
		nbr = buff[i];
		buff[i++] = buff[cursor];
		buff[cursor--] = nbr;
	}
	return (buff);
}

int	ft_inbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base, int base_size)
{
	int	i;
	int	number;
	int	sign;
	int	digit;

	sign = 1;
	i = 0;
	while (str[i] && (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			sign *= -1;
	number = 0;
	while (str[i])
	{
		digit = ft_inbase(str[i], base);
		if (digit < 0)
			break ;
		number = number * base_size + digit;
		i++;
	}
	return (number * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		b_from_size;
	int		b_to_size;
	int		number;
	int		i;
	char	*buffer;

	b_from_size = ft_isvalid_base(base_from);
	b_to_size = ft_isvalid_base(base_to);
	if (b_to_size < 2 || b_from_size < 2)
		return (NULL);
	number = ft_atoi_base(nbr, base_from, b_from_size);
	buffer = malloc(MAX_BUFF_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < MAX_BUFF_SIZE)
		buffer[i++] = 0;
	return (ft_putnbr_base_buff(number, base_to, b_to_size, buffer));
}
