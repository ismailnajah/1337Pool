/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:33:32 by inajah            #+#    #+#             */
/*   Updated: 2024/07/13 18:17:28 by inajah           ###   ########.fr       */
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

// TODO: fix the issue with binary files.
// the problem is that i am printing with while(str[i])
// which causes issue when there is 0 in the data
// removing it will fix it but it will cause an issue
// of the stream.
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_error(char *str);
void	debug(char *str);
void	ft_print_int_as_hex(int n, int mode);

char	*ft_bytecpy(char *dest, char *src, int size);
int		ft_bytecmp(char *s1, char *s2, int size);

int		ft_hexdump_read(int fd, t_stream *s, int mode);
int		ft_hexdump_file(char **av, t_stream *s, int mode);
int		ft_hexdump_files(int ac, char **av, t_stream *s, int mode);
int		ft_hexdump_error(char *prog_name, char *path, int err);

#endif
