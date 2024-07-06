/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:17:53 by inajah            #+#    #+#             */
/*   Updated: 2024/07/06 14:18:04 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
