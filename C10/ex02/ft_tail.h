/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:51:39 by inajah            #+#    #+#             */
/*   Updated: 2024/07/10 16:07:42 by inajah           ###   ########.fr       */
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

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_error(char *str);

int		ft_get_offset(int *offset, char *param);
int		ft_tail_error(char **av, int error);
void	ft_tail_read(void);


#endif
