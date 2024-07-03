/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:10:00 by inajah            #+#    #+#             */
/*   Updated: 2024/07/03 15:04:15 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#define BOARD_SIZE 10

int	ft_issafe(int *state, int c_r)
{
	int	p_r;
	int	p_c;
	int	c_c;

	p_r = c_r - 1;
	c_c = state[c_r];
	while (p_r >= 0)
	{
		p_c = state[p_r];
		if (p_c == c_c)
			return (0);
		if (p_r - c_r == c_c - p_c || c_r - p_r == c_c - p_c)
			return (0);
		p_r--;
	}
	return (1);
}

void	ft_print_solution(int *solution)
{
	int	i;

	i = 0;
	while (i < BOARD_SIZE)
	{
		write(1, &"0123456789"[solution[i]], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	_ft_ten_queens_puzzle(int *state, int queen_index)
{
	int	nb;

	nb = 0;
	if (queen_index >= BOARD_SIZE)
	{
		ft_print_solution(state);
		return (1);
	}
	while (!ft_issafe(state, queen_index) && state[queen_index] < BOARD_SIZE)
		state[queen_index]++;
	if (state[queen_index] == BOARD_SIZE)
	{
		state[queen_index] = 0;
		return (0);
	}
	nb += _ft_ten_queens_puzzle(state, queen_index + 1);
	state[queen_index]++;
	nb += _ft_ten_queens_puzzle(state, queen_index);
	return (nb);
}

int	ft_ten_queens_puzzle(void)
{
	int	solution[10];
	int	i;

	i = 0;
	while (i < BOARD_SIZE)
	{
		solution[i] = 0;
		i++;
	}
	return (_ft_ten_queens_puzzle(solution, 0));
}
