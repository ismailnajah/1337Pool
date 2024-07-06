/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:07:05 by inajah            #+#    #+#             */
/*   Updated: 2024/07/06 15:00:51 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <errno.h>

char	*ft_allocate_copy(char *src)
{
	char	*copy;
	int		size;

	size = 0;
	while (src[size])
		size++;
	copy = malloc((size + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	if (size == 0)
		copy[0] = '\0';
	return (copy);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	copy = ft_allocate_copy(src);
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
