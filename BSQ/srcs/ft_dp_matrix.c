/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dp_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:44:39 by inajah            #+#    #+#             */
/*   Updated: 2024/07/18 10:38:03 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void	initiate_dp_matrix(int **dp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dp[i][0] = 0;
		dp[0][i] = 0;
		i++;
	}
}

void	free_dp_matrix(int **dp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

int	**allocate_dp_matrix(int size)
{
	int	**dp;
	int	i;

	dp = malloc(sizeof(int *) * (size));
	if (!dp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dp[i] = malloc(sizeof(int) * (size));
		if (!dp[i])
		{
			free_dp_matrix(dp, i);
			return (NULL);
		}
		i++;
	}
	initiate_dp_matrix(dp, size);
	return (dp);
}
