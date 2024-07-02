/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:26:16 by inajah            #+#    #+#             */
/*   Updated: 2024/07/02 13:34:36 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

long long	ft_power(int x, int n)
{
	if (n == 0)
		return (1);
	return (x * ft_power(x, n - 1));
}

long long	_ft_atoi_base(char *str, char *base_symboles, unsigned int size)
{
	long long		number;
	unsigned int	base;
	unsigned int	digit;
	int				i;

	base = 0;
	while (base_symboles[base])
		base++;
	i = size - 1;
	number = 0;
	while (i >= 0)
	{
		digit = ft_inbase(str[i], base_symboles);
		number += digit * ft_power(base, size - i - 1);
		i--;
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	base_size;
	unsigned int	i;
	int				start;
	int				sign;

	sign = 1;
	base_size = ft_isvalid_base(base);
	if (base_size <= 1)
		return (0);
	i = 0;
	while (str[i] && (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	start = i;
	while (str[i] && ft_inbase(str[i], base) >= 0)
		i++;
	return (_ft_atoi_base(str + start, base, i - start) * sign);
}
