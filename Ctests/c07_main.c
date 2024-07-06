#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../C07/ex04/ft_convert_base.c"
#include "../C07/ex05/ft_split.c"

int main()
{
	char *str = "    ++-+---++-dcrcmcmooododmrrrmorcmcrmomo";
	char *buff = ft_convert_base(str, "mrdoc", "0123456789");
	printf("ft_conver_base : \"%s\"\n\n", buff);


	char *str_s = "  1    ";
	char *charset = "";
	printf("--- testing ft_split ----\n");
	char **words_list = ft_split(str_s, charset);
	int i = 0;
	while(words_list[i])
	{
		printf("strlen(\"%s\") = %d\n", words_list[i], (int) strlen(words_list[i]));
		i++;
	}	
	return 0;
}
