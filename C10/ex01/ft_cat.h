/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:40:32 by inajah            #+#    #+#             */
/*   Updated: 2024/07/10 10:35:02 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_error(char *str);
int		ft_cat_read_input(void);
int		ft_cat_display_files(int ac, char **av);
int		ft_cat_display_file(char *path);
void	ft_display_file(int fd);
int		ft_cat_error(char *prog_name, char *paht, int err);

#endif
