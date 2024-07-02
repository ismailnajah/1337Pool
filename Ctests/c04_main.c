#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "../C04/ex00/ft_strlen.c"
#include "../C04/ex01/ft_putstr.c"
#include "../C04/ex02/ft_putnbr.c"
#include "ft_atoi_test.c"
#include "ft_putnbr_base_test.c"

#define NL write(1, "\n", 1)

int main()
{
	char *str = "testing ft_strlen\n";
	printf("ft_strlen = %d, strlen = %ld\n", ft_strlen(str), strlen(str));
	ft_putstr(str);
	ft_putnbr(INT_MIN);
	NL;
	ft_putnbr(INT_MAX);
	NL;
	ft_putnbr(-1337);
	NL;
	ft_putnbr(4242);
	NL;
	ft_putnbr(0);

	NL;
	ft_atoi_run_tests();

	//testing ex04
	ft_putstr("\n Testing ft_putnbr_base\n");
	ft_putnbr_base_run_tests();
	return 0;
}
