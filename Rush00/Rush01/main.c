/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:36:52 by aaferyad          #+#    #+#             */
/*   Updated: 2024/06/30 09:03:09 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int width, int height);
void	ft_putchar(char c);

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n * sign);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_usage(char *program_name)
{
	ft_putstr("Usage: ");
	ft_putstr(program_name);
	ft_putstr(" width height\n");
}

int	ft_valid_arguments(int width, int height, char *program_name)
{
	if (width <= 0 || height <= 0)
	{
		ft_putstr(program_name);
		ft_putstr(":");
		if (width <= 0)
			ft_putstr("\tinvalid width  --- width  must be greater than 0 ---\n");
		if (height <= 0)
			ft_putstr("\tinvalid height --- height must be greater than 0 ---\n");
		ft_usage(program_name);
		return 0;
	}
	return 1;
}

int	main(int argc, char *argv[])
{
	int	width;
	int	height;

	if (argc != 3)
	{
		ft_putstr(argv[0]);
		if (argc < 3)
			ft_putstr(": too few arguments\n");
		else
			ft_putstr(": too many arguments\n");
		ft_usage(argv[0]);
		return 1;
	}
	width = ft_atoi(argv[0]);
	height = ft_atoi(argv[1]);
	if (!ft_valid_arguments(width, height, argv[0]))
		return 1;
	rush(width, height);
	return (0);
}
