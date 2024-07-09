/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:07:22 by inajah            #+#    #+#             */
/*   Updated: 2024/07/09 10:06:19 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define MAX_ASCII 255

void	ft_init_split(int *hash_t, char *charset)
{
	int	i;

	i = 0;
	while (i < MAX_ASCII)
		hash_t[i++] = 0;
	i = 0;
	while (charset[i])
	{
		hash_t[(unsigned char) charset[i]] = 1;
		i++;
	}
}

char	*ft_strndup(char *str, int size)
{
	char	*copy;
	int		i;

	copy = malloc((size + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = str[i];
		i++;
	}
	copy[size] = '\0';
	return (copy);
}

char	**ft_count_words(char *str, int *hash_t, int *words_count)
{
	int		i;
	char	**words_list;

	i = 0;
	while (str[i])
	{
		if (hash_t[(unsigned char) str[i]] == 1)
			i++;
		else
		{
			*words_count = *words_count + 1;
			while (str[i] && hash_t[(unsigned char) str[i]] == 0)
				i++;
		}
	}
	words_list = malloc((*words_count + 1) * sizeof(char *));
	if (!words_list)
		return (NULL);
	return (words_list);
}

void	_ft_split(char *str, int *hash_t, char **words_list, int words_count)
{
	int	start;
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (index < words_count)
	{
		if (hash_t[(unsigned char) str[i]] == 1)
			i++;
		else
		{
			start = i;
			while (str[i] && hash_t[(unsigned char) str[i]] == 0)
				i++;
			if (i > start)
			{
				words_list[index] = ft_strndup(str + start, i - start);
				index++;
			}
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int		hash_t[MAX_ASCII];
	int		words_count;
	char	**words_list;

	ft_init_split(hash_t, charset);
	words_count = 0;
	words_list = ft_count_words(str, hash_t, &words_count);
	if (!words_list)
		return (NULL);
	_ft_split(str, hash_t, words_list, words_count);
	words_list[words_count] = 0;
	return (words_list);
}
