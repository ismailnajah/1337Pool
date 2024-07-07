/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:50:28 by inajah            #+#    #+#             */
/*   Updated: 2024/07/07 11:58:02 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_solution(int grid[10][10],int size)
{
	int r;
	int c;

	r = 0;
	while (r < size)
	{
		c = 0;
		while (c < size)
		{
			if (grid[r][c] == 0)
				write(1," ",1);
			else
				write(1, &"0123456789"[grid[r][c]], 1);
			write(1," ",1);
			c++;
		}
		r++;
		write(1,"\n",1);
	}
}

int	ft_isvalid_state(int **grid, int size)
{
	//check if the grid is following the rules
	(void)grid;
	return size;
}

int ft_isvalid_value(int **grid, int size, int row, int col)
{
	// check if the value of (row, col) is valid no repetition in row or col (suduku rules)
	(void)grid;
	row = col;
	return size;
}

/*void	ft_solution(int **grid, int size,int row, int col)
{
	row = col;
	size = row;
	(void) state;
	write(1, "solution\n", 9);
}*/
