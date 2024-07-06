#include <stdio.h>
#include <stdlib.h>
#include "../C07/ex04/ft_convert_base.c"
#include "../C07/ex05/ft_split.c"

int main()
{
	char *str = "    ++-+---++-dcrcmcmooododmrrrmorcmcrmomo";
	char *buff = ft_convert_base(str, "mrdoc", "0123456789");
	printf("ft_conver_base : \"%s\"\n\n", buff);


	char *str_s = "     word1 word2 word3 word4";
	char *charset = " ";
	printf("--- testing ft_split ----\n");
	int count = ft_words_count(str_s, charset);
	printf("\"%s\" has %d words\n", str_s, count);

	char **words_list = ft_split(str_s, charset);
	for(int i=0; i < count; i++)
		printf("%s\n", words_list[i]);	
	return 0;
}
