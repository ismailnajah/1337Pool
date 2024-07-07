/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:13:15 by inajah            #+#    #+#             */
/*   Updated: 2024/07/07 17:43:45 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	g_grid[11][11];
extern int	g_size;

int	ft_print_solution(void)
{
	int	r;
	int	c;

	r = 1;
	while (r < g_size - 1)
	{
		c = 1;
		while (c < g_size - 1)
		{
			write(1, &"0123456789"[g_grid[r][c]], 1);
			if (c != g_size - 2)
				write(1, " ", 1);
			c++;
		}
		r++;
		write(1, "\n", 1);
	}
	return (1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_isvalid_row(int row, int col, int dir, int rule_index)
{
	int	count_maxs;
	int	max;
	int	c;

	while (row < g_size - 1)
	{
		count_maxs = 0;
		max = 0;
		c = col;
		while (0 < c && c < g_size - 1)
		{
			if (max < g_grid[row][c])
			{
				max = g_grid[row][c];
				count_maxs++;
			}
			c += dir;
		}
		if (count_maxs != g_grid[row][rule_index])
			return (0);
		row++;
	}
	return (1);
}

int	ft_isvalid_col(int row, int col, int dir, int rule_index)
{
	int	count_maxs;
	int	max;
	int	r;

	while (col < g_size - 1)
	{
		count_maxs = 0;
		max = 0;
		r = row;
		while (0 < r && r < g_size - 1)
		{
			if (max < g_grid[r][col])
			{
				max = g_grid[r][col];
				count_maxs++;
			}
			r += dir;
		}
		if (count_maxs != g_grid[rule_index][col])
			return (0);
		col++;
	}
	return (1);
}
