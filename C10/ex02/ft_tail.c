/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:14:53 by inajah            #+#    #+#             */
/*   Updated: 2024/07/10 16:07:46 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_get_offset(int *offset, char *param)
{
	*offset = 0;
	ft_putstr(param);
	return (1);
}

void	ft_tail_read(void)
{
	char	c;
	char	text[30000];
	int		i;

	i = 0;
	while (read(STDIN, &c, 1))
	{
		if (c != EOF)
		{
			text[i] = c;
			i++;
		}
		else
		{
			text[i] = '\0';
			break;
		}
	}
	ft_putstr(text);
}
