/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:07:52 by inajah            #+#    #+#             */
/*   Updated: 2024/07/04 19:06:28 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

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

void	ft_putnbr_base_buff(long long nbr, char *base_symboles, int base_size, char *buffer)
{
	//make this function iterative;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr < base_size){
		if(buffer != NULL)
			buffer[]  = base_symboles + nbr;
	}
	else
	{
		ft_putnbr_base(nbr / base_size, base_symboles, base_size);
		ft_putnbr_base(nbr % base_size, base_symboles, base_size);
	}
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
	while (str[i] && ft_inbase(str[i], base) >= 0)
	{
		digit = ft_inbase(str[i], base);
		if (digit < 0)
			break;
		number = number * base_size + digit;
		i++;
	}
	return (number * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to) 
{
	int	base_from_size;
	int	base_to_size;
	int	number;

	base_from_size = ft_isvalid_base(base_from);
	base_to_size = ft_isvalid_base(base_to);
	if (base_from_size == 0 || base_to_size == 0)
		return (0);
	number = ft_atoi_base(nbr, base_from, base_from_size);
	ft_putnbr_base(number, base_to, base_to_size);
	return (0);
}












