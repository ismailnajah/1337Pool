/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:33:20 by inajah            #+#    #+#             */
/*   Updated: 2024/07/06 15:06:05 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

#define ASCII_SIZE 256

int	ft_words_count(char *str, int *hash_t)
{
	int	word_counter;
	int	i;

	word_counter = 0;
	i = 0;
	while (str[i])
	{
		if (hash_t[(unsigned int)str[i]] == 1)
			i++;
		else
		{
			word_counter++;
			while (str[i] && hash_t[(unsigned int)str[i]] == 0)
				i++;
		}
	}
	return (word_counter);
}

char	**ft_init_split(char *str, char *sep, int *hash_t, int *w_count)
{
	int		i;
	char	**words_list;

	i = 0;
	while (i < ASCII_SIZE)
	{
		hash_t[i] = 0;
		i++;
	}
	i = 0;
	while (sep[i])
	{
		hash_t[(unsigned int) sep[i]] = 1;
		i++;
	}
	*w_count = ft_words_count(str, hash_t);
	words_list = malloc(((*w_count) + 1) * sizeof(char *));
	if (!words_list)
		return (NULL);
	if ((*w_count) == 0)
	{
		words_list[0] = 0;
		return (words_list);
	}
	return (words_list);
}

char	*ft_strndup(char *src, unsigned int size)
{
	unsigned int	i;
	char			*copy;

	copy = malloc((size + 1) * sizeof(char));
	if (!copy)
		return (0);
	i = 0;
	while (src[i] && i < size)
	{
		copy[i] = src[i];
		i++;
	}
	copy[size] = '\0';
	return (copy);
}

void	_ft_split(char **words_list, int size, char *str, int *hash_t)
{
	char	*start;
	int		i;
	int		word_size;
	int		index;

	index = 0;
	i = 0;
	while (index < size)
	{
		while (str[i] && hash_t[(unsigned int)str[i]] == 1)
			i++;
		start = str + i;
		while (str[i] && hash_t[(unsigned int)str[i]] == 0)
			i++;
		word_size = (str + i) - start;
		if (word_size != 0)
		{
			words_list[index] = ft_strndup(start, word_size);
			index++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**words_list;
	int		words_count;
	int		charset_hash[ASCII_SIZE];

	words_list = ft_init_split(str, charset, charset_hash, &words_count);
	_ft_split(words_list, words_count, str, charset_hash);
	words_list[words_count] = 0;
	return (words_list);
}
