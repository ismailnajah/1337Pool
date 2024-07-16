/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:45:40 by inajah            #+#    #+#             */
/*   Updated: 2024/07/16 10:55:03 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

struct s_btree
{
	void			*item;
	struct s_btree	*left;
	struct s_btree	*right;
};
typedef struct s_btree	t_btree;
#endif
