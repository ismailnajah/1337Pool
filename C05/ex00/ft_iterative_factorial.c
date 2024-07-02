/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:55:04 by inajah            #+#    #+#             */
/*   Updated: 2024/07/02 20:34:27 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	out;

	if (nb < 0)
		return (0);
	i = 1;
	out = 1;
	while (i <= nb)
	{
		out = out * i;
		i++;
	}
	return (out);
}
