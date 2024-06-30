/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:35:38 by soabboub          #+#    #+#             */
/*   Updated: 2024/06/30 16:46:02 by soabboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

int	ft_print(int c, int r, int columns, int rows)
{
	if (c == 0)
	{
		if (r == 0)
			ft_putchar('/');
		else if (r == rows - 1)
			ft_putchar('\\');
		else
			ft_putchar('*');
		return (1);
	}
	else if (c == columns - 1)
	{
		if (r == 0)
			ft_putchar('\\');
		else if (r == rows - 1)
			ft_putchar('/');
		else
			ft_putchar('*');
		return (1);
	}
	return (0);
}

void	ft_rush(int columns, int rows)
{
	int	col;
	int	row;

	row = 0;
	while (row < rows)
	{
		col = 0;
		while (col < columns)
		{
			if (!ft_print(col, row, columns, rows))
			{
				if (row == 0 || row == rows -1)
					ft_putchar('*');
				else
					ft_putchar(' ');
			}
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

int	rush(int columns, int rows)
{
	if (columns <= 0 || rows <= 0)
		return (0);
	ft_rush(columns, rows);
	return (1);
}
