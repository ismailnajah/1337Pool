/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:15:06 by inajah            #+#    #+#             */
/*   Updated: 2024/06/30 23:07:43 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr (char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	to_find_size;

	to_find_size = 0;
	while (to_find[to_find_size])
		to_find_size++;
	if (to_find_size == 0)
		return str;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j])
		{
			j++;
		}
		if(!to_find[j])
			return (str + i);
		i++;
	}
	return 0;
}
