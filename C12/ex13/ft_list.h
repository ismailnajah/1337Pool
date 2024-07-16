/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:19:34 by inajah            #+#    #+#             */
/*   Updated: 2024/07/16 14:57:30 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

struct s_list
{
	void			*data;
	struct s_list	*next;
};

typedef struct s_list	t_list;
t_list	*ft_create_elem(void *data);
#endif
