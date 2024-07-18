/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:56:09 by inajah            #+#    #+#             */
/*   Updated: 2024/07/18 09:04:38 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void	print_map(t_map *map, t_point pos, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->metadata.size)
	{
		j = 0;
		while (j < map->metadata.size)
		{
			if ((i <= pos.y && (i > pos.y - size))
				&& (j <= pos.x && (j > pos.x - size)))
				write(1, &map->metadata.full, 1);
			else
				write(1, map->data[i] + j, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

t_map	*ft_free_and_close(t_map *map, int row, int fd)
{
	int	i;

	if (fd > 0)
		close(fd);
	i = 0;
	while (i < row)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
	map->data = NULL;
	return (map);
}

int	insert_character(t_map *map, t_point *pos, char c)
{
	if (c == '\n')
	{
		if (pos->x < map->metadata.size)
			return (0);
		return (1);
	}
	if (c != map->metadata.empty && c != map->metadata.obstacle)
		return (0);
	if (pos->x == map->metadata.size)
	{
		pos->y++;
		if (pos->y >= map->metadata.size)
			return (0);
		pos->x = 0;
	}
	if (pos->x == 0)
		map->data[pos->y] = malloc(sizeof(char) * map->metadata.size);
	map->data[pos->y][pos->x] = c;
	pos->x++;
	return (1);
}

int	allocate_and_fill_map(t_map *map, int fd)
{
	char	char_buffer;
	t_point	pos;

	while (fd > 0 && read(fd, &char_buffer, 1) && char_buffer != '\n')
		;
	map->data = malloc(sizeof(char *) * map->metadata.size);
	pos.x = 0;
	pos.y = 0;
	while (read(fd, &char_buffer, 1))
	{
		if (!insert_character(map, &pos, char_buffer))
		{
			ft_free_and_close(map, pos.y, fd);
			return (0);
		}
	}
	return (1);
}

t_map	read_and_validate_map(char *path)
{
	t_map	map;
	int		fd;

	map.metadata = get_metadata_from_file(path);
	map.data = NULL;
	if (map.metadata.size <= 0)
		return (map);
	fd = open_file(path);
	if (fd < 0)
		return (map);
	if (allocate_and_fill_map(&map, fd))
		close(fd);
	return (map);
}
