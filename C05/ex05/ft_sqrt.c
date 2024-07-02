/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:43:55 by inajah            #+#    #+#             */
/*   Updated: 2024/07/02 21:48:03 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt_nb;

	sqrt_nb = 0;
	while (sqrt_nb * sqrt_nb < nb)
		sqrt_nb++;
	if (sqrt_nb * sqrt_nb != nb)
		return (0);
	return (sqrt_nb);
}
