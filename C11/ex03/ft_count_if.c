/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:18:45 by inajah            #+#    #+#             */
/*   Updated: 2024/07/14 09:28:20 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (i < length)
	{
		result += (*f)(tab[i]);
		i++;
	}
	return (result);
}
