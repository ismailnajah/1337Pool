#include <stdio.h>
#include <stdlib.h>
#include "../C07/ex04/ft_convert_base.c"


int main()
{
	char *str = "    ++-+--++-+101010";
	char *buff = ft_convert_base(str, "01", "0123456789");
	printf("%s\n", buff);
	return 0;
}
