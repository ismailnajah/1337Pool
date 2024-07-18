/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:52:09 by inajah            #+#    #+#             */
/*   Updated: 2024/07/18 11:26:31 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int	read_from_input(t_map *map, t_point solution_pos)
{
	char	buffer[32];
	int		i;
	int		size;

	i = 0;
	while (read(0, buffer + i, 1) && buffer[i] != '\n' && i < 32)
		i++;
	if (i > 32)
		return (print_error(1));
	buffer[i] = '\0';
	map->metadata = get_metadata(buffer);
	if (map->metadata.size <= 0)
		return (print_error(1));
	if (!allocate_and_fill_map(map, 0))
		return (print_error(1));
	size = find_biggest_square(map, &solution_pos);
	if (size > 0)
		print_map(map, solution_pos, size);
	ft_free_and_close(map, map->metadata.size, -1);
	return (0);
}

void	ft_init_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
}

int	main(int argc, char *argv[])
{
	int		i;
	int		size;
	t_map	map;
	t_point	solution_pos;

	ft_init_point(&solution_pos);
	if (argc == 1)
		return (read_from_input(&map, solution_pos));
	i = 1;
	while (i < argc)
	{
		map = read_and_validate_map(argv[i]);
		if (!map.data)
		{
			print_error(1);
			i++;
			continue ;
		}
		size = find_biggest_square(&map, &solution_pos);
		if (size > 0)
			print_map(&map, solution_pos, size);
		ft_free_and_close(&map, map.metadata.size, -1);
		i++;
	}
	return (0);
}
