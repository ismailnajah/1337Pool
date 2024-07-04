/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:07:05 by inajah            #+#    #+#             */
/*   Updated: 2024/07/04 13:26:14 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <errno.h>

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	unsigned int	size;
	unsigned int	i;
	char			*copy;

	if (!src)
		return (0);
	size = ft_strlen(src);
	copy = malloc(size * sizeof(char));
	if (!copy)
	{
		errno = ENOMEM;
		return (0);
	}
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
