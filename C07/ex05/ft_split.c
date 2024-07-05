/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:33:20 by inajah            #+#    #+#             */
/*   Updated: 2024/07/05 11:52:13 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_find_char(char c, char *haystack)
{
	int	i;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	**ft_split(char *str, char *charset)
{
	int	word_counter;
	int	i;
	int j;

	word_counter = 0;
	i = 0;
	while (str[i])
	{
		if (ft_find_char(str[i] , charset) >= 0)
			i++;
		else
		{
			j = 0;
			while(str[i + j] && ft_find_char(str[i + j] , charset) < 0)
				j++;
			if (j > 0)
				word_counter++;
			i += j;
		}
	}
	printf("you have %d words in \"%s\" with charset \"%s\"\n", word_counter, str, charset);
	return (NULL);
}
