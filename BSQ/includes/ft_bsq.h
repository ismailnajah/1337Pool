/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:18:00 by inajah            #+#    #+#             */
/*   Updated: 2024/07/18 11:37:44 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map_metadata
{
	int				size;
	char			empty;
	char			obstacle;
	char			full;
}					t_map_metadata;

typedef struct s_map
{
	char			**data;
	t_map_metadata	metadata;
}					t_map;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

int				min(int a, int b);
int				ft_atoi(char *str);
int				print_error(int return_code);
int				open_file(char *path);
int				ft_is_printable(char c);

void			free_dp_matrix(int **dp, int size);
int				**allocate_dp_matrix(int size);
void			initiate_dp_matrix(int **dp, int size);
int				fill_dp_matrix(int **dp, t_map *map, t_point *max_pos);
int				find_biggest_square(t_map *map, t_point *max_pos);

t_map_metadata	get_metadata(char buffer[]);
t_map_metadata	get_metadata_from_file(char *path);

t_map			read_and_validate_map(char *path);
t_map			*ft_free_and_close(t_map *map, int row, int fd);
int				allocate_and_fill_map(t_map *map, int fd);
int				insert_character(t_map *map, t_point *p, char c);
void			print_map(t_map *map, t_point pos, int size);

#endif
