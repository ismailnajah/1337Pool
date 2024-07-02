/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:35:11 by inajah            #+#    #+#             */
/*   Updated: 2024/07/02 13:31:59 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

void	_ft_putnbr_base(long long nbr, char *base_symboles, int base_size)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr < base_size)
		write(1, base_symboles + nbr, 1);
	else
	{
		_ft_putnbr_base(nbr / base_size, base_symboles, base_size);
		_ft_putnbr_base(nbr % base_size, base_symboles, base_size);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_size;

	base_size = ft_isvalid_base(base);
	if (base_size <= 1)
		return ;
	_ft_putnbr_base(nbr, base, base_size);
}
