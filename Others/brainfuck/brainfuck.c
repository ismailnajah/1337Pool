/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:28:35 by inajah            #+#    #+#             */
/*   Updated: 2024/07/16 20:39:48 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	go_to_matching(char *inst, int cursor)
{
	int balance = 0;
	int i = cursor + 1;
	if (inst[cursor] == '[')
	{
		while (inst[i] != ']' || balance != 0 )
		{
			if (inst[i] == '[')
				balance++;
			else if (inst[i] == ']')
				balance--;
			i++;
		}
	}
	else if (inst[cursor] == ']')
	{
		i = cursor - 1;
		while (inst[i] != '[' || balance != 0 )
		{
			if (inst[i] == ']')
				balance++;
			else if (inst[i] == '[')
				balance--;
			i--;
		}
	}
	return i;
}

int	main(int ac, char **av)
{
	char op;
	unsigned char bytes[2048] = {0};
	int ip = 0;
	int cursor = 0;

	if (ac == 2)
	{	
		while(av[1][cursor])
		{
			op = av[1][cursor];
			if (op == '>')
				ip++;
			else if (op == '<')
				ip--;
			else if (op == '+')
				bytes[ip]++;
			else if (op == '-')
				bytes[ip]--;
			else if (op == '.')
				write(1, bytes + ip, 1);
			else if (op == '[')
			{
				if (bytes[ip] == 0)
					cursor = go_to_matching(av[1], cursor);
			}
			else if (op == ']')
			{
				cursor = go_to_matching(av[1], cursor);
				cursor--;
			}
			cursor++;
		}
	}
	else
		write(1, "\n", 1);
	return 0;
}
