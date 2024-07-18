/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:19:37 by inajah            #+#    #+#             */
/*   Updated: 2024/07/18 11:11:04 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void	update_cell(int **dp, t_point cell, int *max, t_point *max_pos)
{
	dp[cell.y][cell.x] = min(dp[cell.y - 1][cell.x - 1],
			min(dp[cell.y][cell.x - 1], dp[cell.y - 1][cell.x])) + 1;
	if (dp[cell.y][cell.x] > *max)
	{
		*max = dp[cell.y][cell.x];
		max_pos->x = cell.x - 1;
		max_pos->y = cell.y - 1;
	}
}

int	fill_dp_matrix(int **dp, t_map *map, t_point *max_pos)
{
	t_point	cell;
	int		max;

	max = 0;
	cell.y = 1;
	while (cell.y < map->metadata.size + 1)
	{
		cell.x = 1;
		while (cell.x < map->metadata.size + 1)
		{
			if ((map->data[cell.y - 1][cell.x - 1]) == map->metadata.obstacle)
				dp[cell.y][cell.x] = 0;
			else
				update_cell(dp, cell, &max, max_pos);
			cell.x++;
		}
		cell.y++;
	}
	return (max);
}

int	find_biggest_square(t_map *map, t_point *max_pos)
{
	int	**dp;
	int	max;

	dp = allocate_dp_matrix(map->metadata.size + 1);
	max = fill_dp_matrix(dp, map, max_pos);
	free_dp_matrix(dp, map->metadata.size + 1);
	return (max);
}
