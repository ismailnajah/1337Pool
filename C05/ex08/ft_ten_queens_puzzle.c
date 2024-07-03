/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:10:00 by inajah            #+#    #+#             */
/*   Updated: 2024/07/03 11:19:56 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define BOARD_SIZE 10

int	ft_is_valid_position(int *state, int c_r, int c_c)
{
	int	p_r;
	int	p_c;

	p_r = c_r - 1;
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

void ft_print_solution(int *solution)
{
	int	i;

	i = 0;
	while(i < BOARD_SIZE)
	{
		write(1, &"0123456789"[solution[i]], 1);
		i++;
	}
}

int _ft_ten_queens_puzzle(int *state, int queen_index)
{
	if(state[0] == BOARD_SIZE)
		return (0);
	if (state[queen_index] == BOARD_SIZE )
	{
		state[queen_index] = 0;
		state[queen_index - 1 ]++;
		return _ft_ten_queens_puzzle(state, queen_index - 1);
	}
	if (ft_is_valid_position(state, queen_index, state[queen_index]))
	{
		if (queen_index == BOARD_SIZE - 1)
		{
			ft_print_solution(state);
			write(1, "\n", 1);
			return (1);
		}
		else
			return _ft_ten_queens_puzzle(state, queen_index + 1);
	}
	state[queen_index]++;
	return _ft_ten_queens_puzzle(state, queen_index);
}

int	ft_ten_queens_puzzle(void)
{
	int	solution[10] = {0};
	int nb_solutions;
	int	i;

	nb_solutions = 0;
	i = 0;
	while (i < BOARD_SIZE)
	{
		solution[0] = i;
		nb_solutions +=	_ft_ten_queens_puzzle(solution, 1);
		i++;
	}
	return nb_solutions;
}
