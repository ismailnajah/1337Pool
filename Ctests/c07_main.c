#include <stdio.h>
#include <stdlib.h>
#include "../C07/ex04/ft_convert_base.c"


int main()
{
	char *str = "    ++-+---++-2147483648";
	char *buff = ft_convert_base(str, "0123456789", "0123456789abcdef");
	printf("ft_conver_base : \"%s\"\n", buff);
	return 0;
}
