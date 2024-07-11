/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:51:39 by inajah            #+#    #+#             */
/*   Updated: 2024/07/11 10:29:27 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <string.h>
# include <libgen.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define I_OFFSET -1

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_error(char *str);
int		ft_strlen(char *str);
int		ft_read_file(char *path, char *buffer, int *file_len);

int		ft_get_nbytes(char **av, int *nbytes, int p_shift);
int		ft_tail_error(char *prog_name, char *path, int error);
int		ft_tail_illegal(char **av);
int		ft_tail_read(int nbytes);
int		ft_tail_files(int ac, char **av, int nbytes, int p_shift);

typedef struct s_file
{
	char	*path;
	int		len;
}	t_file;

#endif
