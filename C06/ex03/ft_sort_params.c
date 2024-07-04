/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:37:03 by inajah            #+#    #+#             */
/*   Updated: 2024/07/04 09:24:08 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_sort_strings(char **str_tab, int size)
{
	int		i;
	int		swaps;
	char	*tmp;

	swaps = 1;
	i = 0;
	while (swaps)
	{
		i = 0;
		swaps = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(str_tab[i], str_tab[i + 1]) > 0)
			{
				tmp = str_tab[i];
				str_tab[i] = str_tab[i + 1];
				str_tab[i + 1] = tmp;
				swaps++;
			}
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		return (0);
	i = 1;
	ft_sort_strings(argv + 1, argc - 1);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
