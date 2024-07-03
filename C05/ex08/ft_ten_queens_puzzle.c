/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:10:00 by inajah            #+#    #+#             */
/*   Updated: 2024/07/03 09:47:31 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (p_r - c_r == c_c - p_c || c_r - p_r == c_c - p_c )
			return (0);
		p_r--;
	}
	return (1);
}

int ft_ten_qeens_puzzle(void)
{
	//int	solution[10];
	//int	position;
	
	//ft_is_valid_position(solution, current_queen, position)


	return (0);
}
