#include <stdio.h>
#include "../C00/ex00/ft_putchar.c"
#include "../C00/ex01/ft_print_alphabet.c"
#include "../C00/ex02/ft_print_reverse_alphabet.c"
#include "../C00/ex03/ft_print_numbers.c"
#include "../C00/ex04/ft_is_negative.c"
#include "../C00/ex05/ft_print_comb.c"
#include "../C00/ex06/ft_print_comb2.c"
#include "../C00/ex07/ft_putnbr.c"
#include "../C00/ex08/ft_print_combn.c"

int	main(void)
{
	//testing ex00
	char c = 'A';
	ft_putchar(c);

	//testing ex01
	ft_putchar('\n');
	ft_print_alphabet();

	//testing ex02
	ft_putchar('\n');
	ft_print_reverse_alphabet();

	//testing ex03
	ft_putchar('\n');
	ft_print_numbers();

	//testing ex04
	ft_putchar('\n');
	ft_is_negative(-12);
	ft_is_negative(0);
	ft_is_negative(12);

	//testing ex05
	ft_putchar('\n');
	ft_print_comb();

	//testing ex06
	ft_putchar('\n');
	ft_print_comb2();
	
	//testing ex07
	int max_int = 2147483647;
	int min_int = -2147483648;
	int pos_nb = 1337;
	int neg_nb = -42;
	ft_putchar('\n');
	ft_putnbr(min_int);
	ft_putchar(' ');
	ft_putnbr(max_int);
	ft_putchar(' ');
	ft_putnbr(pos_nb);
	ft_putchar(' ');
	ft_putnbr(neg_nb);
	printf("\n%d %d %d %d", min_int, max_int, pos_nb, neg_nb);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(9);
	return (0);
}
