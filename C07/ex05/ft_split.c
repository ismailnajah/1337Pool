/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:33:20 by inajah            #+#    #+#             */
/*   Updated: 2024/07/06 13:00:38 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

#define ASCII_SIZE 256

void	ft_init_charset_hash(int *charset_hash, char *charset)
{
	int	i;

	i = 0;
	while(i < ASCII_SIZE)
	{
		charset_hash[i] = 0;
		i++;
	}
	i = 0;
	while(charset[i])
	{
		charset_hash[(unsigned int) charset[i]] = 1;
		i++;
	}
}

int ft_words_count(char *str, char *charset)
{
	int	charset_hash[ASCII_SIZE];
	int	word_counter;
	int	i;

	ft_init_charset_hash(charset_hash, charset);
	word_counter = 0;
	i = 0;
	while (str[i])
	{
		if (charset_hash[(unsigned int)str[i]] == 1)
			i++;
		else
		{
			word_counter++;
			while(str[i] && charset_hash[(unsigned int)str[i]] == 0)
				i++;
		}
	}
	return (word_counter);
}

char	*ft_get_next_word(char *str, int *charset_hash, int *word_size, int *i)
{
	char	*start;
	
	while (str[*i] && charset_hash[(unsigned int)str[*i]] == 1)
		(*i)++;
	start = str + *i;
	while(str[*i] && charset_hash[(unsigned int)str[*i]] == 0)
	{
		*i = *i + 1;
	}
	*word_size = (str + *i) - start;
	return start;
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

char	**ft_split(char *str, char *charset)
{
	char	**words_list;
	int		words_count;
	int		word_size;
	int		cursor;
	int		i;
	int		charset_hash[ASCII_SIZE];

	ft_init_charset_hash(charset_hash ,charset);
	words_count = ft_words_count(str, charset);
	words_list = malloc((words_count + 1) * sizeof(char *));
	if (!words_list)
		return (NULL);
	if (words_count == 0)
	{
		words_list[0] = 0;
		return (words_list);
	}
	i = 0;
	cursor = 0;
	while (i < words_count)
	{
		ft_get_next_word(str, charset_hash, &word_size, &cursor);
		words_list[i++] = ft_strndup((str + cursor) - word_size, word_size);
	}
	words_list[i] = 0;
	return (words_list);
}
