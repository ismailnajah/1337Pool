#include <stdio.h>

#include "../C05/ex00/ft_iterative_factorial.c"
#include "../C05/ex01/ft_recursive_factorial.c"
#include "../C05/ex02/ft_iterative_power.c"
#include "../C05/ex03/ft_recursive_power.c"
#include "../C05/ex04/ft_fibonacci.c"
#include "../C05/ex05/ft_sqrt.c"
#include "../C05/ex06/ft_is_prime.c"
#include "../C05/ex07/ft_find_next_prime.c"
#include "../C05/ex08/ft_ten_queens_puzzle.c"

int main()
{
#if 0
	int nb = 1;
	int power = 100;
	printf("iter_fact = %d, rec_fact = %d\n",ft_iterative_factorial(nb) ,ft_recursive_factorial(nb));
	printf("iter_power = %d, rec_power = %d\n",ft_iterative_power(nb, power) ,ft_recursive_power(nb, power));
	
	int feb = 15;
	printf("ft_fibonacci(%d) = %d\n", feb,ft_fibonacci(feb));

	int sqrt = 144;
	printf("ft_sqrt(%d) = %d\n\n", sqrt, ft_sqrt(sqrt));

	int range = 1000;
	for (int p = 0; p < range; p++)
		if (ft_is_prime(p))
			printf("%d is prime\n", p);
	printf("\nnext prime greater or equale to %d is %d\n", range, ft_find_next_prime(range));
#endif

	int state[] = {0,2,4,1,0};
	int size = sizeof(state) / sizeof(int);
	int c_q = 4;
	int i;
	for(i=0; i< size ;i++)
	{
		if (ft_is_valid_position(state, c_q, i)){
			printf("Valid column found!! : %d\n", i);
			break;
		}
	}
	if (i==size)
		printf("No Valide column was found\n");

}
