/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:07:10 by inajah            #+#    #+#             */
/*   Updated: 2024/07/04 16:17:10 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void	ft_copy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	if (src_len < size - dest_len)
		ft_copy(dest + dest_len, src, src_len);
	else
		ft_copy(dest + dest_len, src, size - dest_len - 1);
	return (dest_len + src_len);
}

char	*_ft_strjoin(char **strs, char *sep, int size, int dest_size)
{
	int		i;
	char	*dest;

	dest = malloc(dest_size * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (i < dest_size)
		dest[i++] = 0;
	i = 0;
	while (i < size)
	{
		ft_strlcat(dest, strs[i], dest_size);
		ft_strlcat(dest, sep, dest_size);
		i++;
	}
	dest[dest_size - 1] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		strsl;
	int		sepl;
	int		i;

	if (size == 0)
	{
		dest = malloc(sizeof(char));
		if (!dest)
			return (0);
		dest[0] = '\0';
		return (dest);
	}
	i = 0;
	strsl = 0;
	while (i < size)
	{
		strsl += ft_strlen(strs[i]);
		i++;
	}
	sepl = ft_strlen(sep);
	return (_ft_strjoin(strs, sep, size, strsl + 1 + sepl * (size - 1)));
}
