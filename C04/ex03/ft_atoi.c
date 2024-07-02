/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:14:47 by inajah            #+#    #+#             */
/*   Updated: 2024/07/02 13:17:59 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_power(int x, int n)
{
	if (n == 0)
		return (1);
	return (x * ft_power(x, n - 1));
}

long long	ft_digits_to_int(char *digit_str, unsigned int size)
{
	int			i;
	long long	number;

	number = 0;
	i = size - 1;
	while (i >= 0)
	{
		number += (digit_str[i] - '0') * ft_power(10, size - 1 - i);
		i--;
	}
	return (number);
}

int	ft_atoi(char *str)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;
	int				sign;

	sign = 1;
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
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		i++;
	}
	end = i;
	return (ft_digits_to_int(str + start, end - start) * sign);
}
