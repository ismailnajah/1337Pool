#include "../C08/ex01/ft_boolean.h"
#include "../C08/ex02/ft_abs.h"
#include <stdio.h>


void ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

t_bool	ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

int main(int ac, char **av)
{
	(void) av;
	if (ft_is_even(ac - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);

	int value = 5;
	printf("%d\n", ABS(value - 10 + 1));
	return (SUCCESS);
}
