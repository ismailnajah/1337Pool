/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:00:50 by inajah            #+#    #+#             */
/*   Updated: 2024/06/26 21:29:55 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_sized_str(char *str, int size)
{
	int	i;

	i=0;
	while (i < size)
	{
		write(1, str+i, 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	buff[10];
	// init buffer
	int i;
	int k;

	i=0;
	while (i<n)
	{
		buff[i] = '0' + i;
		i++;
	}
	i=n-1;
	while (buff[0] <= ('0' + 10 - n))
	{
		while (buff[i] <= '9' - (n-1-i))
		{
			k = i+1;
			while (k < n)
			{
				buff[k] = buff[k-1] + 1;
				k++;
			}
			i = n-1;
			print_sized_str(buff, n);
			write(1 , ", ", 2);
			if (buff[i] == '9' - (n-1-i)){
				break;
			}	
			buff[i]++;
		}
		i--;
		while (buff[i] > '9' - (n-1-i) && i>0){
			i--;
		}
		if (i>=0)
			buff[i]++;
	}
}
