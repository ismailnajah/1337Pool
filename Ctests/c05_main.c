#include <stdio.h>

#include "../C05/ex00/ft_iterative_factorial.c"
#include "../C05/ex01/ft_recursive_factorial.c"
#include "../C05/ex02/ft_iterative_power.c"
#include "../C05/ex03/ft_recursive_power.c"
#include "../C05/ex04/ft_fibonacci.c"
#include "../C05/ex05/ft_sqrt.c"

int main()
{
	int nb = 1;
	int power = 100;
	printf("iter_fact = %d, rec_fact = %d\n",ft_iterative_factorial(nb) ,ft_recursive_factorial(nb));
	printf("iter_power = %d, rec_power = %d\n",ft_iterative_power(nb, power) ,ft_recursive_power(nb, power));
	
	int feb = 15;
	printf("ft_fibonacci(%d) = %d\n", feb,ft_fibonacci(feb));

	int sqrt = 144;
	printf("ft_sqrt(%d) = %d\n", sqrt, ft_sqrt(sqrt));

}
