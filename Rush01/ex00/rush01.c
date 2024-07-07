/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:50:28 by inajah            #+#    #+#             */
/*   Updated: 2024/07/07 17:43:03 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define FW 1
#define BW -1

extern int	g_grid[11][11];
extern int	g_size;

int	ft_print_solution(void);
int	ft_isvalid_col(int row, int col, int dir, int rule_index);
int	ft_isvalid_row(int row, int col, int dir, int rule_index);

int	ft_validate_solution(void)
{
	int	row_fw;
	int	row_bw;
	int	col_fw;
	int	col_bw;

	row_fw = ft_isvalid_row(1, 1, FW, 0);
	row_bw = ft_isvalid_row(1, g_size - 2, BW, g_size - 1);
	col_fw = ft_isvalid_col(1, 1, FW, 0);
	col_bw = ft_isvalid_col(g_size - 2, 1, BW, g_size - 1);
	return (row_fw && row_bw && col_fw && col_bw);
}

int	ft_suduko(int cell_r, int cell_c)
{
	int	value;
	int	c;
	int	r;

	value = g_grid[cell_r][cell_c];
	r = cell_r - 1;
	while (r > 0)
	{
		if (value == g_grid[r][cell_c])
			return (0);
		r--;
	}
	c = cell_c - 1;
	while (c > 0)
	{
		if (value == g_grid[cell_r][c])
			return (0);
		c--;
	}
	return (1);
}

int	ft_step_forward(int r, int c, int *next_r, int *next_c)
{
	g_grid[r][c] += 1;
	while (!ft_suduko(r, c) && g_grid[r][c] < g_size - 1)
		g_grid[r][c]++;
	if (g_grid[r][c] == g_size - 1)
	{
		g_grid[r][c] = 0;
		return (0);
	}
	*next_c = c + 1;
	*next_r = r;
	if (*next_c == g_size - 1)
	{
		*next_c = 1;
		*next_r = r + 1;
	}
	return (1);
}

int	ft_solution(int r, int c)
{
	int	next_cell_r;
	int	next_cell_c;

	if (r == g_size - 1)
	{
		if (ft_validate_solution())
			return (ft_print_solution());
		else
			return (0);
	}
	if (ft_step_forward(r, c, &next_cell_r, &next_cell_c))
	{
		if (!ft_solution(next_cell_r, next_cell_c))
			return (ft_solution(r, c));
		return (1);
	}
	else
		return (0);
	if (!ft_solution(next_cell_r, next_cell_c))
		return (ft_solution(r, c));
	return (1);
}
