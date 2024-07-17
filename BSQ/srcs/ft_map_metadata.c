/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_metadata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:09:12 by inajah            #+#    #+#             */
/*   Updated: 2024/07/17 20:46:03 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

t_map_metadata	get_metadata(char buffer[])
{
	int				i;
	t_map_metadata	metadata;

	metadata.size = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i--;
	if (i < 3)
		return (metadata);
	metadata.full = buffer[i--];
	metadata.obstacle = buffer[i--];
	metadata.empty = buffer[i];
	buffer[i] = '\0';
	metadata.size = ft_atoi(buffer);
	if (!ft_is_printable(metadata.full) || !ft_is_printable(metadata.obstacle)
		|| !ft_is_printable(metadata.empty)
		|| metadata.full == metadata.obstacle || metadata.full == metadata.empty
		|| metadata.obstacle == metadata.empty)
	{
		metadata.size = 0;
	}
	return (metadata);
}

t_map_metadata	get_metadata_from_file(char *path)
{
	char			buffer[32];
	t_map_metadata	metadata;
	int				fd;

	fd = open_file(path);
	read(fd, buffer, sizeof(buffer));
	buffer[31] = '\0';
	metadata = get_metadata(buffer);
	close(fd);
	return (metadata);
}
