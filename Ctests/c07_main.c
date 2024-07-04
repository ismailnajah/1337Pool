#include <stdio.h>
#include <stdlib.h>
#include "../C07/ex04/ft_convert_base.c"


int main()
{
	char *str = "    +++---+-+42asdfa";
	ft_convert_base(str, "0123456789", "01");
	return 0;
}
