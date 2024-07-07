/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:47:06 by inajah            #+#    #+#             */
/*   Updated: 2024/07/07 14:14:28 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define SUCCESS 0
#define FAILURE 1
#define MAX_SIZE 11


void	ft_solution(int row, int col);
void	ft_print_solution(int grid[MAX_SIZE][MAX_SIZE],int size);

int g_size;
int g_grid[MAX_SIZE][MAX_SIZE];


void	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}


int	ft_leftright(int grid[MAX_SIZE][MAX_SIZE], char *rules,  int row, int col)
{
	int i;
	i = 0;
	while (row < g_size - 1)
	{
		if ('0' <= rules[i] && rules[i] <= '9')
		{
			grid[row][col] = rules[i] - '0';
			row++;
			if (!rules[i + 1] && rules[i + 1] != ' ' && row != g_size - 1)
				return 0;
			i += 2;
		}
		else
			return (0);
	}
	return (1);
}

int	ft_updown(int grid[MAX_SIZE][MAX_SIZE], char *rules, int row, int col)
{
	int i;
	i = 0;
	while (col < g_size - 1)
	{
		if ('0' <= rules[i] && rules[i] <= '9')
		{
			grid[row][col] = rules[i] - '0';
			col++;
			if (!rules[i + 1] && rules[i + 1] != ' ')
				return 0;
			i += 2;
		}
		else
			return (0);
	}
	return (1);
}

int	ft_valid_rules(int grid[MAX_SIZE][MAX_SIZE], char *rules)
{
	int i;
	
	i = 0;
	int up = ft_updown(grid, rules + i, 0, 1);
	i = (g_size - 2) * 2;
	int down = ft_updown(grid, rules + i, g_size - 1, 1);
	i = (g_size - 2) * 4;
	int left = ft_leftright(grid, rules + i, 1, 0);
	i = (g_size - 2) * 6;
	int right = ft_leftright(grid, rules + i, 1, g_size - 1);
	i = (g_size - 2) * 8 - 1;
	if (rules[i])
		return (0);
	return (up && down && left && right);
}

// "  12234423 2 1 1 2 1 21     2"
/*void	ft_init_grid(int **grid, int size, int *rules)
{
}*/

int	main(int ac, char **av)
{
	int size = 4;
	g_size = size + 2;

	if (ac != 2)
	{
		ft_putstr("too many or few arguments\n");
		return (FAILURE);
	}
	if(!ft_valid_rules(g_grid, av[1]))
	{
		ft_putstr("invalid set of rules!!\n");
		return (FAILURE);
	}
//	ft_print_solution(g_grid, g_size);
	ft_solution(1, 1);
	return (SUCCESS);
}
