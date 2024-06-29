/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:53:37 by inajah            #+#    #+#             */
/*   Updated: 2024/06/29 17:58:15 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	unsigned int	i;
	int				upper;
	int				lower;

	i = 0;
	while (str[i])
	{
		lower = ('a' <= str[i] && str[i] <= 'z');
		upper = ('A' <= str[i] && str[i] <= 'Z');
		if (!(lower || upper))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
