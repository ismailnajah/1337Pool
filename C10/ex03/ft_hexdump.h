/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:33:32 by inajah            #+#    #+#             */
/*   Updated: 2024/07/12 09:58:12 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define LINE_SIZE 16

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_error(char *str);

int		ft_hexdump_read(int mode);

#endif
