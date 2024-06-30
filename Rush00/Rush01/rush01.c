/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:24:41 by aaferyad          #+#    #+#             */
/*   Updated: 2024/06/29 20:26:06 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	printer(char *symbol, int width)
{
	int	i;	

	i = 0;
	while (i < width)
	{
		if (!i)
			ft_putchar(symbol[i]);
		else if (i + 1 == width)
			ft_putchar(symbol[2]);
		else
			ft_putchar(symbol[1]);
		i++;
	}
}

void	rush(int width, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (!i)
			printer("/*\\", width);
		else if (i + 1 == height)
			printer("\\*/", width);
		else
			printer("* *", width);
		if (i < height)
			ft_putchar('\n');
		i++;
	}
}
