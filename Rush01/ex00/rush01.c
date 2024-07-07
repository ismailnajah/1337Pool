/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:50:28 by inajah            #+#    #+#             */
/*   Updated: 2024/07/07 16:12:41 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define FW (1)
#define BW (-1)
extern int g_grid[11][11];
extern int g_size;

int	ft_print_solution()
{
	int r;
	int c;

	r = 1;
	while (r < g_size - 1)
	{
		c = 1;
		while (c < g_size - 1)
		{
			write(1, &"0123456789"[g_grid[r][c]], 1);
			if(c != g_size - 2)
				write(1," ",1);
			c++;
		}
		r++;
		write(1,"\n",1);
	}	
	return (1);
}

int	ft_isvalid_row(int col, int dir, int rule_index)
{
	int count_maxs;
	int max;
	int r;
	int c;

	r = 1;
	c = col;
	while (r < g_size - 1)
	{
		count_maxs = 0;
		max = 0;
		c = col;
		while(0 < c && c < g_size - 1)
		{
			if (max < g_grid[r][c])
			{
				max  = g_grid[r][c];
				count_maxs++;
			}
			c += dir;
		}
		if (count_maxs != g_grid[r][rule_index])
			return (0);
		r++;
	}
	return (1);
}

int	ft_isvalid_col(int row, int dir, int rule_index)
{
	int count_maxs;
	int max;
	int c;
	int r;

	c = 1;
	r = row;
	while (0 < c && c < g_size - 1)
	{
		count_maxs = 0;
		max = 0;
		r = row;
		while(0 < r && r < g_size - 1)
		{
			if (max < g_grid[r][c])
			{
				max  = g_grid[r][c];
				count_maxs++;
			}
			r += dir;
		}
		if (count_maxs != g_grid[rule_index][c])
			return (0);
		c++;
	}
	return (1);
}


int ft_validate_solution()
{
	int row_fw;
	int row_bw;
	int col_fw;
	int col_bw;

	row_fw = ft_isvalid_row(1, FW, 0);
	row_bw = ft_isvalid_row(g_size - 2, BW, g_size - 1);
	col_fw = ft_isvalid_col(1, FW, 0);
	col_bw = ft_isvalid_col(g_size - 2, BW, g_size - 1);
	return row_fw && row_bw && col_fw && col_bw;
}

int ft_suduko(int cell_r, int cell_c)
{
	int value;
	int c;
	int r;

	value = g_grid[cell_r][cell_c];
	r = cell_r - 1;
	while (r > 0)
	{

		if (value == g_grid[r][cell_c])
			return (0);
		r--;
	}
	c = cell_c - 1;
	while(c > 0)
	{
		if (value == g_grid[cell_r][c])
			return (0);
		c--;
	}	
	return (1);
}

int	ft_solution(int r, int c)
{
	int next_cell_r;
	int next_cell_c;

	if (r == g_size - 1)
	{
		if (ft_validate_solution())
			return (ft_print_solution());
		else
			return (0);
	}
	g_grid[r][c] += 1;
	while(!ft_suduko(r, c) && g_grid[r][c] < g_size - 1)
		g_grid[r][c]++;
	if(g_grid[r][c] == g_size - 1)
	{
		g_grid[r][c] = 0;
		return 0;
	}
	next_cell_c = c + 1;
	next_cell_r = r;
	if(next_cell_c == g_size - 1){
		next_cell_c = 1;
		next_cell_r = r + 1;
	}
	if(!ft_solution(next_cell_r, next_cell_c))
		return ft_solution(r,c);	
	return (1);
}
