/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:33:32 by inajah            #+#    #+#             */
/*   Updated: 2024/07/13 20:21:16 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

# define FAILURE 1
# define SUCCESS 0

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define LINE_SIZE 16

typedef struct s_stream
{
	int		index;
	int		row;
	int		cursor;
	char	buffer[32];
}	t_stream;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_error(char *str);
char	*ft_bytecpy(char *dest, char *src, int size);
int		ft_bytecmp(char *s1, char *s2, int size);

void	ft_print_int_as_hex(int n, int mode);
void	ft_print_str_as_hex(char *str, int size, int padding);
void	ft_print_non_printable(char *str, int size);
void	ft_print_line(char *buffer, int row, int mode, int last);
void	ft_print_spaces(int i, int padding);

int		ft_hexdump_read(int fd, t_stream *s, int mode);
int		ft_hexdump_file(char **av, t_stream *s, int mode);
int		ft_hexdump_files(int ac, char **av, t_stream *s, int mode);
int		ft_hexdump_error(char *prog_name, char *path, int err);

#endif
