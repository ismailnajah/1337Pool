/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:56:26 by inajah            #+#    #+#             */
/*   Updated: 2024/07/02 23:00:48 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	candidate;

	candidate = nb;
	while (!_is_prime(candidate))
		candidate++;
	return (candidate);
}
