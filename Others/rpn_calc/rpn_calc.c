/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:04:28 by inajah            #+#    #+#             */
/*   Updated: 2024/07/17 09:57:36 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_add(int a, int b);
int ft_sub(int a, int b);
int ft_mul(int a, int b);
int ft_div(int a, int b);
int ft_mod(int a, int b);

int	error(int n)
{
	printf("[%d]Error\n", n);
	return 1;
}

int	get_op_index(char c, char *ops)
{
	int i = 0;

	while (ops[i])
	{
		if (c == ops[i])
			return i;
		i++;
	}
	return -1;
}

int get_next_operand(char *str, int *cursor, int *operand)
{
	char nbr[20];
	int i = 0;

	while (str[*cursor] && str[*cursor] != ' ')
	{
		if (!('0' <= str[*cursor] && str[*cursor] <= '9'))
			return 0;
		nbr[i] = str[*cursor];
		i++;
		(*cursor)++;
	}
	nbr[i] = '\0';
	*operand = atoi(nbr);
	return 1;
}

void print_stack(int *stack, int size)
{
	printf("[");
	for(int i=0; i<size; i++)
		printf("%d ", stack[i]);
	printf("]\n");
}

int	main(int ac, char **av)
{	
	if(ac != 2)
		return error(1);

	int (*op[5])(int,int);
	int stack[2048];
	int stack_index = 0;
	int cursor = 0;

	op[0] = &ft_add;
	op[1] = &ft_sub;
	op[2] = &ft_mul;
	op[3] = &ft_div;
	op[4] = &ft_mod;

	while (av[1][cursor])
	{
		if (av[1][cursor] == ' ')
		{
			cursor++;
			continue;
		}
		int op_index = get_op_index(av[1][cursor], "+-*/%");
		if (op_index < 0)
		{
			if (!get_next_operand(av[1], &cursor, stack + stack_index))
				return error(2);
			stack_index++;
		}
		else
		{
			if (stack_index < 2)
				return error(3);
			else
			{
				printf("current op '%c' : ", av[1][cursor]);
				print_stack(stack, stack_index);
				stack[stack_index - 2] = (*op[op_index])(stack[stack_index - 2], stack[stack_index - 1]);
				stack_index--;
				cursor++;
			}
		}
	}
	if (stack_index > 1)
		return error(4);
	printf("%d\n", stack[stack_index - 1]);
	return 0;
}

int ft_add(int a, int b)
{
	return a + b;
}

int ft_sub(int a, int b)
{
	return a - b;
}

int ft_mul(int a, int b)
{
	return a * b;
}

int ft_div(int a, int b)
{
	return a / b;
}

int ft_mod(int a, int b)
{
	return a % b;
}

