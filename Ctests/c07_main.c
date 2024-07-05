#include <stdio.h>
#include <stdlib.h>
#include "../C07/ex04/ft_convert_base.c"
#include "../C07/ex05/ft_split.c"

int main()
{
	char *str = "    ++-+---++-dcrcmcmooododmrrrmorcmcrmomo";
	char *buff = ft_convert_base(str, "mrdoc", "0123456789");
	printf("ft_conver_base : \"%s\"\n\n", buff);


	char *str_s = "abc ";
	char *charset = "abc";
	printf("--- testing ft_split ----\n");
	ft_split(str_s, charset);
	return 0;
}
