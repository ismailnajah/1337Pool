/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:07:46 by inajah            #+#    #+#             */
/*   Updated: 2024/07/14 10:41:28 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

int	ft_get_op_index(char *str, char *op)
{
	int	len;
	int	i;

	len = 0;
	while (op[len])
		len++;
	if (len != 1)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == op[0])
			return (i);
		i++;
	}
	return (-1);
}

int	main(int ac, char **av)
{
	int	r;
	int	op_index;
	int	(*ops[5])(int, int);

	r = 1;
	ops[0] = &add;
	ops[1] = &sub;
	ops[2] = &mul;
	ops[3] = &div;
	ops[4] = &mod;
	if (ac != 4)
		return (1);
	op_index = ft_get_op_index("+-*/%", av[2]);
	if (op_index < 0)
		ft_putnbr(0);
	else
		r = (*ops[op_index])(ft_atoi(av[1]), ft_atoi(av[3]));
	ft_putstr("\n");
	return (r);
}
