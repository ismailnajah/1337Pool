/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:35:21 by inajah            #+#    #+#             */
/*   Updated: 2024/07/02 21:05:04 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	out;
	int	i;

	if (power < 0 || nb == 0)
		return (0);
	if (power == 0 || nb == 1)
		return (1);
	i = 0;
	out = 1;
	while (i < power)
	{
		out *= nb;
		i++;
	}
	return (out);
}
